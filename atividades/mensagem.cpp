#include <iostream>
#include <string>
#include <fstream>

void print_usage(const std::string &filename);

int main(int argc, char *argv[]){
	if (argc == 1){
		print_usage(argv[0]);
		return 1;
	}

	std::string action = std::string(argv[1]);
	if (action != "add"){
		print_usage(argv[0]);
		return 1;
	}

	std::string msg;
	if (argc == 2){
		std::cout << "Insira a mensagem: ";
		std::getline(std::cin, msg);
	}

	else if (argc > 2){
		msg = std::string(argv[2]);
	}

	std::ofstream arquivo_saida("log.txt", std::ios::app);
	arquivo_saida << msg << std::endl;
	arquivo_saida.close();

	std::cout << "Mensagem Adicionada" << std::endl;
	return 0;
}


void print_usage(const std::string &filename){
	std::cout << "Uso: " << filename << " add <mensagem>" << std::endl;
}