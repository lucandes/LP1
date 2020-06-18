#include <iostream>
#include <string>
#include <fstream>

void print_usage(const std::string &progname);
int list_file(const std::string filename);

int main(int argc, char *argv[]){
	if (argc == 1){
		print_usage(argv[0]);
		return 1;
	}

	std::string action = argv[1];
	std::string msg;
	std::string const filename = "diary.txt";
	if (argc == 2){
		if (action == "list"){
			return list_file(filename);
		}
		if (action == "add"){
			std::cout << "Insira a mensagem: ";
			std::getline(std::cin, msg);
		}
		else {
			print_usage(argv[0]);
			return 1;
		}
	}

	else {
		if (action == "add"){
			msg = std::string(argv[2]);
		}
		else {
			print_usage(argv[0]);
			return 1;
		}
	}

	std::ofstream arquivo_saida(filename, std::ios::app);
	if (arquivo_saida.is_open()){
		arquivo_saida << msg << std::endl;
		arquivo_saida.close();
		std::cout << "Mensagem Adicionada" << std::endl;
	}
	else {
		std::cerr << "Erro: arquivo não pode ser aberto." << std::endl;
		return 1;
	}

	return 0;
}


void print_usage(const std::string &progname){
	std::cout << "Uso: " << progname << " add <mensagem>" << std::endl;
}

int list_file(const std::string filename){
	std::ifstream arquivo_entrada(filename, std::ios::in);
	if (arquivo_entrada.fail()){
		std::cerr << "Erro: não foi possível abrir o arquivo de mensagens." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(arquivo_entrada, line)){
		std::cout << line << std::endl;
	}
	arquivo_entrada.close();
}