#include "Product.h"
#include <fstream>
#include <iomanip> 

sict::Product::Product(int number, double price)
{
	_number = number;
	_price = price;
}

double sict::Product::price() const
{
	return this->_price;
}

void sict::Product::display(std::ostream & os) const
{
	extern int FW; // using field width for output from L4.cpp
	os << std::setw(FW) << std::right << this->_number << std::setw(FW) << this->_price << std::endl;
}

sict::IProduct * sict::Product::readRecord(std::ifstream &file)
{
	/*file >> _number >> _price;

	return this;*/

	int n;
	double p;

	file >> n >> p;

	return new Product(n, p);
}

sict::Product::~Product()
{
}
