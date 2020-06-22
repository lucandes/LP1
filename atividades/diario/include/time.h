#ifndef TIME_H
#define TIME_H

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Time {
	unsigned short hour;
	unsigned short minutes;
	unsigned short seconds;
};

#endif