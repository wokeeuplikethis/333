#include "InputCheck.h"

int InputCheck::value = 0;
std::string InputCheck::value_input = "";

int InputCheck::CheckIntValue()
{
	while (true)
	{
		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);
		try
		{
			value = stoi(value_input);

			return value;
		}
		catch (std::exception&)
		{

			std::cout << "Ошибка...Попробуй ещё раз! " << std::endl;

		}

	}
}
int InputCheck::CheckIntValuePlus()
{
	while (true)
	{
		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);
		try
		{
			value = stoi(value_input);

			if (value <= 0)
				throw std::exception("NegativeInt");
			else 
				return value;
		}
		catch (std::exception&)
		{

			std::cout << "Ошибка...Попробуй ещё раз!" << std::endl;


		}

	}
}

int InputCheck::CheckMenu(int items)
{
	while (true)
	{

		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);

		try
		{
			value = stoi(value_input);
			if (value <= items && value >= 1)
				return value;
			else
				throw value;
		}
		catch (std::exception&)
		{

			std::cout << "Несуществующий пункт меню...Попробуй ввести цифру! " << std::endl;
		}
		catch (int ex_value)
		{
			std::cout << ex_value << " - несуществующий пункт меню... Попробуй ещё раз!" << std::endl;
		}
	}
}

int InputCheck::CheckLineInt(std::ifstream& file)
{
	std::string temp_v = "";
	int temp_i = 0;

	try
	{
		std::getline(file, temp_v);
	}
	catch (const std::exception&)
	{
		std::cout << "Не хватает данных или неправильная форма файла" << std::endl;

		throw  std::exception("Wrong data");
	}
	try
	{
		temp_i = stoi(temp_v);
	
		return temp_i;
	}
	catch (const std::exception&)
	{
		std::cout << "Ошибка...Неправильные данные" << std::endl;

		throw std::exception("Wrong data");
	
	}
}

int InputCheck::CheckLineUnsInt(std::ifstream& file)
{
	std::string temp_v = "";
	int temp_i = 0;

	try
	{
		std::getline(file, temp_v);
	}
	catch (const std::exception&)
	{
		std::cout << "Не хватает данных или непрвавильная форма файла" << std::endl;
		throw  std::exception("Wrong data");
		
	}
	try
	{
		temp_i = stoi(temp_v);
		if (temp_i < 0)

		{
			throw  std::exception("Wrong data");
		}
		else if (temp_i == 0)
		{
			throw std::exception("bro tut 0");
		}
			return temp_i;
	}
	catch (const std::exception&)
	{
		std::cout << "Не хватает данных или неправильная форма файла" << std::endl;

		throw std::exception("Wrong data");
		
	}
}

