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


	// Template Derived Class Declaration: 
	template<typename T, typename L, typename V, int N>
	class LVList : public List <T, N> {
	public:
		V accumulate(const L& label) const {
			
			// Set a local object of type V to the initial value (either int or string) of type T's class variable
			V acc = T::getInitialValue();

			//call the sum function to find a match with that "label" and send the "acc" value in as a parameter
			//then assign the summed value to "acc", so that when it loops again with another "label" match, 
			//it sends the new summed value into the sum function, and accumulates the values
			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
				acc = ((List<T, N>&)*this)[i].sum(label, acc);
			}

			//after iterating through all the elements, return the "acc" accumulated value of all the matches of the "label"
			return acc;
		}
	};
}
#endif // !SICT_LIST_H
