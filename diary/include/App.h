#ifndef APP_H
#define APP_H

#include "Diary.h"
#include "Message.h"

#include <string>
#include <iostream>
#include <vector>

struct App {
	Diary diary;
	std::string config_path;

	App(const std::string config_path);
	int run(int argc, char *argv[]);
	int check_action(const std::string &action, int argc, char *argv[]);
	void add();
	void add(const std::string &message);
	void search();
	void search(const std::string pattern);
	void list_messages(std::string format);
	void interactive();
	int show_usage(const std::string &program_name);
};

#endif 