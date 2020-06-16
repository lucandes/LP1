#include <iostream>
#include <string>

int main(int argc, char *argv[]){
	std::string msg;
	if (argc == 1 || std::string(argv[1]) != "add"){
		std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
		return 1;
	}
	if (argc == 2 && std::string(argv[1]) == "add"){
		std::cout << "Insira a mensagem: ";
		std::getline(std::cin, msg);
	}

	std::cout << "Mensagem Adicionada" << std::endl;
	return 0;
}
