#ifndef TAXABLEPRODUCT_H
#define TAXABLEPRODUCT_H
#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include <string>

namespace sict
{
	class TaxableProduct : public Product
	{
	public:
		TaxableProduct() {};
		TaxableProduct(int n, double p, std::string s);
		virtual double price() const;
		virtual void display(std::ostream & os) const;
		friend  std::ostream& operator << (std::ostream& os, const TaxableProduct& p)
		{
			p.display(os);
			return os;
		};
		virtual IProduct * readRecord(std::ifstream & file);
		~TaxableProduct();
	private:
		int _number;
		double _price;
		std::string _tax;
	};
}

#endif // !TAXABLEPRODUCT_H