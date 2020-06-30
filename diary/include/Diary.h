#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <fstream>
#include <sstream>
#include "Date.h"
#include "Time.h"
#include "Message.h"

struct Diary {
	Diary(const std::string &filename);

	std::string filename;
	Message* messages;
	size_t messages_size;
	size_t messages_capacity;

	void add(const std::string &message);
	void add(const std::string &message, const Time time, const Date date);
	Message* search(const std::string pattern);
	int write();
	int load_messages();
	void check_capacity();

	~Diary();
};

#endif