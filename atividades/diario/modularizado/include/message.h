#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "time.h"
#include "date.h"

struct Message {
	Date date;
	Time time;
	std::string content;

	Message();
	Message(Date d, Time t, std::string c);
};

#endif