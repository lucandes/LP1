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
	Diary(const std::string config_path);

	std::string db_path;
	std::vector<Message> messages;
	std::string default_format;

	void read_conf(const std::string conf_path);
	void add(const std::string &message);
	void add(const std::string &message, const Time time, const Date date);
	std::vector<Message*> search(const std::string pattern);
	void write();
	void load_messages();
};

#endif