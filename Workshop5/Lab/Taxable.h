/*
================================================================================================================
Name		: Taxable.h
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
Description: This header file provides the logic for the function object Taxable to assign the instance variables
			 and return a expression.
================================================================================================================
*/

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H



namespace sict {
	class Taxable {
		const float taxRate;
	public:
		// One Arguement Constructor : Receives parameter, sets to instance variable. 
		Taxable(float rec) : taxRate{ rec } {};

		// Overloaded Function Call Operator: Returns the taxed sum.
		float operator()(float rec) { return rec * (1+ taxRate); }
	};
}
#endif // !

