//#include <iostream>
//#include <string>
#include <fstream>
#include "Txt.h"

namespace l1
{
	Txt::Txt()
	{
		//����������� �� ���������
	}
	
	Txt::Txt(const std::string &Input)
	{
		std::ifstream fs(Input, std::ios::in); //�������� ������� ����
		if (!fs) //�������� ������� �����
		{
			std::ofstream ofs("Lab1Output.txt");
			ofs << "File not found\n" << std::endl;
			ofs.close();
		}
		else
		{
			int count = 0; //������� �����
			std::string str;
			while (getline(fs, str))
			{
				count++;
			}

			txt_length = count;

			fs.clear();
			fs.seekg(0); //� ������ �����

			txt_array = new std::string[txt_length];
			for (int i = 0; i < count; i++)
			{
				fs >> txt_array[i];
			}

			fs.close(); //��������� �����
		}
		
	}
	
	Txt::~Txt() 
	{
		// ����������� ������� ������, ������� �������� �����
		delete[] txt_array;
	}

	//����������� �����������
	Txt::Txt(const Txt &copy)
	{
		txt_length = copy.txt_length;
		txt_array = new std::string[txt_length];
		for (int i = 0; i < txt_length; i++)
		{
			txt_array[i] = copy.txt_array[i];
		}
	}

	//�������� ������������ �����
	Txt & Txt::operator=(const Txt &copy)
	{
		//�������� �� ����������������
		if (&copy == this)
			return *this;

		//���� ������ ��� ����� ��������, �� ������� ��� ��������
		if (txt_array) 
		{
			delete[] txt_array;
		}
		
		//��������� ����������� ��������
		txt_length = copy.txt_length;
		txt_array = new std::string[txt_length];
		for (int i = 0; i < txt_length; i++)
		{
			txt_array[i] = copy.txt_array[i];
		}

		return *this;
	}

	//����������� �����������
	Txt::Txt(Txt && move)
	{
		//����������� ������������ ������� ������-����� ������ �� ��������� �������
		txt_length = move.txt_length;
		txt_array = move.txt_array;
		for (int i = 0; i < txt_length; i++)
		{
			txt_array[i] = move.txt_array[i];
		}
		//�� ��������� ����������� ����������� ����������� ������
		move.txt_array = nullptr;
		move.txt_length = 0;
	}

	//�������� ������������ �����������
	Txt & Txt::operator=(Txt &&move)
	{
		//�������� �� ����������������
		if (this != &move)
		{
			//���� ������ ��� ����� ��������, �� ������� ��� ��������
			if (txt_array)
			{
				delete[] txt_array;
			}
			txt_length = 0;
			//����������� ������������ ������� ������-����� ������ �� ��������� �������
			txt_length = move.txt_length;
			txt_array = new std::string[txt_length];
			for (int i = 0; i < txt_length; i++)
			{
				txt_array[i] = move.txt_array[i];
			}
			//�� ��������� ����������� ����������� ����������� ������
			move.txt_array = nullptr;
			move.txt_length = 0;
		}
		
		return *this;
	}

	size_t const Txt::size()
	{
		//���������� ������ (���������� �������)
		return this->txt_length;
	}
}
