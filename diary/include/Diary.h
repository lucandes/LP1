#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "Date.h"
#include "Time.h"
#include "Message.h"

struct Diary {
	Diary(const std::string &filename);

	std::string filename;
	std::vector<Message> messages;

	void add(const std::string &message);
	void add(const std::string &message, const Time time, const Date date);
	std::vector<Message*> search(const std::string pattern);
	void write();
	void load_messages();
};

#endif