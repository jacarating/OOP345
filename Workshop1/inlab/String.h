/*
================================================================================================================
Name		: String.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 16, 2019
Workshop	: Workshop 1 - In Lab
================================================================================================================
*/



#ifndef SICT_STRING_H
#define SICT_STRING_H

#include <cstring>
#include <iostream>

extern const int INITIAL; // Tell compiler this variable exists in another translation unit.
namespace sict {
	const int MAX{ 3 };

	class String {
		char iStr[MAX+1]; // Possible to use pointer instead for any string size, allocate MAX size memory 
	public:
		String(const char*); // Receives the address of an unmodifiable C-style nullterminated string.
		void display(std::ostream &os) const; //  Receives a reference to an std::ostream object. Display functions always must be const. No changes allowed!
		//~String() { delete[] iStr; } // Free dynamic memory for pointer (don't need for static memory)
	};

	std::ostream& operator<<(std::ostream&, const String&); // Need to overload to insert into output stream
	

}
#endif // !SICT_STRING_H