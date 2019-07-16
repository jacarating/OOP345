/*
================================================================================================================
Name		: Utilities.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: July 8th, 2019
Workshop	: Milestone 1
Description : This file provides functionality for the Utilities class to extract tokens from a string.
================================================================================================================
*/
#include <iostream>
#include <string>
#include "Utilities.h"

namespace sict {
	char Utilities::delimeter = '\0';


	Utilities::Utilities() : fieldWidth{ 0 } {	}

	// Modifier: Extracts token from a string.
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string token;

		size_t endofstr = std::string::npos;

		//find the delimiter starting from the next_pos of the str
		size_t nextdelim = str.find(delimeter, next_pos);

		//if delimiter is at the next_pos, then one delimiter follows another, throw error
		if (nextdelim == next_pos) throw str + " ERROR: No token between delimiters";

		//if delimiter is found, then nextdelim will not equal the npos
		if (nextdelim != endofstr) {

			//extract substring at the start of token (next_pos) and the number of characters between the delimiter and the beginning of token
			token = str.substr(next_pos, nextdelim - next_pos);

			//set next_pos to one character after the delimiter, which would be the start of the next token
			next_pos = nextdelim + 1;

			//if (token.length() > width) { //if new token has larger fieldwidth, 
			//	width = token.length();   //then set the data member to the larger width
			//}
		}
		else {  //if no next delimiter is found, extract last token and set next_pos to beyond end of string
			token = str.substr(next_pos);
			next_pos = endofstr;
		}

		return token;
	}

	// Modifier: set field size.
	void Utilities::setFieldWidth(size_t t) {
		fieldWidth = t;
	}

	// Query:
	const char Utilities::getDelimiter() const {
		return delimeter;
	}

	// Modifier: set the delimiter for token
	void Utilities::setDelimiter(const char d) {
		delimeter = d;
	}

	// Query: 
	size_t Utilities::getFieldWidth() const {
		return fieldWidth;
	}




}