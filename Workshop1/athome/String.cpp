/*
================================================================================================================
Name		: String.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 16, 2019
Workshop	: Workshop 1 - In Lab
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic to instatiate String objects, handle errors at instantiation, and display their contents.
================================================================================================================
*/

#include "String.h"



namespace sict {

	// Constructor that checks for invalid string. Initializes data memeber to valid arguement.
	String::String(const char* str) {
		if (str[0] == '\0' || str == nullptr) {
			iStr = nullptr;
		}
		else {
			iStr = new char[strlen(str) + 1]; // Create dynamic memory.
			strncpy(iStr, str, strlen(str)); // Copy string up to string length.
			iStr[strlen(str)] = '\0'; // Last element set to null terminator.
		}

	}

	// Inserts the string stored in the instance variable.  
	void String::display(std::ostream &os) const {
		os << iStr; 
	}

	// Overloaded helper function that counts of how many String objects that have been instantiated, and outputs that number followed by the string stored in that object in the specified format.
	std::ostream& operator<<(std::ostream &lhs, const String &rhs) {
		static int iCounter = INITIAL; // We need to make static to prevent the counter to re-initializing back to 3. Declaration of class variable.
		lhs << iCounter++ << ": ";
		rhs.display(lhs);
		

		return lhs;
	}

}