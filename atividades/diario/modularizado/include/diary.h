#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <fstream>
#include <ctime>
#include "message.h"

struct Diary {
	Diary(const std::string &filename);

	std::string filename;
	Message* messages;
	size_t messages_size;
	size_t messages_capacity;

	void add(const std::string &message);
	void write();
	int load_messages();
	std::string get_current_time();
	std::string get_current_date(); // change it to return date and time struct

	~Diary();
};

#endif