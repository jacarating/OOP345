/*
================================================================================================================
Name		: MessagePack.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: June 9th, 2019
Workshop	: Workshop 4
================================================================================================================
*/


#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <iostream>
#include "Message.h"

namespace sict {

	class MessagePack {
		Message* msgptr;
		size_t n;
	public:
		MessagePack() : msgptr{ nullptr }, n{ 0 } {};
		MessagePack(Message** ptr, int n);
		MessagePack(const MessagePack& src);
		MessagePack(MessagePack&& src);
		MessagePack& operator=(const MessagePack& src);
		MessagePack& operator=(MessagePack&& src);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, const MessagePack& pack);
}

#endif
