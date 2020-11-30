#pragma once
#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair
{
public:
	//����������� �� ��������� - ��������� ���������� ������ ���������
	Pair()
	{

	};

	//������������� �����������, ������� ������������� �������� ���� ���� - �������� ������.
	Pair(const A &key, const B &value)
	{
		_key = key;
		_value = value;
	};

	//���������� ��������� ������ ��� ������ ������ ����������� �������� ����������
	const A & getKey() const
	{
		return this->_key;
	};

	//���������� ��������� ������ ��� ������ ������ ���������� � ����������� ��������.
	const B & getValue() const
	{
		return this->_value;
	};

	//����������
	~Pair()
	{

	};

private:
	A _key; //����
	B _value; //��������
};

#endif // !PAIR_H
