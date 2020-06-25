#include "diary.h"

Diary::Diary(const std::string &filename) : filename(filename){
	messages_capacity = 10;
	messages = new Message[messages_capacity];
	messages_size = load_messages();
}

void Diary::add(const std::string &message){
	Date date = get_current_date();
	Time time = get_current_time();

	Message new_message(date, time, message);
	messages[messages_size] = new_message;
	messages_size++;
}

void Diary::write(){
}

int Diary::load_messages(){
	/* retorna a quantidade de mensagens que achou no arquivo ou 0 se não houver arquivo */
	return 0;
}

Diary::~Diary(){
	delete[] messages;
}