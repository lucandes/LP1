#include "App.h"


int main (int argc, char *argv[]){
	const std::string config_path = "./diary.config";
	App aplicativo(config_path);
	return aplicativo.run(argc, argv);
}