/*
================================================================================================================
Name		: Text.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 21, 2019
Workshop	: Workshop 2 - In Lab
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic to instatiate Text objects. Which include reading from 
			 an external file, counting the number of records and allocating the neccessary amount of memory
			 needed for each record.
================================================================================================================
*/




#include "Text.h"
#include <string>
using namespace std; //good practice to use in implentation files

namespace sict {

	// Constructor: set safe empty state.
	Text::Text() {
		numof = 0;
		tArray = nullptr;
	}

	// 1 Argument Constuctor: gets filename from parameter and reads the file for the number of records.
	Text::Text(char* rec) {
		
		std::ifstream fin;
		fin.open(rec);
		int temp = 0;

		if (fin.is_open()) { // Check status of connection
			while (!fin.eof()) { // Keep reading until end of file
				if (fin.get() == '\n') { // When you find a new line, increment the counter.
					temp++;
				}
			}
			numof = temp;
			tArray = new std::string[numof];

			fin.seekg(0);
			for (int i = 0; i < numof && !fin.eof(); i++) {
				getline(fin, tArray[i], '\n');
			}
		}
		else {
			tArray = nullptr;
		}

	}
	// Copy Assignment Operator: Receives Text object and copies it into the current object. Checks for self-assignment, frees dynamic memory, and performs a deep copy. 
	Text& Text::operator=(const Text& rhs) {
		if (this != &rhs) {
			if (rhs.tArray != nullptr) {
				delete[] tArray;
				numof = rhs.numof;
				tArray = new std::string[numof];

				for (int i = 0; i < rhs.numof; i++) {
					tArray[i] = rhs.tArray[i];
				}
			}
			else {
				tArray = nullptr;
			}
		}
		return *this;
	}


	// Copy Constructor: Copies object into newly created object.
	Text::Text(const Text& rec) {
		if (rec.tArray != nullptr) {
			*this = rec;
		}
	}


	// Returns number of records.
	size_t Text::size() const {
		return numof;
	}

	// Frees dynamic memory, and assigns pointer.
	Text::~Text() {
		delete[] tArray;
		tArray = nullptr;
	}
}