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

std::vector<int> SortingA::busquedaBin(const std::vector<int>& lista, int n,int mesI,int diaI, int mesF, int diaF)
{
    int claveI = (mesI * 100000000) + (diaI * 1000000);
    int claveF = (mesF * 100000000) + (diaF * 1000000);

    int bajo, alto, med;
    int centralI = 0;
    int centralF = n - 1;

    bajo = 0;
    alto = n - 1;
    while (bajo <= alto) {
        med = bajo + (alto - bajo) / 2;
        if (lista[med] >= claveI) {
            centralI = med;
            alto = med - 1;
        }
        else {
            bajo = med + 1;
        }
    }

    bajo = 0;
    alto = n - 1;
    while (bajo <= alto) {
        med = bajo + (alto - bajo) / 2;
        if (lista[med] <= claveF) {
            centralF = med;
            bajo = med + 1; 
        }
        else {
            alto = med - 1;
        }
    }

    std::vector<int> result;
    result.push_back(centralI);
    result.push_back(centralF);
    return result;
}