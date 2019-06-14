/*
================================================================================================================
Name		: Text.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 25, 2019
Workshop	: Workshop 2
================================================================================================================
*/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

namespace sict {

	class Text {
		int numof;
		std::string * tArray;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
		Text(Text&&);
		Text& operator=(Text&&);
	};

}

#endif // !SICT_TEXT_H