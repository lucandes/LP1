#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "time.h"

struct Message {
	Date date;
	Time time;
	std::string content;

	bool compare_messages(const Message &other_message);
	bool is_newer_than(const Message &other_message);
};

#endif