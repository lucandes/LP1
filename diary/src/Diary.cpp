#include "Diary.h"

Diary::Diary(const std::string &filename) : filename(filename){
	messages_capacity = 10;
	messages = new Message[messages_capacity];
	messages_size = load_messages();
}

void Diary::add(const std::string &message){
	Date date = get_current_date();
	Time time = get_current_time();

	add(message, time, date);
}

void Diary::add(const std::string &message, const Time time, const Date date){
	check_capacity();
	Message new_message(date, time, message);
	messages[messages_size] = new_message;
	messages_size++;
}

Message* Diary::search(const std::string pattern){
	for (size_t i = 0; i < messages_size; ++i){
		if (messages[i].content.find(pattern) != std::string::npos)
			return &messages[i];
	}
	return nullptr;
}

int Diary::write(){
	std::ofstream arquivo_saida(filename);
	if (arquivo_saida.fail())
		return 1;

	Date current_date;
	for (size_t i = 0; i < messages_size; ++i){
		if (messages[i].date.compare(current_date) == false){
			arquivo_saida << std::endl << '#' << messages[i].date.to_string() << std::endl << std::endl;
			current_date = messages[i].date;	
		}

		arquivo_saida << "- " << messages[i].time.to_string() << ' ' << messages[i].content << std::endl;
	}
}

int Diary::load_messages(){
	std::ifstream arquivo_entrada(filename);
	if (arquivo_entrada.fail())
		return 0;

	bool has_date = false;
	Date message_date;
	std::string line;
	std::stringstream stream;
	int message_count = 0;
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
			message_count++;
		}
	}
	return message_count;
}

void Diary::check_capacity(){
	if (messages_size == messages_capacity){
		messages_capacity += 10;
		Message *temp_messages = new Message[messages_capacity];
		for (size_t i = 0; i < messages_size; ++i){
			temp_messages[i] = messages[i];
		}
		delete[] messages;
		messages = temp_messages;
	}
}

Diary::~Diary(){
	delete[] messages;
}