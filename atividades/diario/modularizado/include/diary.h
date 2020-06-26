#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <fstream>
#include <sstream>
#include "date.h"
#include "time.h"
#include "message.h"

struct Diary {
	Diary(const std::string &filename);

	std::string filename;
	Message* messages;
	size_t messages_size;
	size_t messages_capacity;

	void add(const std::string &message);
	void add(const std::string &message, const Time time, const Date date);
	int write();
	int load_messages();

	~Diary();
};

#endif