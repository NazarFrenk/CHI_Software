#define _CRT_SECURE_NO_WARNINGS
#include "TaxableProduct.h"
#include <fstream>
#include <stdlib.h>
#include <iomanip>

sict::TaxableProduct::TaxableProduct(int n, double p, std::string s)
{
	_number = n;
	_price = p;
	_tax = s;
}

double sict::TaxableProduct::price() const
{
	double p = this->_price;
	double total = p;
	if (this->_tax == "HST")
	{
		return total += p * 0.13;
	}
	else
	{
		return total += p * 0.08;
	}
}

void sict::TaxableProduct::display(std::ostream & os) const
{
	extern int FW; // using field width for output from L4.cpp
	os << std::setw(FW) << std::right << this->_number << std::setw(FW) << this->_price << " " << std::setw(FW) << std::left << this->_tax << std::endl;
}

sict::IProduct * sict::TaxableProduct::readRecord(std::ifstream & file)
{
	int n;
	double p;
	std::string temp;
	
	file >> n >> p;
	
	std::ios_base::streampos possition = file.tellg();
	file >> temp;

	if (temp.size() > 2)
	{
		file.seekg(possition);
		
	}

	if (temp[0] == 'H' || temp[0] == 'P')
	{
		std::string str;

		if (temp[0] == 'H')
		{
			str = "HST";
		}
		else
		{
			str = "PST";
		}
		return new TaxableProduct(n, p, str);
	}

	return new Product(n, p);
}

sict::TaxableProduct::~TaxableProduct()
{
}
