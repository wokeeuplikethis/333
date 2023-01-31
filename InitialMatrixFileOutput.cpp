#include "InitialMatrixFileOutput.h"

void InitialMatrixFileOutput(std::vector<std::vector<int>> matrix)
{
	const int this_file = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{
		std::cout << "������� ��� ����� ��� ����" << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "������������ ��� ������\n" << std::endl;
			continue;
		}
		try
		{
			CheckFileExist.open(name);
			std::cout << "���� � ����� ������ ��� ����������..." << std::endl
				<< "1 - ��������� � ���� ���� " << std::endl
				<< "2 - ������� ������ ��� " << std::endl;
			int var = InputCheck::CheckMenu(2);
			if (var == this_file)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
				std::cout << "���� ������� ��������!" << std::endl;
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
				std::cout << "���� ������� ��������!" << std::endl;
			}
			catch (const std::exception&)
			{
				std::cout << "������..." << std::endl;
				continue;
			}

		}
		break;


	}

	int numberOfLines = static_cast<int> (matrix.size());
	int numberOfColums = static_cast<int>(matrix[0].size());


	FileRecorder << numberOfLines << std::endl;
	FileRecorder << numberOfColums << std::endl;
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfColums; j++)
		{
			FileRecorder << matrix[i][j] << std::endl;
		}
	}
	FileRecorder.close();
}

