#ifndef SALE_H
#define SALE_H
#include <iostream>
#include <vector>
#include "Product.h"
#include "TaxableProduct.h"

namespace sict
{
	class Sale
	{
	public:
		Sale();
		Sale(char *file);
		void display(std::ostream &os) const;
		~Sale();

	private:
		std::vector<sict::IProduct *> my_vect;
	};
}

#endif // !SALE_H
