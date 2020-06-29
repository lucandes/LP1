#include "Date.h"

Date::Date() : day(0), month(0), year(0)
{}

Date::Date(unsigned d, unsigned m, unsigned y) : day(d), month(m), year(y)
{}

bool Date::compare(const Date date){
	if (day == date.day && month == date.month && year == date.year){
		return true;
	}
	return false;
}

std::string Date::to_string(){
	std::stringstream stream;
	day < 10 ? stream << '0' << day : stream << day;
	stream << '/';
	month < 10 ? stream << '0' << month : stream << month;
	stream << '/';
	stream << year;

	return stream.str();
}

Date date_from_string(const std::string date){
	std::stringstream stream;
	stream << date;

	unsigned day;
	unsigned month;
	unsigned year;
	char discard;

	stream >> day;
	stream >> discard;
	stream >> month;
	stream >> discard;
	stream >> year;

	Date new_date(day, month, year);
	return new_date;
}

Date get_current_date(){
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), "%d/%m/%Y", std::localtime(&time));

	std::stringstream stream(result);
	char discard;
	Date current_date;
	stream >> current_date.day;
	stream >> discard;
	stream >> current_date.month;
	stream >> discard;
	stream >> current_date.year;

	return current_date;
}

