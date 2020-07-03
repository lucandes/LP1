#include "Diary.h"

/* constructor */
Diary::Diary(const std::string config_path){
	read_conf(config_path);
	load_messages();
}

/* read the configuration file */
void Diary::read_conf(const std::string config_path){
	std::ifstream arquivo_entrada(config_path);

	if (arquivo_entrada.fail()){
		std::ofstream arquivo_saida(config_path);
		if (arquivo_saida.fail()){
			exit(1);
		}

		arquivo_saida << "path=diary.md" << std::endl << "default_format=%d %t: %m" << std::endl;
		arquivo_saida.close();
		arquivo_entrada.open(config_path);
	}

	std::string line;
	while (std::getline(arquivo_entrada, line)){
		if (line.find("path") == 0){
			db_path = line.substr(5);
			continue;
		}
		if (line.find("default_format") == 0){
			default_format = line.substr(15);
			continue;
		}
	}
}

/* Adds a message with current time and date */
void Diary::add(const std::string &message){
	Date date = get_current_date();
	Time time = get_current_time();

	add(message, time, date);
}

/* Adds a message with defined time and date */
void Diary::add(const std::string &message, const Time time, const Date date){
	Message new_message(date, time, message);
	messages.push_back(new_message);
}

/* Searches for a message that matches the pattern */
std::vector<Message*> Diary::search(const std::string pattern){
	std::vector<Message*> found_messages;

	for (size_t i = 0; i < messages.size(); ++i){
		if (messages[i].content.find(pattern) != std::string::npos){
			found_messages.push_back(&messages[i]);
		}
	}
	return found_messages;
}

/* Write all messages into the .md file */
void Diary::write(){
	std::ofstream arquivo_saida(db_path);
	if (arquivo_saida.fail())
		return;

	Date current_date;
	for (auto it : messages){
		if (it.date.compare(current_date) == false){
			arquivo_saida << std::endl << '#' << it.date.to_string() << std::endl;
			current_date = it.date;	
		}

		arquivo_saida << "- " << it.time.to_string() << ' ' << it.content << std::endl;
	}
}

/* Read all messages from the .md file */
void Diary::load_messages(){
	std::ifstream arquivo_entrada(db_path);
	if (arquivo_entrada.fail())
		return;

	bool has_date = false;
	Date message_date;
	std::string line;
	while(std::getline(arquivo_entrada, line)){
		if (line.length() == 0)
			continue;

		if (line[0] == '#'){
			message_date = date_from_string(line.substr(1, 10));
			has_date = true;
			continue;
		}

		if (line[0] == '-'){
			if (has_date == false)
				message_date = get_current_date();

			Time message_time = time_from_string(line.substr(2, 8));
			std::string message_content = line.substr(11);

			add(message_content, message_time, message_date);
		}
	}
}