#include "Store.hpp"

Store::Store(){
	this->load_stock();
}

void Store::show_stock(){
	std::cout << "Avaliable Stock:" << std::endl;
	for (size_t i = 0; i < this->stock.size(); ++i){
		Product product = this->stock[i];

		std::cout << product.code << " - " << 
		product.name << " x" << 
		product.quantity << " : " 
		<< std::put_money(product.price) << " for " <<
		product.measure << std::endl;
	}
}

void Store::sell(int index, int quantity){
	this->stock[index].quantity -= quantity;
}

void Store::show_log(){
	/* dunno */
}

int  Store::find(std::string code){
	for (size_t i = 0; i < this->stock.size(); ++i){
		if (this->stock[i].code == code){
			return i;
		}
	}

	return -1;
}

void Store::load_stock(){
	std::ifstream file("csv/estoque.csv");
	if (file.fail()){
		return;
	}

	

	std::stringstream stream;
	std::string line;
	
	int line_counter = 0;
	while(std::getline(file, line)){
		if (line.length() == 0){
			continue;
		}

		if (line_counter == 0){
			line_counter++;
			continue;
		}

		/* this will read every value from the end 
		of the line to the start by cutting the string */

		Product new_product;

		int index;
		int char_counter = 0;

		/* read quatity */
		for (int i = line.length() - 1; i > 0; --i){
			char_counter++;
			if (line[i] == ','){
				index = i;
				break;
			}
		}
		new_product.quantity = std::stoi(line.substr(index + 1));
		line.resize(line.length() - (char_counter));

		/* read price */
		char_counter = 0;
		for (int i = line.length() - 1; i > 0; --i){
			char_counter++;
			if (line[i] == ' '){
				index = i;
				break;
			}
		}
		std::string temp = line.substr(index + 1);
		temp.replace(temp.find(","), 1, "");
		new_product.price = std::stoi(temp);
		line.resize(line.length() - (char_counter + 4));



		/* read measurement unity */
		char_counter = 0;
		for (int i = line.length() - 1; i > 0; --i){
			char_counter++;
			if (line[i] == ','){
				index = i;
				break;
			}
		}
		new_product.measure = line.substr(index + 1);
		line.resize(line.length() - (char_counter));

		/* read name */
		char_counter = 0;
		for (int i = line.length() - 1; i > 0; --i){
			char_counter++;
			if (line[i] == ','){
				index = i;
				break;
			}
		}
		new_product.name = line.substr(index + 1);
		line.resize(line.length() - (char_counter));



		/* read code */
		new_product.code = line;
		this->stock.push_back(new_product);
	}
}

void Store::register_stock(){
	std::string filename = "csv/estoque.csv";

	std::ofstream file(filename);
	file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

	for (size_t i = 0; i < this->stock.size(); ++i){
		Product product = this->stock[i];

		file << i + 1 << "," << product.name 
		<< "," << product.measure 
		<< ",\"" << std::put_money(product.price)
		<< "\"," << product.quantity << std::endl;
	}
	file.close();
}

Store::~Store(){
	register_stock();

}