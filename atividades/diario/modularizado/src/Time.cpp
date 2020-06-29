#include "Time.h"

Time::Time() : hour(0), minute(0), second(0)
{}

Time::Time(unsigned h, unsigned m, unsigned s) : hour(h), minute(m), second(s)
{}

std::string Time::to_string(){
	std::stringstream stream;
	hour < 10 ? stream <<  '0' << hour : stream <<  hour;
	stream << ':';
	minute < 10 ? stream << '0' << minute : stream << minute;
	stream << ':';
	second < 10 ? stream << '0' << second : stream << second;

	return stream.str();
}

Time time_from_string(const std::string time){
	std::stringstream stream;
	stream << time;

	unsigned hour;
	unsigned minute;
	unsigned second;
	char discard;

	stream >> hour;
	stream >> discard;
	stream >> minute;
	stream >> discard;
	stream >> second;

	Time new_time(hour, minute, second);
	return new_time;
}

Time get_current_time(){
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), "%H:%M:%S", std::localtime(&time));

	std::stringstream stream(result);

	char discard;
	Time current_time;
	stream >> current_time.hour;
	stream >> discard;
	stream >> current_time.minute;
	stream >> discard;
	stream >> current_time.second;

	return current_time;
}

