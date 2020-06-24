#include "../include/app.h"


int main (int argc, char *argv[]){
	App aplicativo("db.txt");
	return aplicativo.run(argc, argv);
}