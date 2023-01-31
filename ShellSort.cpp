#include "ShellSort.h"

void ShellSort::Print() {
    std::cout << "Сортировка Шелла:" << std::endl;
}

void ShellSort::PrintCounters()
{   

    std::cout << "Shell     ";
    ISort::PrintCounters();
}

void ShellSort::AbsSort(std::vector<int>& arr, int size)
{
    for (int gap = size/2; gap > 0; gap/=2)
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            comparisonCounter++;
            for (j = i; j >= gap && abs(arr[j - gap]) > abs(temp); j -= gap)
            {
                swapCounter++;
                arr[j] = arr[j - gap];
                if (j == gap)
                    comparisonCounter--;
            }

            arr[j] = temp;
        } 
}

void ShellSort::Sort(std::vector<int>& arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            comparisonCounter++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                swapCounter++;
                arr[j] = arr[j - gap];
                if (j == gap)
                    comparisonCounter--;
            }

            arr[j] = temp;
        }
}