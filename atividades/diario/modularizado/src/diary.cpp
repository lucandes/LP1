#include "../include/diary.h"

Diary::Diary(const std::string &filename) : filename(filename){
	messages_capacity = 10;
	messages = new Message[messages_capacity];
	messages_size = load_messages();
}

void Diary::add(const std::string &message){
	Message new_message;
	new_message.content = message;
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