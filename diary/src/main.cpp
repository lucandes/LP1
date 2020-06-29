#include "App.h"
#include "Diary.h"
#define FILEMANE "db.md"


int main (int argc, char *argv[]){
	Diary my_diary(FILEMANE);

	for (int i = 0; i < 10; ++i){
		my_diary.add("MENSAGEM DE TESTE");
	}

	/* print messages */
	for (int i = 0; i < my_diary.messages_size; ++i){
		std::cout << '(' << my_diary.messages[i].date.to_string() << ") " 
		<< my_diary.messages[i].time.to_string() << " - " 
		<< my_diary.messages[i].content << std::endl;
	}

	my_diary.write();

	return 0;

	/*
	App aplicativo("db.txt");
	return aplicativo.run(argc, argv);
	*/
}