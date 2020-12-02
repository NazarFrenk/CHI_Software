#ifndef IPRODUCT_H
#define IPRODUCT_H
#include <iostream>

namespace sict
{
	class IProduct
	{
	public:
		IProduct() {};
		virtual double price() const = 0;
		virtual void display(std::ostream & os) const = 0;
		friend  std::ostream& operator << (std::ostream& os, const IProduct& p)
		{
			p.display(os);
			return os;
		};
		IProduct * readRecord(std::ifstream & file) ;
	};
}

#endif // !IPRODUCT_H
