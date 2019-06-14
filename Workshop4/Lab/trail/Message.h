#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <iostream>
#include <string>
namespace sict {

	class Message {
		std::string userName;
		std::string replyName;
		std::string tweet;
	public:
		Message() : userName{ "" }, replyName{ "" }, tweet{ "" }{};
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};


}
#endif // !SICT_MESSAGE_H
