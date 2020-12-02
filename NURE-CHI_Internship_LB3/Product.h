#ifndef PRODUCT_H
#define PRODUCT_H
#include "IProduct.h"

namespace sict
{
	class Product : public IProduct
	{
	public:
		Product() {};
		Product(int number, double price);
		virtual double price() const;
		virtual void display(std::ostream & os) const;
		friend  std::ostream& operator << (std::ostream& os, const Product& p)
		{
			p.display(os);
			return os;
		};
		virtual IProduct * readRecord(std::ifstream & file);
		~Product();
	private:
		int _number;
		double _price;
	};
}

#endif // !PRODUCT_H

