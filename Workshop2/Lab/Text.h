/*
================================================================================================================
Name		: Text.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 21, 2019
Workshop	: Workshop 2 - In Lab
================================================================================================================
*/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
#include <fstream>
#include <string>

namespace sict {

	class Text {
		int numof;
		std::string * tArray;
	public:
		Text();
		Text(char* );
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};

}

#endif // !SICT_TEXT_H