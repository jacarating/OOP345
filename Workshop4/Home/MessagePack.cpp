/*
================================================================================================================
Name		: MessagePack.cpp
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
Description: This implmentation file provides the logic to MessagePack that manages a composition of Message objects.
================================================================================================================
*/

#include <iostream>
#include <utility>
#include "MessagePack.h"

namespace sict {
	// Two Argument Constructor: Receives array of objects, checks for validation, allocates adaquate memory, and copies objects within each index (if valid).
	MessagePack::MessagePack(Message** ptr, int no) {
		msgptr = nullptr;
		if (ptr != nullptr && no > 0) {
			msgptr = new Message[no];
			n = 0;
			for (size_t i = 0; i < (size_t)no; i++) {
				if (!ptr[i]->empty()) {
					msgptr[n++] = *ptr[i];
				}
			}
		}
	}

	// Copy Constructor: Copies entire object using copy assignment operator.
	MessagePack::MessagePack(const MessagePack& src) {
		msgptr = nullptr;
		*this = src;
	}

	// Move Constructor: Move resources from src object to newly created object. Calls the move assignment operator.

	MessagePack::MessagePack(MessagePack&& src) {
		msgptr = nullptr;
		*this = std::move(src);
	}

	// Copy Assignment Operator: Performs a deep copy of the src object into the current object by allocating dynamic memory.
	MessagePack& MessagePack::operator=(const MessagePack& src) {
		if (this != &src) {
			if (src.msgptr != nullptr && src.n > 0) {
				delete[] msgptr;
				n = src.n;
				msgptr = new Message[n];
				for (size_t i = 0; i < n; i++) {
					msgptr[i] = src.msgptr[i];
				}
			}
			else {
				msgptr = nullptr;
			}
		}
		return *this;
	}

	// Move Assignment Operator: Moves src object resources to current object.
	MessagePack& MessagePack::operator=(MessagePack&& src) {
		if (this != &src) {
			if (src.msgptr != nullptr && src.n > 0) {
				delete[] msgptr;  // Prepare object for resource
				n = src.n;
				msgptr = src.msgptr;

				src.msgptr = nullptr;
				src.n = 0;
			}
			else {
				msgptr = nullptr;
			}
		}
		return *this;
	}

	// Destructor: Deallocate dynamic memory, and assign to a safe state.
	MessagePack::~MessagePack() {
		delete[] msgptr;
		msgptr = nullptr;
	}

	// Query: Displays Message contents for each element by calling the component objects' display function.
	void MessagePack::display(std::ostream& os) const {
		for (size_t i = 0; i < n; i++) {
			msgptr[i].display(os);
		}
	}

	// Query: Returns the number of Message objects currently stored.
	size_t MessagePack::size() const {
		return n;
	}

	// Overloaded Output Operator: a non-friend helper function that inserts into os the contents of the MessagePack object. 
	std::ostream& operator<<(std::ostream& os, const MessagePack& pack) {
		if (pack.size()) {
			pack.display(os);
		}
		return os;
	}

}