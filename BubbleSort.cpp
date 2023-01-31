#include "BubbleSort.h"


void BubbleSort::Print() 
{
	std::cout << "\nБаблсорт:" << std::endl;
}

void BubbleSort::PrintCounters()
{	
	std::cout << "Таблица результатов сортировок:" << "\n" << std::endl;
	std::cout << "Cортировка|Сравнения|Свапы|" << std::endl;
	std::cout << "Bubble    ";
	ISort::PrintCounters();
}

void BubbleSort::AbsSort(std::vector<int>& arr, int size)
{
	
	bool end = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comparisonCounter++;
			if (abs(arr[j]) > abs(arr[j + 1]))
			{
				swapCounter++;
				std::swap(arr[j], arr[j + 1]);
				end = false;
			}

		}
		if (end)return;
	}
}

void BubbleSort::Sort(std::vector<int>& arr, int size)
{
	bool end = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comparisonCounter++;
			if (arr[j] > arr[j + 1])
			{
				swapCounter++;
				std::swap(arr[j], arr[j + 1]);
				end = false;
			}

		}
		if (end)return;
	}
}
