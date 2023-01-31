#pragma once
#include "ISort.h"

class ShellSort : public ISort
{
public:

	void Print() override;

	void PrintCounters() override;

	void Sort(std::vector<int>& arr, int size) override;

	void AbsSort(std::vector<int>& arr, int size) override;
};

