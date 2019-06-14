/*
================================================================================================================
Name		: Timekeeper.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 21, 2019
Workshop	: Workshop 2
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic to instatiate Timekeeper objects, record time (duration), and convert that time into seconds - as instructed.
================================================================================================================
*/

#include <iostream>
#include <chrono>
#include <cstring>
#include "Timekeeper.h"
using namespace std;

namespace sict
{
	// Default Constructor: Sets object to a safe state.
	Timekeeper::Timekeeper() {
		nr = 0;
		for (int i = 0; i < MAX_RECORDS; i++) {
			record[i].msg = nullptr;
			record[i].units = nullptr;
		}
	}
	void Timekeeper::start() {
		startTime = std::chrono::steady_clock::now(); // Assign startTime the current time.
	}

	void Timekeeper::stop() {
		endTime = std::chrono::steady_clock::now(); // Assign endTime the current time.
	}

	// Determines the length of time. Checks if there's space allocated in array, then stores the description of the record.
	void Timekeeper::recordEvent(const char *msg) {
		if (nr < MAX_RECORDS) {
			record[nr].msg = msg;
			record[nr].units = " seconds";
			record[nr].duration = (endTime - startTime);
			nr++;
		}
	}

	// Prints the duration that it took to call each function to the output stream.
	void Timekeeper::report(std::ostream &os) const {
		os << "\nExecution Times:" << std::endl;
		for (int i = 0; i < nr; i++) {
			os << record[i].msg << " ";
			os.width(4);
			os << chrono::duration_cast<chrono::milliseconds>(record[i].duration).count() << " " << record[i].units << endl;
		}

	}

}