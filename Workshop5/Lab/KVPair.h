/*
================================================================================================================
Name		: KVPair.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: June 13th, 2019
Workshop	: Workshop 5
================================================================================================================
*/

/*
================================================================================================================
Description: This header file provides the logic for a templated class that receives two types: a key name, and
			 a value. It sets the instance variables and defines the output format.
================================================================================================================
*/

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include <iostream>

extern int fieldWidth; // Tells compiler to look for definition elsewhere.

namespace sict {
	

	template<typename K, typename V>
	class KVPair {
		K key;
		V value;
	public:

		// Default Constructor: 
		KVPair() : key{}, value{} {};

		// Two Arguement Constructor: Sets instance variables to received parameters.
		KVPair(const K& rKey, const V& rValue) : key{ rKey }, value{ rValue }{};

		// Templated Query: Receives ostream and function object to display the formatted data.
		template<typename F> void display(std::ostream& os, F f) const {
			
			os.setf(std::ios::left); // Must unset explicitly.
			os.width(fieldWidth); 
			os << key << " : ";
			os.unsetf(std::ios::left); // Unsetting..

			os.setf(std::ios::right);
			os.width(fieldWidth);
			os << value;

			os.width(fieldWidth);
			os << f(value);
			os.unsetf(std::ios::right);
		};

		// Query: Returns if the current object is empty.
		bool isEmpty() const { return key == "" && value == ""; };
	};
}
#endif // !SICT_KVPAIR_H


