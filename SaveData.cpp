#include "SaveData.h"
#include <fstream>
#include"InputCheck.h"
#include"SaveData.h"
#include "SortedMatrix.h"

void SaveData(std::vector<std::shared_ptr<ISort>>& sortsCase, std::vector < std::shared_ptr<SortedMatrix>> sortsMatrices)
{
	const int this_file = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);


	while (true)
	{
		std::cout << "Введите имя файла или путь" << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Неправильный тип данных\n" << std::endl;
			continue;
		}
		try
		{
			CheckFileExist.open(name);
			std::cout << "Файл с таким именем уже существует!" << std::endl
				<< "1 - Сохранить в этот файл" << std::endl
				<< "2 - Выбрать другое имя" << std::endl;
			int var = InputCheck::CheckMenu(2);
			if (var == this_file)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
			}
			else
			{
				CheckFileExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << "Ошибка..." << std::endl;
				continue;
			}
		}
		break;

	}
	std::vector<std::vector<int>> matrixColums = sortsMatrices[0]->GetMatrixColums();
	std::vector<std::vector<int>> matrixLines = sortsMatrices[0] ->GetMatrixLines();

	FileRecorder<< std::string(15,' ') << "Сравнение" << "\t" << "Свап" << std::endl;
	for (int i = 0; i < sortsCase.size(); i++)
	{
		std::string temp_name = typeid(*sortsCase[i]).name();
		temp_name.erase(0, 6);
		FileRecorder << temp_name << std::string(15 - temp_name.size(),' ') << sortsCase[i]->GetComprasionCounter() << "\t\t\t" << sortsCase[i]->GetSwapCountrt() << std::endl;;
	}

	FileRecorder << "\n Отсортированная матрица" << std::endl;
	for (int i = 0; i < sortsMatrices[0]->GetNumberOflines(); i++)
	{
		for (int j = 0; j < sortsMatrices[0]->GEtNumberOfColums(); j++)
		{
			FileRecorder << matrixColums[i][j] << "\t";
		}
		FileRecorder << std::endl;
	}	
	FileRecorder.close();
}
