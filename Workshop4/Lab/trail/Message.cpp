#include "Message.h"
using namespace std;

namespace sict {
	Message::Message(const std::string& str) {
		size_t userNameEnd = str.find(' '); // Username is right before the first space.
		size_t endOfStr = str.npos; // Represents end of string. Nothing found.
		size_t replyStart = str.find('@');

		if (userNameEnd != endOfStr && !str.empty()) { // If its not just a username, or the string is not empty.
			userName = str.substr(0, userNameEnd);

			if (replyStart != endOfStr) { // Reply was found.
				size_t replyUserEnd = str.find(' ', replyStart); // Find end of reply username.

				replyName = str.substr(replyStart + 1, replyUserEnd - replyStart - 1);

				tweet = str.substr(replyUserEnd + 1);
			}
			else {
				tweet = str.substr(userNameEnd + 1);
			}
		}
		else
			*this = Message();
	}


	bool Message::empty() const {
		return userName == "" || tweet == "";
	}


	void Message::display(std::ostream& os) const {
		if (!empty()) {
			os << ">User  : " << userName << endl;

			if (replyName != "") {
				os << " Reply : " << replyName << endl;
			}

			os << " Tweet : " << tweet << endl;
		}

	}
}