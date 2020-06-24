#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "time.h"
#include "date.h"

struct Message {
	Date date;
	Time time;
	std::string content;

	Message(const std::string &new_message, const Time &current_time, const Date &current_date);
};

#endif