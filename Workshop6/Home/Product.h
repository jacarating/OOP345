/*
================================================================================================================
Name		: Product.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 5th, 2019
Workshop	: Workshop 6
================================================================================================================
*/


#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace sict {

	class Product : public iProduct {
		int prodno;
		double saleprice;
	public:
		Product(int num, double p);
		double price() const;
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);

	class TaxableProduct : public Product {
		enum class taxtype { HST, PST, NoTax };
		taxtype tax;
		static double hst;
		static double pst;
	public:
		TaxableProduct(int num, double p, char t);
		double price() const;
		void display(std::ostream& os) const;
	};
}

#endif