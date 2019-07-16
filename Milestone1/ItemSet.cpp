/*
================================================================================================================
Name		: ItemSet.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 8th, 2019
Workshop	: Milestone 1
Description : This file provides functionality for the ItemSet class for managing the stock inventory of a particular item.
================================================================================================================
*/

#include <iostream>
#include <string>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	int ItemSet::fieldw = 0;
	
	// One Arguement Constructor: extracts 4 tokens from the string, populates the object with those tokens.
	ItemSet::ItemSet(const std::string str) {
		Utilities use;
		size_t str_pos = 0;
		try {
			if (!str.empty()) {
				name = use.extractToken(str, str_pos);
				if (name.length() > use.getFieldWidth()) {
					use.setFieldWidth(name.length());
				}
				serial = stoi(use.extractToken(str, str_pos));
				quant = stoi(use.extractToken(str, str_pos));
				desc = use.extractToken(str, str_pos);

				fieldw = use.getFieldWidth();
			}
		}
		catch (const std::string& str) {
			std::cerr << str << std::endl;
		}
	}

	// Query: 
	const std::string& ItemSet::getName() const {
		return name;
	}

	// Query: 
	const unsigned int ItemSet::getSerialNumber() const {
		return serial;
	}

	// Query: 
	const unsigned int ItemSet::getQuantity() const {
		return quant;
	}

	// Overloaded Operator: 
	ItemSet& ItemSet::operator--() {
		--quant;
		++serial;
		return *this;
	}

	// Query: inserts the data for the current object into stream os
	void ItemSet::display(std::ostream& os, bool full) const {
		if (full) {
			os.setf(std::ios::left);
			os.fill(' ');
			os.width(fieldw);
			os << name << " [";
			os.fill('0');
			os.width(5);
			os << serial << "] " << "Quantity ";
			os.fill(' ');
			os.width(3);
			os << quant << " Description: " << desc << std::endl;
		}
		else {
			os.width(fieldw);
			os << name << " " << serial + 1 << std::endl;
		}
	}
}