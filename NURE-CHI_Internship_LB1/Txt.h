#include <string>
#ifndef TXT_H
#define TXT_H

namespace l1
{
	class Txt
	{
	public:
		//пустой конструктор
		Txt();

		//конструктор с параметром
		Txt(const std::string &Input);

		//конструктор копирования;
		Txt(const Txt&);

		//оператор присваивания копий;
		Txt& operator = (const Txt&);

		//конструктор перемещения;
		Txt(Txt&&);

		//оператор присваивания перемещения;
		Txt& operator = (Txt&&);

		//деструктор;
		~Txt();

		//функция - член с именем size_t size() const, которая возвращает количество записей текстовых данных;
		size_t const size();

	private:
		std::string *txt_array; //массив для строк
		int txt_length; //его размер
	};
}

#endif // !TXT_H
