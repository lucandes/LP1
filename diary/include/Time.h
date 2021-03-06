#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

struct Time {
	unsigned hour;
	unsigned minute;
	unsigned second;

	Time();
	Time(unsigned h, unsigned m, unsigned s);
	std::string to_string();
};

Time time_from_string(const std::string time);
Time get_current_time();

#endif