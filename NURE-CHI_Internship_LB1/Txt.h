#include <string>
#ifndef TXT_H
#define TXT_H

namespace l1
{
	class Txt
	{
	public:
		//������ �����������
		Txt();

		//����������� � ����������
		Txt(const std::string &Input);

		//����������� �����������;
		Txt(const Txt&);

		//�������� ������������ �����;
		Txt& operator = (const Txt&);

		//����������� �����������;
		Txt(Txt&&);

		//�������� ������������ �����������;
		Txt& operator = (Txt&&);

		//����������;
		~Txt();

		//������� - ���� � ������ size_t size() const, ������� ���������� ���������� ������� ��������� ������;
		size_t const size();

	private:
		std::string *txt_array; //������ ��� �����
		int txt_length; //��� ������
	};
}

#endif // !TXT_H
