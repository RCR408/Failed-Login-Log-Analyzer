#pragma once
#include "bitacora.h"

class SortingA
{
private:
	static void swap(int*, int*,std::string*,std::string*);
	static int partition(std::vector<int>&, std::vector<std::string>&,int, int);
public:
	static void quickSort(std::vector<int>&, std::vector<std::string>&,int, int);
	static std::vector<int> busquedaBin(const std::vector<int>&, int, int,int,int,int);
};

