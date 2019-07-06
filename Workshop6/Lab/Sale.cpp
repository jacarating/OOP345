/*
================================================================================================================
Name		: Sale.cpp
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
#include <vector>
#include "Sale.h"

extern int FW;

namespace sict {

	Sale::Sale(const char* filename) {
		std::ifstream fin;
		fin.open(filename);
		int counter = 0;

		if (fin.is_open()) {
			while (!fin.eof()) {
				if (fin.get() == '\n') {
					++counter;
				}
			}
			fin.clear();
			fin.seekg(0);
			for (int i = 0; i < counter; i++) {
				products.push_back(readRecord(fin));
			}
		}
		else {
			throw "Failed to open file!";
		}
	}

	void Sale::display(std::ostream& os) const {
		os << "\nProduct No";
		os.setf(std::ios::right);
		os.width(FW);
		os << "Cost" << std::endl;
		double total = 0;
		for (auto e : products) {
			e->display(os);
			total += e->price();
			os << std::endl;
		}
		os.width(FW);
		os << "Total";
		os.width(FW);
		os << total;
	}

	Sale::~Sale() {
		for (auto e : products) {
			delete e;
		}
	}
}