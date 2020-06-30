#include "App.h"

App::App(const std::string &filename): diary(filename)
{}

int App::run(int argc, char* argv[]){
	if (argc == 1)
		return show_usage(argv[0]);

	std::string action = argv[1];
	check_action(action, argc, argv);
}

int App::check_action(const std::string &action, int argc, char* argv[]){
	if (action == "add"){
		if (argc == 2){
			add();
		} else {
			add(argv[2]);
		}
	}

	else if (action == "list"){
		list_messages();
	}

	else if (action == "search"){
		if (argc == 2){
			search();
		} else {
			search(argv[2]);
		}
	}

	else {
		return show_usage(argv[0]);
	}

	return 0;
}

void App::add(){
	std::string new_message;
	std::cout << "Enter a new message: ";
	std::getline(std::cin, new_message);

	add(new_message);
}


void App::add(const std::string &message){
	diary.add(message);
	diary.write();
}

void App::search(){
	std::string pattern;
	std::cout << "Enter a pattern to search: ";
	std::getline(std::cin, pattern);
	search(pattern);
}
void App::search(const std::string pattern){
	Message *found;
	found = diary.search(pattern);
	if (found == nullptr){
		std::cout << "No results for \"" << pattern << "\"." << std::endl;
		return;
	}

	std::cout << "Message found: \n" << found->date.to_string() << " " << found->time.to_string()
	<< " \"" << found->content << '"' << std::endl;
}

void App::list_messages(){
	for (size_t i = 0; i < diary.messages_size; ++i){
		const Message &message = diary.messages[i];
		std::cout << "- " << message.content << std::endl;
	}
}

int App::show_usage(const std::string &program_name){
	std::cout << "Usage: " << program_name << " <action>" << std::endl;
	std::cout << "Commands:\n- add  (new message)\n- list (list messages)\n- search (search for a message)\n";
	return 1;
}