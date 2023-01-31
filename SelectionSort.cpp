#include "SelectionSort.h"

void SelectionSort::Print() {
	std::cout << "Сортировка выборкой:" << std::endl;
}

void SelectionSort::PrintCounters()
{
	std::cout << "Selection ";
	ISort::PrintCounters();
}

void SelectionSort::AbsSort(std::vector<int>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++)
		{
			comparisonCounter++;
			if (abs(arr[tmpid]) >  abs(arr[j]))
			{
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i)
		{
			swapCounter++;
			std::swap(arr[i], arr[tmpid]);
		}
	}
}

void SelectionSort::Sort(std::vector<int>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++)
		{
			comparisonCounter++;
			if (arr[tmpid] > arr[j])
			{
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i)
		{
			swapCounter++;
			std::swap(arr[i], arr[tmpid]);
		}
	}
}
