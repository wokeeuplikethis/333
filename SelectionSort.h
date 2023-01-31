#pragma once
#include "ISort.h"

class SelectionSort : public ISort
{
public:
	
	void Print() override;

	void PrintCounters() override;

	void AbsSort(std::vector<int>& arr, int size) override;

	void Sort(std::vector<int>& arr, int size) override;


};

