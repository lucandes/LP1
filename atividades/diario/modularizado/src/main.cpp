#include "../include/app.h"
#include "../include/diary.h"


int main (int argc, char *argv[]){
	Diary my_diary("db.txt");

	for (int i = 0; i < my_diary.messages_capacity; ++i){
		my_diary.add("Mensagem teste");
	}

	return 0;

	/*
	App aplicativo("db.txt");
	return aplicativo.run(argc, argv);
	*/
}