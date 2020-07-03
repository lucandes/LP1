#include "App.h"

/* constructor */
App::App(const std::string config_path) : diary(config_path)
{}

/* control the program execution */
int App::run(int argc, char* argv[]){
	if (argc == 1)
		return show_usage(argv[0]);

	std::string action = argv[1];
	check_action(action, argc, argv);
}

/* interprete the input action */ 
int App::check_action(const std::string &action, int argc, char* argv[]){
	if (action == "add"){
		if (argc == 2){
			add();
		} else {
			add(argv[2]);
		}
	}

	else if (action == "list"){
		if (argc == 2){
			list_messages(diary.default_format);
		} else {
			list_messages(argv[2]);
		}
	}

	else if (action == "search"){
		if (argc == 2){
			search();
		} else {
			search(argv[2]);
		}
	}

	else if (action == "interactive"){
		interactive();
	}

	else {
		return show_usage(argv[0]);
	}

	return 0;
}

/* add message from cin */
void App::add(){
	std::string new_message;
	std::cout << "Enter a new message: ";
	std::getline(std::cin, new_message);

	add(new_message);
}

/* add message from command line (argv) */
void App::add(const std::string &message){
	diary.add(message);
	diary.write();
}

/* send a pattern to diary's search function from cin */
void App::search(){
	std::string pattern;
	std::cout << "Enter a pattern to search: ";
	std::getline(std::cin, pattern);
	search(pattern);
}

/* send a pattern to diary's search function from command line */
void App::search(const std::string pattern){
	std::vector<Message*> found_messages;
	found_messages = diary.search(pattern);

	if (found_messages.empty()){
		std::cout << "No results for \"" << pattern << "\"." << std::endl;
		return;
	}

	std::cout << "Messages found: " << found_messages.size() << std::endl << std::endl;
	for (auto it : found_messages){
		std::cout << it->date.to_string() << 
		" at " << it->time.to_string() << 
		" \"" << it->content << "\"\n";
	}
}

/* print a list with all messages */
void App::list_messages(std::string format){
	if (format.find("%d") == std::string::npos &&
		format.find("%t") == std::string::npos &&
		format.find("%m") == std::string::npos){
		std::cout << "Error: invalid output format" << std::endl;
		exit(1);
	}

	for (auto it : diary.messages){
		std::string output = format;
		if (output.find("%d") != std::string::npos){
			output.replace(output.find("%d"), 2, it.date.to_string());
		}
		if (output.find("%t") != std::string::npos){
			output.replace(output.find("%t"), 2, it.time.to_string());
		}
		if (output.find("%m") != std::string::npos){
			output.replace(output.find("%m"), 2, it.content);
		}
		std::cout << output << std::endl;
	}
}

/* display an interactive menu */
void App::interactive(){
	std::cout << "Diary 1.0\n\n";

	while (true){
		std::cout << "Choose the action:\n\n";
		std::cout << "1) List messages" << std::endl;
		std::cout << "2) Add new message" << std::endl;
		std::cout << "3) Search message" << std::endl << std::endl;
		std::cout << "0) End" << std::endl << std::endl;
		std::cout << "> ";
		int action;
		std::cin >> action;

		if (action == 0){
			std::cout << "Exiting..." << std::endl;
			return;
		}
		if (action == 1){
			list_messages(diary.default_format);
			return;
		}
		if (action == 2){
			std::cin.ignore();
			add();
			return;
		}
		if (action == 3){
			std::cin.ignore();
			search();
			return;
		}

		std::cout << "Enter a valid value" << std::endl << std::endl;
	}
}

/* show the program's command list */
int App::show_usage(const std::string &program_name){
	std::cout << "Usage: " << program_name << " <command>" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "- add  <new message>   Record a message" << std::endl;
	std::cout << "- list <format>        List all messages" << std::endl;
	std::cout << "- search <pattern>     Search for a message" << std::endl;
	std::cout << "- interactive          Shows an interactive menu" << std::endl;
	return 1;
}