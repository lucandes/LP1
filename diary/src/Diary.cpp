#include "Diary.h"
#include <iostream>

Diary::Diary(const std::string &filename) : filename(filename)
{
	load_messages();
}

void Diary::add(const std::string &message){
	Date date = get_current_date();
	Time time = get_current_time();

	add(message, time, date);
}

void Diary::add(const std::string &message, const Time time, const Date date){
	Message new_message(date, time, message);
	messages.push_back(new_message);
	std::cout << "Mensagem adicionada: " << new_message.content << std::endl;
}

std::vector<Message*> Diary::search(const std::string pattern){
	std::vector<Message*> found_messages;
	for (auto it : messages){
		if (it.content.find(pattern) != std::string::npos){
			found_messages.push_back(&it);
		}
	}
	return found_messages;
}

void Diary::write(){
	std::ofstream arquivo_saida(filename);
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

void Diary::load_messages(){
	std::ifstream arquivo_entrada(filename);
	if (arquivo_entrada.fail())
		return;

	bool has_date = false;
	Date message_date;
	std::string line;
	std::stringstream stream;
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