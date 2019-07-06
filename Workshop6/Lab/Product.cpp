/*
================================================================================================================
Name		: Product.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 5th, 2019
Workshop	: Workshop 6
Description : This file provides the logic to create Product objects, display their content, and the abilty to read and store records from a file.
================================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"

extern int FW;

namespace sict {

	// Two Arguement Constructor: Assigns values that are received to its' data members.
	Product::Product(int num, double p) {
		prodno = num;
		saleprice = p;
	}

	// Query: Returns current objects' saleprice value.
	double Product::price() const {
		return saleprice;
	}

	// Query: Display product number and sale price with format.
	void Product::display(std::ostream& os) const {
		os.width(FW);
		os << prodno;
		os.width(FW);
		os.setf(std::ios::fixed);
		os.precision(2);
		os << saleprice;
	}

	// Overloaded Operator: Calls p display function.
	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	// Function: Reads a single record from a file and allocates memory for a Product object and passes the num and price into its' constructor parameters.
	iProduct* readRecord(std::ifstream& file) {
		iProduct* polym;
		if (file.is_open()) {
			if (!file.eof()) {
				int num;
				double price;
				file >> num;
				file >> price;
				polym = new Product(num, price);
			}
		}
		return polym; // return address.
	}
}