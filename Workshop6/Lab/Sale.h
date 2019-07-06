/*
================================================================================================================
Name		: Sale.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 5th, 2019
Workshop	: Workshop 6
================================================================================================================
*/
#ifndef SICT_SALE_H
#define SICT_SALE_H
#include <iostream>
#include <vector>
#include "Product.h"

namespace sict{
	class Sale {
		std::vector<iProduct*> products;
	public:
		Sale(const char* filename);
		void display(std::ostream& os) const;
		~Sale();
	};
}

#endif