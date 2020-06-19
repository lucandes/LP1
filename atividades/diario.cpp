#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

void print_usage(const std::string &progname);
int list_file(const std::string filename);
int add_message(const std::string filename, std::string message);
std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();
bool check_last_date(std::ifstream &arquivo_entrada);


int main(int argc, char *argv[]){
	if (argc == 1){
		print_usage(argv[0]);
		return 1;
	}

	std::string actionList[] = {"add", "list"};
	std::string action = argv[1];
	std::string message;
	std::string const filename = "db.txt";

	/* action add */
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

	/* action list */
	if (!action.compare(actionList[1]) && argc == 2){
		return list_file(filename);
	}
	
	/* no action match */
	print_usage(argv[0]);
	return 1;
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
		if (line[0] == '#' || line.length() == 0)
			continue;
		if (line[0] == '-'){
			std::cout << "- " << line.substr(11, line.length()) << std::endl;
			continue;
		}
		std::cout << "- " << line << std::endl;
	}
	arquivo_entrada.close();

	return 0;
}


int add_message(const std::string filename, std::string message){
	/* tive problemas com o fstream então separei a entrada e a saida */

	/* leitura do arquivo */
	std::ifstream arquivo_entrada(filename);
	bool newDate;
	if (arquivo_entrada.fail()) 
		newDate = true;
	else
		newDate = check_last_date(arquivo_entrada);
	arquivo_entrada.close();

	/* escrita do arquivo */
	std::ofstream arquivo_saida(filename, std::ios::app);
	if (arquivo_saida.fail()){
		std::cerr << "Erro: arquivo não pode ser aberto." << std::endl;
		return 1;
	}
	if (newDate){
		arquivo_saida << std::endl << "#" << get_current_date() << std::endl << std::endl;
	}
	arquivo_saida << "- "<< get_current_time() << " " << message << std::endl;
	arquivo_saida.close();
	std::cout << "Mensagem Adicionada" << std::endl;
	return 0;
}


std::string format_current_date(const std::string &format){
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

	return std::string(result);
}

std::string get_current_date(){
	return format_current_date("%d/%m/%Y");
}

std::string get_current_time(){
	return format_current_date("%H:%M:%S");
}

bool check_last_date(std::ifstream &arquivo_entrada){
	std::string line;
	std::string current_date_formated = '#' + get_current_date();
	while(std::getline(arquivo_entrada, line)){
		if (!line.compare(current_date_formated)) 
			return false;
	}
	return true;
}