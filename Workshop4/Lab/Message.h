/*
================================================================================================================
Name		: Message.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: June 5th, 2019
Workshop	: Workshop 4
================================================================================================================
*/


#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <iostream>
#include <string>

namespace sict {
	class Message {
		std::string user;
		std::string reply;
		std::string tweet;
	public:
		Message() : user{ "" }, reply{ "" }, tweet{ "" } {};
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}
#endif