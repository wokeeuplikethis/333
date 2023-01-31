#pragma once
#include "ISort.h"
#include <iostream>

class QuickSort : public ISort
{
public:

	void Print() override;

	void PrintCounters() override;

	void AbsSort(std::vector<int>& arr, int size) override;

	void AbsQuicksort(std::vector<int>& arr, int start, int end);

	int AbsPartition(std::vector<int>& arr, int start, int end);

	void Sort(std::vector<int>& arr, int size) override;

	void Quicksort(std::vector<int>& arr, int start, int end);

	int Partition(std::vector<int>& arr, int start, int end);
};

