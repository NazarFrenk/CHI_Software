#pragma once
#include <cassert> 
#ifndef LIST_H
#define LIST_H

template<typename T, size_t N>
class List
{
public:
	//конструктор по умолчанию - принимает безопасное пустое состояние
	List()
	{
		this->counter = 0;
		this->_size = N;
	};

	//возвращает количество елементов в массиве
	const size_t size()
	{
		return this->_size;
	};

	//перегруженный оператор, возвращающий запрошенный индекс массива
	const T & operator [] (int index) const
	{
		assert(index >= 0 && index < _size);

		return mass[index];
	};

	//перегруженный оператор, который добавляет элемент в массив, если есть свободное место
	void operator += (const T &temp)
	{
		if (this->counter == size())
		{
			return;
		}

		this->mass[counter] = temp;
		this->counter++;
	};

	//деструктор
	~List()
	{
		
	};

private:
	T mass[N]; //массив из N-элементов
	size_t _size = N; //размер списка
	int counter = 0;
};

#endif // !LIST_H
