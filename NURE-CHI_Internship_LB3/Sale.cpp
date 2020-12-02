#include "Sale.h"
#include <fstream>
#include <iomanip>

sict::Sale::Sale()
{
}

sict::Sale::Sale(char * file)
{
	std::ifstream  my_stream(file);
	if (my_stream.is_open())
	{

		while (!my_stream.eof()) 
		{
			TaxableProduct temp = TaxableProduct();
			
			my_vect.push_back((temp.readRecord(my_stream)));
		}
		my_stream.close();
	}
}

void sict::Sale::display(std::ostream & os) const
{
	extern int FW; // using field width for output from L4.cpp
	if (!my_vect.empty())
	{
		double total = 0;
		os << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << std::setw(FW) << std::left << " Taxable" << std::endl;
		for (size_t i = 0; i < my_vect.size(); i++)
		{
			my_vect[i]->display(os);
			total += my_vect[i]->price();
		}

		os << std::setw(FW) << "Total" << std::setw(FW) << std::setprecision(5) << total << std::endl;
	}
}

sict::Sale::~Sale()
{
}
