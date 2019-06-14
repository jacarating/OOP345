/*
================================================================================================================
Name		: Notifications.h
Author		: Jacob Carating
Email		: jacarating@myseneca.ca
Student #	: 157 725 177
Course Code : OOP345
Section		: SCC
Date		: June 9th, 2019
Workshop	: Workshop 4
================================================================================================================
*/
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict {
	class Notifications {
		const Message** ptrptr;
		int maxadd;
		size_t n;
	public:
		Notifications();
		Notifications(int maxele);
		Notifications(const Notifications& src);
		Notifications(Notifications&& src);
		Notifications& operator=(const Notifications& src);
		Notifications& operator=(Notifications&& src);
		~Notifications();
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, const Notifications& notif);
}

#endif