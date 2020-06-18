#include <iostream>
#include <string>
#include <fstream>

void print_usage(const std::string &progname);
int list_file(const std::string filename);
int add_message(const std::string filename, std::string message);

int main(int argc, char *argv[]){
	if (argc == 1){
		print_usage(argv[0]);
		return 1;
	}

	std::string actionList[] = {"add", "list"};
	std::string action = argv[1];
	std::string message;
	std::string const filename = "diary.txt";
	
	if (!action.compare(actionList[0]) && argc <= 3){
		if (argc == 2){
			std::cout << "Insira a mensagem: ";
			std::getline(std::cin, message);
		}
		else {
			message = std::string(argv[2]);
		}
		return add_message(filename, message);
	}
	if (!action.compare(actionList[1]) && argc == 2){
		return list_file(filename);
	}
	else {
		print_usage(argv[0]);
		return 1;
	}

	return 0;
}


void print_usage(const std::string &progname){
	std::cout << "Uso: " << progname << " <comando>" << std::endl;
	std::cout << "Comandos:\n- add  (nova mensagem)\n- list (listar mensagens)\n";
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

	return 0;
}

int add_message(const std::string filename, std::string message){
	std::ofstream arquivo_saida(filename, std::ios::app);
	if (arquivo_saida.fail()){
		std::cerr << "Erro: arquivo não pode ser aberto." << std::endl;
		return 1;
	}

	arquivo_saida << message << std::endl;
	arquivo_saida.close();
	std::cout << "Mensagem Adicionada" << std::endl;
	return 0;
}
