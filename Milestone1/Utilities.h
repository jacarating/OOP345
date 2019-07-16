/*
================================================================================================================
Name		: Utilities.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 8th, 2019
Workshop	: Milestone 1
================================================================================================================
*/
#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
#include <string>

namespace sict {
	class Utilities {
		int fieldWidth;
		static char delimeter;
	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif

