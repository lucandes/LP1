#include "Store.hpp"

Store::Store(std::string stock_file, std::string caixa_file) : stock_file(stock_file), caixa_file(caixa_file), total_gain(0){
	this->load_stock();
	this->load_caixa();
}

void Store::show_stock(){
	std::cout << "Estoque disponível:" << std::endl;
	for (size_t i = 0; i < this->stock.size(); ++i){
		Product product = this->stock[i];

		if (product.quantity == 0){
			continue;
		}
		
		std::cout << product.code << " - " 
		<< product.name << " x" << product.quantity 
		<< " : " << int_to_money(product.price) 
		<< " por " << product.measure << std::endl;
	}
}

void Store::show_caixa(){
	std::cout << "Registro do caixa:" << std::endl;
	for (size_t i = 0; i < this->sold.size(); ++i){
		Product product = this->sold[i];

		std::cout << product.code << " - " 
		<< product.name << " x" << product.quantity 
		<< " : " << int_to_money(product.price) << std::endl;
	}
	std::cout << "TOTAL: " << int_to_money(this->total_gain) << std::endl;
}

void Store::sell(int index, int quantity){
	this->stock[index].quantity -= quantity;

	Product product = this->stock[index];

	/* if product was already sold */
	for (int i = 0; i < this->sold.size(); ++i){
		if (product.code == this->sold[i].code){
			this->total_gain += product.price * quantity;
			this->sold[i].quantity += quantity;
			return;
		}
	}

	product.quantity = quantity;
	this->sold.push_back(product);
	this->total_gain += product.price * quantity;
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
	std::ifstream file(this->stock_file);
	if (file.fail()){
		std::cout << "Erro: falha ao abrir arquivo de estoque" << std::endl;
		return;
	}

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

		int index = 0;
		int char_counter = 0;

		/* read quantity */
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
	std::ofstream file(this->stock_file);
	file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

	for (size_t i = 0; i < this->stock.size(); ++i){
		Product product = this->stock[i];

		file << i + 1 << "," << product.name 
		<< "," << product.measure 
		<< ",\"" << int_to_money(product.price)
		<< "\"," << product.quantity << std::endl;
	}
	file.close();
}

void Store::load_caixa(){
	std::ifstream file(this->caixa_file);
	if (file.fail()){
		return;
	}

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

		int index = 0;
		int char_counter = 0;

		/* read total */
		if (line_counter == 1){
			for (int i = line.length() - 1; i > 0; --i){
				char_counter++;
				if (line[i] == '"' && i != line.length() - 1){
					index = i;
					break;
				}
			}
			this->total_gain = money_to_int(line.substr(index));
			line.resize(line.length() - (char_counter + 1));
			line_counter++;
		}	

		Product new_product;

		//std::cout << line << std::endl;

		/* read quantity */
		char_counter = 0;
		for (int i = line.length() - 1; i > 0; --i){
			char_counter++;
			if (line[i] == ','){
				index = i;
				break;
			}
		}
		new_product.quantity = std::stoi(line.substr(index + 1));
		line.resize(line.length() - (char_counter));

		//std::cout << line << std::endl;

		/* read price */
		char_counter = 0;
		for (int i = line.length() - 1; i > 0; --i){
			char_counter++;
			if (line[i] == '"' && i != line.length() - 1){
				index = i;
				break;
			}
		}
		new_product.price = money_to_int(line.substr(index));
		line.resize(line.length() - (char_counter + 1));

		//std::cout << line << std::endl;

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

		//std::cout << line << std::endl;

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

		//std::cout << line << std::endl;

		/* read code */
		new_product.code = line;
		this->sold.push_back(new_product);
	}
}

void Store::register_caixa(){
	std::ofstream file(this->caixa_file);
	file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE,TOTAL" << std::endl;

	for (size_t i = 0; i < this->sold.size(); ++i){
		Product product = this->sold[i];

		file << product.code << "," << product.name 
		<< "," << product.measure 
		<< ",\"" << int_to_money(product.price)
		<< "\"," << product.quantity;

		if (i == 0){
			file << ",\"" << int_to_money(this->total_gain) << "\"";
		}

		file << std::endl;
	}
	file.close();
}

Store::~Store(){
	register_stock();
	register_caixa();

}