#pragma once
#include "ISort.h"

class BubbleSort : public ISort
{
public:


	void PrintCounters() override;

	void AbsSort(std::vector<int>& arr, int size) override;

	void Sort(std::vector<int>& arr, int size) override;

	void Print() override;

};

