#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

struct Date {
	unsigned day;
	unsigned month;
	unsigned year;

	Date();
	Date(unsigned d, unsigned m, unsigned y);
	std::string to_string();
	bool compare(const Date date);
};

Date date_from_string(const std::string date);
Date get_current_date();

#endif