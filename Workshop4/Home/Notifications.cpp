/*
================================================================================================================
Name		: Notifications.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: June 9th, 2019
Workshop	: Workshop 4
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic for the class Notifications to utilize its aggregation
			 class Message. The Notifications class uses a pointer to pointer (**) that dynamically allocates
			 memory to an unmodifiable array of Message objects and counts the number of the currently stored
			 addresses in the array.
================================================================================================================
*/
#include <iostream>
#include <string>
#include "Notifications.h"

namespace sict {

	// Default Constructor: Set to safe state.
	Notifications::Notifications() {
		ptrptr = nullptr;
		maxadd = 0;
		n = 0;
	}

	// One Arguement Constructor: Check if size is valid, allocate memory.
	Notifications::Notifications(int maxele) {
		if (maxele > 0) {
			ptrptr = new const Message*[maxele];
			maxadd = maxele;
			n = 0;
		}
		else {
			*this = Notifications();
		}
	}

	// Copy Constructor: Check for validation, then copy resources into newly created Notifications object.
	Notifications::Notifications(const Notifications& src) {
		ptrptr = nullptr;
		*this = src;
	}

	// Move Constructor: Calls the move assignment operator to take resources for a newly created Notifications object.
	Notifications::Notifications(Notifications&& src) {
		ptrptr = nullptr;
		*this = std::move(src);
	}

	// Copy Assignment: Performs a deep copy of the received objects' resources to an existing object.
	Notifications& Notifications::operator=(const Notifications& src) {
		if (this != &src) {
			if (src.ptrptr != nullptr && src.n > 0) {
				delete[] ptrptr; // Delete anything within current object.
				n = src.n;
				maxadd = src.maxadd;
				ptrptr = new const Message*[src.maxadd];
				for (size_t i = 0; i < n; i++) {
					ptrptr[i] = src.ptrptr[i];
				}
			}
			else {
				ptrptr = nullptr;
			}
		}
		return *this;
	}

	// Move Assignment: Moves resources from received object, and into the current object.
	Notifications& Notifications::operator=(Notifications&& src) {
		if (this != &src) { // Check for self assignment.
			if (src.ptrptr != nullptr && src.n > 0) {
				delete[] ptrptr;
				n = src.n;
				maxadd = src.maxadd;
				ptrptr = src.ptrptr;
				
				// Disassociate src object from current object:
				src.ptrptr = nullptr;
				src.n = 0;
				src.maxadd = 0;
			}
			else {
				ptrptr = nullptr;
			}
		}
		return *this;
	}

	// Deconstructor: Free memory.
	Notifications::~Notifications() {
		delete[] ptrptr;
		ptrptr = nullptr;
	}

	// Modifier: Check for validation, then assign msg address into aggregation of Message objects and increment the counter.
	Notifications& Notifications::operator+=(const Message& msg) {
		if (!msg.empty() && n < (size_t)maxadd) {
			ptrptr[n++] = &msg;
		}
		return *this;
	}

	// Modifier: Looks for matching addresses within Message** array, once found remove that address, decrement the counter, and then shift over the remaining addresses.
	Notifications& Notifications::operator-=(const Message& msg) {
		bool found = false;
		size_t i;
		for (i = 0; i < n && !found; i++) {
			if (ptrptr[i] == &msg) { //if address stored at that index is same as address of "msg"
				found = true;		//means it was successfully found in the array of pointers
			}
		}
		if (found) {
			for (; i < n; i++) {  //if address was matched,
				ptrptr[i - 1] = ptrptr[i];  //remove the address from the array of pointers
											//by shifting the elements one position to the left
			}								//which will overwrite the index at which it was stored
			if (n) {			//if number of elements is not zero,
				ptrptr[n - 1] = nullptr;  //make the last index nullptr
				n--;			//subtract the number of elements by one
			}
		}

		return *this;
	}

	// Query: Inserts into the output stream os each element in the array of Message objects.  
	void Notifications::display(std::ostream& os) const {
		for (size_t i = 0; i < n; i++) {
			ptrptr[i]->display(os);
		}
	}

	// Query: Returns the number of Message objects pointed to by the current object. 
	size_t Notifications::size() const {
		return n;
	}

	// Non-friend Helper Function: inserts into os the contents of the Notifications object. 
	std::ostream& operator<<(std::ostream& os, const Notifications& notif) {
		if (notif.size()) {
			notif.display(os);
		}
		return os;
	}

}
