//#include <iostream>
//#include <string>
#include <fstream>
#include "Txt.h"

namespace l1
{
	Txt::Txt()
	{
		//конструктор по умолчанию
	}
	
	Txt::Txt(const std::string &Input)
	{
		std::ifstream fs(Input, std::ios::in); //пытаемся открыть файл
		if (!fs) //проверем наличие файла
		{
			std::ofstream ofs("Lab1Output.txt");
			ofs << "File not found\n" << std::endl;
			ofs.close();
		}
		else
		{
			int count = 0; //счетчик строк
			std::string str;
			while (getline(fs, str))
			{
				count++;
			}

			txt_length = count;

			fs.clear();
			fs.seekg(0); //в начало файла

			txt_array = new std::string[txt_length];
			for (int i = 0; i < count; i++)
			{
				fs >> txt_array[i];
			}

			fs.close(); //закрываем поток
		}
		
	}
	
	Txt::~Txt() 
	{
		// динамически удаляем массив, который выделили ранее
		delete[] txt_array;
	}

	//конструктор копирования
	Txt::Txt(const Txt &copy)
	{
		txt_length = copy.txt_length;
		txt_array = new std::string[txt_length];
		for (int i = 0; i < txt_length; i++)
		{
			txt_array[i] = copy.txt_array[i];
		}
	}

	//оператор присваивания копий
	Txt & Txt::operator=(const Txt &copy)
	{
		//проверка на самоприсваивание
		if (&copy == this)
			return *this;

		//если массив уже имеет значение, то удаляем это значение
		if (txt_array) 
		{
			delete[] txt_array;
		}
		
		//выполняем копирование значений
		txt_length = copy.txt_length;
		txt_array = new std::string[txt_length];
		for (int i = 0; i < txt_length; i++)
		{
			txt_array[i] = copy.txt_array[i];
		}

		return *this;
	}

	//конструктор перемещения
	Txt::Txt(Txt && move)
	{
		//присваиваем создаваемому объекту данные-члены класса из исходного объекта
		txt_length = move.txt_length;
		txt_array = move.txt_array;
		for (int i = 0; i < txt_length; i++)
		{
			txt_array[i] = move.txt_array[i];
		}
		//не позволяет деструктору многократно освобождать память
		move.txt_array = nullptr;
		move.txt_length = 0;
	}

	//оператор присваивания перемещения
	Txt & Txt::operator=(Txt &&move)
	{
		//проверка на самоприсваивание
		if (this != &move)
		{
			//если массив уже имеет значение, то удаляем это значение
			if (txt_array)
			{
				delete[] txt_array;
			}
			txt_length = 0;
			//присваиваем создаваемому объекту данные-члены класса из исходного объекта
			txt_length = move.txt_length;
			txt_array = new std::string[txt_length];
			for (int i = 0; i < txt_length; i++)
			{
				txt_array[i] = move.txt_array[i];
			}
			//не позволяет деструктору многократно освобождать память
			move.txt_array = nullptr;
			move.txt_length = 0;
		}
		
		return *this;
	}

	size_t const Txt::size()
	{
		//возвращает размер (количество записей)
		return this->txt_length;
	}
}
