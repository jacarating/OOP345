/*
================================================================================================================
Name		: LVPair.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 31, 2019
Workshop	: Workshop 3
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic to instatiate LVPair objects using their template parameters.
			 As well as the implmentation of displaying their content as per instructed.
================================================================================================================
*/


#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>

namespace sict {

	template<typename L, typename V>
	class LVPair {
		L iLabel;
		V iValue;
	public:

		// Default Constructor: Sets object to safe state.
		LVPair() : iLabel{}, iValue{} {}

		// Two Argument Constructor: Initializes instance variables to the received parameters.
		LVPair(const L& label, const V& value) : iLabel{ label }, iValue{ value } {};

		// Query: Display objects' content in specified format.
		void display(std::ostream& os) const { os << iLabel << " : " << iValue << std::endl; };
	};

	// Non-Friend Helper Function: inserts into os the received LVPair object.
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) { pair.display(os); return os; };
}
#endif // !SICT_LVPAIR_H


