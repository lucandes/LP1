#include "../include/diary.h"

Diary::Diary(const std::string &filename) : filename(filename){
	load_messages(filename);
}

void Diary::add(const std::string &message){
}

void Diary::write(){
}

int Diary::load_messages(const std::string &filename){
}

