/*
================================================================================================================
Name		: Timekeeper.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 21, 2019
Workshop	: Workshop 2 - In Lab
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic to instatiate Timekeeper objects, record time (duration), and convert that time into seconds - as instructed.
================================================================================================================
*/

#include <iostream>
#include <chrono>
#include <iomanip>
#include "Timekeeper.h"

namespace sict
{

	void Timekeeper::start(){
		startTime = std::chrono::steady_clock::now(); // Assign startTime the current time.
	}

	void Timekeeper::stop(){
		endTime = std::chrono::steady_clock::now(); // Assign endTime the current time.
	}

	// Determines the length of time. Checks if there's space allocated in array, then stores the description of the record.
	void Timekeeper::recordEvent(const char *msg){
		auto ms = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime); // Create milisecond variable. Cast to miliseconds the evaluation.
		if (nr < MAX_RECORDS) {
			record[nr].msg = msg;  
			record[nr].units = " seconds";
			record[nr].duration = ms;
			nr++;
		}
	}

	// Prints the duration that it took to call each function to the output stream.
	void Timekeeper::report(std::ostream &os) const{
		os << "\nExecution Times:\n";
		for (int i = 0; i < nr; i++)
			os << record[i].msg << ' ' << std::setw(5)
			<< record[i].duration.count() / 1000000 // Convert to seconds.
			<< record[i].units
			<< std::endl;
	}

}