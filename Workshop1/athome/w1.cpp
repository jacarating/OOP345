/*
================================================================================================================
Name		: w1.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: May 16, 2019
Workshop	: Workshop 1 - In Lab
================================================================================================================
*/

/*
================================================================================================================
Description: The main function will receive a set of command line arguments that will be echoed to standard output
				by the specified format. Arguments will then be listed and numbered starting from MAX value.
				The main fuction wil also check for invalid parameters and handle errors accordingly.
================================================================================================================
*/


#include "process.h"
#include "String.h"

using namespace sict;

const int INITIAL = 3; // Used for external linkage with String.cpp. Declaration can have keyword extern, however compiler ignores the keyword when initalization is present.

	int main(int argc, char *argv[]) {  
		bool flag{ false }; // Becomes true if error found.

		// Call functions to print arguments within for loop
		// Display error if needed
		


		if (argc < 1) { // Check for invalid input. If valid print to screen, otherwise output error message.
			flag = true;
			std::cout << "***Insufficient number of arguments***" << std::endl;
		}
		else {
			std::cout << "Command Line : ";

			for (int i = 0; i < argc; i++) { // Echoes the set of arguments to standard output separated by a single space on one line.
				std::cout << argv[i] << " ";
			}

			// After printed arguments, we need to end line.

			std::cout << std::endl;

			// Call process function for each string. 
			for (int i = 1; i < argc; i++) {
				process(argv[i]); // Creates String object for each argument to process output.
			}
		}



		return flag == true ? 1 : 0; 
	}

	
