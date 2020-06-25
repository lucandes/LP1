#include "app.h"
#include "diary.h"


int main (int argc, char *argv[]){
	Diary my_diary("db.txt");

	for (int i = 0; i < my_diary.messages_capacity; ++i){
		my_diary.add("MENSAGEM DE TESTE");
	}

	/* print messages */
	for (int i = 0; i < my_diary.messages_capacity; ++i){
		std::cout << '(' << my_diary.messages[i].date.to_string() << ") " 
		<< my_diary.messages[i].time.to_string() << " - " 
		<< my_diary.messages[i].content << std::endl;
	}

	return 0;

	/*
	App aplicativo("db.txt");
	return aplicativo.run(argc, argv);
	*/
}