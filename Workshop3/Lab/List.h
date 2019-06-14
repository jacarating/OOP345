/*
================================================================================================================
Name		: List.h
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
Description: This implmentation file provides the logic to instatiate a List object using the template parameters, 
			 adds to the array and keeps track of the current amount of elements currently stored.
================================================================================================================
*/

#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>

namespace sict {

	template<typename T, int N>
	class List {
		T iArray[N];
		size_t counter = 0u;
	public:

		// Query: Returns number of elements stored in arrary.
		size_t size() const { return counter; }

		// Overloaded Operator: Returns a type T object that in stored in the arrary object specified by the received index.
		const T& operator[](size_t i) const { return iArray[i]; }

		// Overloaded Operator: Checks if theres space in the array, then appends the recieved object to the end of the array and increments the counter.
		void operator+=(const T& t) { if (counter < N) { iArray[counter++] = t; } }
	};


}
#endif // !SICT_LIST_H
