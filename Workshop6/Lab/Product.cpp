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
================================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"

extern int FW;

namespace sict {

	Product::Product(int num, double p) {
		prodno = num;
		saleprice = p;
	}

	double Product::price() const {
		return saleprice;
	}

	void Product::display(std::ostream& os) const {
		os.width(FW);
		os << prodno;
		os.width(FW);
		os.setf(std::ios::fixed);
		os.precision(2);
		os << saleprice;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

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
		return polym;
	}
}