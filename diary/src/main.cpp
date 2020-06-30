#include "App.h"


int main (int argc, char *argv[]){
	const std::string filename = "db.md";
	App aplicativo(filename);
	return aplicativo.run(argc, argv);
}