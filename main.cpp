#include "ISort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "MatrixInput.h"
#include "InitialMatrixFileOutput.h"
#include "SaveData.h"
#include <Windows.h>


enum class Answer 
{
	Yes = 1,
	No

};


int main()
{	
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int const sortsCount = 5;
	std::cout << "------------------------------ " << std::endl
		<< "Бердиев Эдуард гр. 415 КР-3" << std::endl
		<< "------------------------------" << std::endl;

	while (true)
	{
		std::vector < std::shared_ptr<ISort>> sortsCase;
		std::vector < std::shared_ptr<SortedMatrix>> sortsMatrices;
		std::vector<std::vector<int>> matrix;

		sortsCase.emplace_back(std::make_shared<BubbleSort>());
		sortsCase.emplace_back(std::make_shared<QuickSort>());
		sortsCase.emplace_back(std::make_shared<SelectionSort>());
		sortsCase.emplace_back(std::make_shared<ShellSort>());
		sortsCase.emplace_back(std::make_shared<InsertionSort>());
		
		InputMode mode =static_cast<InputMode>( MatrixInput(matrix));

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				std::cout << matrix[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < sortsCount; i++)
		{
			sortsMatrices.emplace_back(std::make_shared<SortedMatrix>(matrix, sortsCase[i]));
			sortsCase[i]->Print();
			sortsMatrices[i]->Show();
		}
		
		for (int i = 0; i < sortsCount; i++)
		{
			sortsCase[i]->PrintCounters();
		}

		if (mode == InputMode::ConsoleByHand || mode == InputMode::ConsoleRandom)
		{
			std::cout << "Вы хотите сохранить исходные данные матрицы в файл?" << std::endl;
			std::cout << "1 - Да\n2 - Нет" << std::endl;
			Answer initialChoice = static_cast<Answer>(InputCheck::CheckMenu(2));
			if (initialChoice == Answer::Yes)
				InitialMatrixFileOutput(matrix);
		}
		std::cout << "Вы хотите сохранить таблицу сравнения сортировки в файл?" << std::endl;
		std::cout << "1 - Да\n2 - Нет" << std::endl;
		Answer dataChoice = static_cast<Answer>(InputCheck::CheckMenu(2));
		if(dataChoice == Answer::Yes)
			SaveData(sortsCase, sortsMatrices);

		std::cout << "Продолжать?" << std::endl;
		std::cout << "1 - Да\n2 - Нет" << std::endl;
		Answer continueChoice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if (continueChoice ==Answer::No) return 0;		
	}
	
}