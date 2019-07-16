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
Description : Interface for Product class
================================================================================================================
*/


#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
#include <iostream>

namespace sict {

	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
		virtual ~iProduct() {};
	};
}

#endif