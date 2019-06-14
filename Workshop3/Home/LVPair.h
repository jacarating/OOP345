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
#include <string>


namespace sict {

	template<typename L, typename V>
	class LVPair {
	protected:
		L iLabel;
		V iValue;
	public:

		// Default Constructor: Sets object to safe state.
		LVPair() : iLabel{0}, iValue{0} {}

		// Two Argument Constructor: Initializes instance variables to the received parameters.
		LVPair(const L& label, const V& value) : iLabel{ label }, iValue{ value } {};

		// Query: Display objects' content in specified format.
		virtual void display(std::ostream& os) const { os << iLabel << " : " << iValue << std::endl; };
	};

	// Non-Friend Helper Function: inserts into os the received LVPair object.
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) { 
		pair.display(os); 
		return os; 
	};


	// SummableLVPair Class Declaration
	template<typename L, typename V> 
	class SummableLVPair : public LVPair<L, V> {
		static V initial;
		static size_t min;
	public:

		// Default Constructor
		SummableLVPair() {};

		// Two Argument Constructor: Receives two unmodifiable objects and increases the size of the minimum field width for display if neccessary.
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (min < label.size()) {
				min = label.size();
			}
		};

		// Class Function: Returns initial value of summation.
		static const V& getInitialValue() { return initial; };

	
		V sum(const L& label, const V& sum) const;

		// Query: Sets the specified format as per instructed.
		void display(std::ostream& os) const {
			os.setf(std::ios::left); // Sets os to the left.
			os.width(min); // Set width
			LVPair<L, V>::display(os); 
		}
	};

	// Query: Return sum of current object and partially accumulated sum.
	template<typename L, typename V>
	V SummableLVPair<L, V>::sum(const L& label, const V& sum) const {
		//create a temporary variable of V type assign to same value as the sum
		V temp = sum;

		//if "label" is the same as the iLabel data member from the LVPair,
		if (this->iLabel.compare(label) == 0) {

			//add the iValue of current object to the existing sum parameter
			temp = this->iValue + sum;
		}

		//return the new summed value of the temporary object
		return temp;
	}

	// Template Declaration: Initializes the field width class variable to 0
	template <typename L,typename V>	
	size_t SummableLVPair<L, V>::min = 0u;

	// Template Specialization: Initializes the starting value for an LVPair<std::string, int> type to 0.
	template <>
	int SummableLVPair<std::string, int>::initial = 0;

	// Template Specialization: Initializes the starting value for an LVPair<std::string, std::string> type to 0.
	template <>
	std::string SummableLVPair<std::string, std::string>::initial = "";

	// Template Specialization: For LVPair<std::string, std::string> types that inserts a single space between concatenating strings. 
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {
		std::string temp = sum;
		if (iLabel.compare(label) == 0) {

			//display the old sum first, with a space in between, then append the new "iValue" to the string
			temp = sum + ' ' + iValue;
		}
		return temp;
	}

}
#endif // !SICT_LVPAIR_H


