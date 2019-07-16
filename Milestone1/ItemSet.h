/*
================================================================================================================
Name		: ItemSet.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 8th, 2019
Workshop	: Milestone 1
================================================================================================================
*/

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H
#include <iostream>
#include <string>

namespace sict {
	class ItemSet {
		std::string name;
		int serial;
		int quant;
		std::string desc;
		static int fieldw;
	public:
		ItemSet(const std::string str);
		ItemSet(ItemSet&& src) = default;
		ItemSet(const ItemSet&) = delete;
		ItemSet& operator=(const ItemSet&) = delete;
		ItemSet& operator=(ItemSet&&) = delete;
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SICT_ITEMSET_H
