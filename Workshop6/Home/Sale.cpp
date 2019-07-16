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
Description : This files provides the logic to instatiate Sale objects and display their contents.
================================================================================================================
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Sale.h"

extern int FW;

namespace sict {

	// One-Arguement Constructor: Receives filename and reads each record then stores them into the sequence (products).
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

	// Query: Display current objects content with specified format.
	void Sale::display(std::ostream& os) const {
		os << "\nProduct No";
		os.setf(std::ios::right);
		os.width(FW);
		os << "Cost";
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os << " Taxable" << std::endl;
		os.unsetf(std::ios::left);

		double total = 0;
		for (auto e : products) {
			e->display(os);
			total += e->price();
			os << std::endl;
		}
		os.setf(std::ios::right);
		os.width(FW);
		os << "Total";
		os.width(FW);
		os << total << std::endl;
		os.unsetf(std::ios::right);
	}

	// Destructor: 
	Sale::~Sale() {
		for (auto e : products) {
			delete e;
		}
	}
}