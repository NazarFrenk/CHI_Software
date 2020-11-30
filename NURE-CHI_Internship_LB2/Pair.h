#pragma once
#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair
{
public:
	//конструктор по умолчанию - принимает безопасное пустое состояние
	Pair()
	{

	};

	//перегруженный конструктор, который устанавливает элементы пары ключ - значение класса.
	Pair(const A &key, const B &value)
	{
		_key = key;
		_value = value;
	};

	//возвращает доступную только для чтения версию сохраненной ключевой информации
	const A & getKey() const
	{
		return this->_key;
	};

	//возвращает доступную только для чтения версию информации о сохраненном значении.
	const B & getValue() const
	{
		return this->_value;
	};

	//деструктор
	~Pair()
	{

	};

private:
	A _key; //ключ
	B _value; //значение
};

#endif // !PAIR_H
