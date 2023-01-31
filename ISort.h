#pragma once
#include <string>
#include <iostream>
#include "Names.h"
#include <vector>

class ISort
{
protected:
	int comparisonCounter = 0;
	int swapCounter = 0;

public:
	int GetComprasionCounter();

	int GetSwapCountrt();
		
	virtual void Print();

	virtual void PrintCounters();

	virtual void AbsSort(std::vector<int>& arr, int size) = 0;

	virtual void Sort(std::vector<int>& arr, int size) = 0;


	virtual ~ISort() = default;

};

