/*
================================================================================================================
Name		: Timekeeper.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 21, 2019
Workshop	: Workshop 2 - In Lab
================================================================================================================
*/
#pragma once

#include <iostream>
#include <chrono>

namespace sict
{

	

	class Timekeeper {
		int nr{ 0 };
		static const int MAX_RECORDS = 10;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct {
			const char* msg; // string containing a message
			const char* units; // string containing predefines units of time
			std::chrono::steady_clock::duration duration; // duration variable of type duration.
		} record[MAX_RECORDS]; 

	public:
		Timekeeper() {}
		void start(); // a modifier that starts the stopwatch for an event
		void stop(); // a modifier that stops the stopwatch for an event
		void recordEvent(const char*); // a modifier that receives the address of a C-style null terminated string that holds the description of the event 
		void report(std::ostream&) const;
	};


}