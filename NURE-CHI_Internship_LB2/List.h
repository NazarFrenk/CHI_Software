#pragma once
#include <cassert> 
#ifndef LIST_H
#define LIST_H

template<typename T, size_t N>
class List
{
public:
	//����������� �� ��������� - ��������� ���������� ������ ���������
	List()
	{
		this->counter = 0;
		this->_size = N;
	};

	//���������� ���������� ��������� � �������
	const size_t size()
	{
		return this->_size;
	};

	//������������� ��������, ������������ ����������� ������ �������
	const T & operator [] (int index) const
	{
		assert(index >= 0 && index < _size);

		return mass[index];
	};

	//������������� ��������, ������� ��������� ������� � ������, ���� ���� ��������� �����
	void operator += (const T &temp)
	{
		if (this->counter == size())
		{
			return;
		}

		this->mass[counter] = temp;
		this->counter++;
	};

	//����������
	~List()
	{
		
	};

private:
	T mass[N]; //������ �� N-���������
	size_t _size = N; //������ ������
	int counter = 0;
};

#endif // !LIST_H
