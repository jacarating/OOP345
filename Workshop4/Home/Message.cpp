/*
================================================================================================================
Name		: Message.cpp
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code 	: OOP345
Section		: SCC
Date		: June 5th, 2019
Workshop	: Workshop 4
================================================================================================================
*/

/*
================================================================================================================
Description: This implmentation file provides the logic to identify a user, the recipient and the message.
			 With the identification methods defines below, this file is able to display their content depending 
			 on their identifier. 
================================================================================================================
*/

#include <iostream>
#include <string>
#include "Message.h"

namespace sict {
	Message::Message(const std::string& str) {
		size_t none = std::string::npos;
		size_t reply_s = str.find('@');
		size_t space = str.find(' ');
		
		//if there is a space in the string, there is a username and tweet
		if (space != none && !str.empty()) {
			//space can be used to figure out the length of the username and passed as the second argument of .substr
			//copy the length of the username from first index
			user = str.substr(0, space);
			
			//if @ is found, then reply exists
			if (reply_s != none) {

				//search for space after the reply
				size_t nextspace = str.find(' ', reply_s);

				//copy string after the @ sign for number of characters between nextspace and @ sign
				reply = str.substr(reply_s + 1, nextspace - 1 - reply_s);

				//copy tweet in between nextspace to end
				tweet = str.substr(nextspace + 1);
			}
			else { //if no reply, then copy the tweet
				//copy string in between first found space and end
				tweet = str.substr(space + 1);
			}
		}
		else { //if there is no space in the line, there is no useful info, so set to empty state
			*this = Message();
		}
	}

	bool Message::empty() const {
		bool isempty = false;
		if (user == "") {
			isempty = true;
		}
		return isempty;
	}

	void Message::display(std::ostream& os) const {
		if (user != "") {
			os << ">User  : " << user << std::endl;
			if (reply != "") {
				os << " Reply : " << reply << std::endl;
			}
			os << " Tweet : " << tweet << std::endl;
		}
	}
}