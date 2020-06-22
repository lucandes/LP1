#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <ctime>
#include <fstream>
#include "time.h"
#include "message.h"

struct Diary {
	const std::string filename = "db.txt";
	const std::string action_list[] = {"add", "list"};

	void print_usage(const std::string &program_name);
	void list_messages(const std::string &filename);
	void add_message(void);
	std::string format_current_date(const std::string &format);
	Time get_current_date(void);
	Date get_current_time(void);
	bool check_last_date(std::ifstream &arquivo_entrada);
};

#endif