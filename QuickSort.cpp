#include "QuickSort.h"

void QuickSort::Print() {
	std::cout << "Быстрая сортировка:" << std::endl;
}

void QuickSort::PrintCounters()
{
	std::cout << "Quick     ";
	ISort::PrintCounters();
}

void QuickSort::AbsSort(std::vector<int>& arr, int size)
{
	AbsQuicksort(arr, 0, size-1);
}

void QuickSort::AbsQuicksort(std::vector<int>& arr, int start, int end)
{
	if (start < end) {
		int p = AbsPartition(arr, start, end);
		AbsQuicksort(arr, start, p - 1);
		AbsQuicksort(arr, p + 1, end);
	}
}

int QuickSort::AbsPartition(std::vector<int>& arr, int start, int end)
{
	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		comparisonCounter++;
		if (abs(arr[i])  < abs(arr[pivot])) {
			swapCounter++;
			std::swap(arr[i], arr[j]);
			++j;
		}
	}
	std::swap(arr[j], arr[pivot]);
	if(swapCounter > 0)
		swapCounter++;
	return j;

}

//----------------------------
void QuickSort::Sort(std::vector<int>& arr, int size)
{
	Quicksort(arr, 0, size - 1);
}

void QuickSort::Quicksort(std::vector<int>& arr, int start, int end)
{
	if (start < end) {
		int p = Partition(arr, start, end);
		Quicksort(arr, start, p - 1);
		Quicksort(arr, p + 1, end);
	}
}

int QuickSort::Partition(std::vector<int>& arr, int start, int end)
{
	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		comparisonCounter++;
		if (arr[i] < arr[pivot]) {
			swapCounter++;
			std::swap(arr[i], arr[j]);
			++j;
		}
	}
	std::swap(arr[j], arr[pivot]);
	if (swapCounter > 0)
		swapCounter++;
	return j;

}
