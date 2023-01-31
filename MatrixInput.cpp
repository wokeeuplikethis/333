#include "MatrixInput.h"
#include <time.h>


int  MatrixInput(std::vector<std::vector<int>>& matrix)
{

	std::cout << "1 - ���������� ������� � ���������� " << std::endl
		<< "2 - ���������� ������� ��������" << std::endl
		<< "3 - ���������� ������� �� �����" << std::endl;
	InputMode mode = static_cast<InputMode>(InputCheck::CheckMenu(3));
	switch (mode)
	{
	case InputMode::ConsoleByHand:
		matrix = ConsoleInput();
		break;

	case InputMode::ConsoleRandom:
		matrix = RandomInput();
		break;

	case InputMode::File:
		matrix = FileInput();
		break;

		
	}
	return static_cast<int>(mode);
}

std::vector<std::vector<int>> ConsoleInput()
{
	
		std::cout << "������� ���-�� �����." << std::endl;;
		int lines = InputCheck::CheckIntValuePlus();
		std::cout << "������� ���-�� ��������." << std::endl;;
		int colums = InputCheck::CheckIntValuePlus();

		std::vector<std::vector<int>> matrix;

		for (int i = 0; i < lines; i++)
		{
			matrix.push_back(std::vector<int>{});
			for (int j = 0; j < colums; j++)
			{
				std::cout << "Enter [" << i + 1 << "] [" << j + 1 << "] ." << std::endl;
				matrix[i].push_back(InputCheck::CheckIntValue());
			}
		}
		return matrix;
}

std::vector<std::vector<int>> FileInput()
{		
	std::string file_name = "";
	std::ifstream file;
	std::vector<std::vector<int>> matrix = {};
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "������� ��� ����� ��� ����." << std::endl << "ENTER : ";
		std::getline(std::cin,file_name);
		if (file_name.find(".txt") >= std::string::npos) {
			std::cout << "������������ ��� ������\n" << std::endl;;
		continue;
		}	
		try
		{
			file.open(file_name);
			std::cout << "���� ������� ������!" << std::endl;
		}
		catch (std::exception&)
		{
			std::cout << "������������ ��� ����� ��� ����... �������� ��� ���!" << std::endl;
			continue;
		}

		try
		{
			int lines = (InputCheck::CheckLineUnsInt(file));
			int colums = (InputCheck::CheckLineUnsInt(file));
			

			for (int i = 0; i < lines; i++)
			{
				matrix.push_back(std::vector<int>{});
				for (int j = 0; j < colums; j++)
				{
					matrix[i].push_back( InputCheck::CheckLineInt(file));
				}
			}
		}
		catch (std::exception&)
		{
			file.close();
			matrix.clear();
			continue;
		}
		file.close();
		return matrix;
	}
}

std::vector<std::vector<int>>  RandomInput() 
{
	srand(static_cast<unsigned>(time(nullptr)));
	std::cout << "������� ���-�� �����." << std::endl;;
	int lines = InputCheck::CheckIntValuePlus();
	std::cout << "������� ���-�� ��������." << std::endl;;
	int colums = InputCheck::CheckIntValuePlus();

	std::vector<std::vector<int>>	matrix;

	for (int i = 0; i < lines; i++)
	{
		matrix.push_back(std::vector<int>{});
		for (int j = 0; j < colums; j++)
		{
			matrix[i].push_back(std::rand() % 101 - 50);
		}
	}
	return matrix;
}

