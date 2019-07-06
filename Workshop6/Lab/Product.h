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

namespace sict {

	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
		virtual ~iProduct() {};
	};

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
}

#endif