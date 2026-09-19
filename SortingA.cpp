#include "SortingA.h"

void SortingA::swap(int* val1, int* val2, std::string* val3 , std::string* val4)
{
	int temp = *val1;
	std::string tempS = *val3;
	*val1 = *val2;
	*val3 = *val4;
	*val2 = temp;
	*val4 = tempS;
}

void SortingA::quickSort(std::vector<int>& arr, std::vector<std::string>& arrS,int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, arrS,low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, arrS,low, pi - 1);
		quickSort(arr, arrS,pi + 1, high);
	}
}

int SortingA::partition(std::vector<int>& arr, std::vector<std::string>& arrS, int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j],&arrS[i],&arrS[j]);
		}
	}
	swap(&arr[i + 1], &arr[high],&arrS[i + 1], &arrS[high]);
	return (i + 1);
}