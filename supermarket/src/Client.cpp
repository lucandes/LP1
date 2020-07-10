#include "Client.hpp"

Client::Client(int money) : money(money), cart_cost(0){
}

int Client::get_money(){
	return this->money;
}

int Client::get_cart_cost(){
	return this->cart_cost;
}

void Client::buy(Product product, int quantity){
	/* if product already in cart, only its quantity will be changed */
	for (size_t i = 0; i < this->cart.size(); ++i){
		if (this->cart[i].code == product.code){
			this->money -= product.price * quantity;
			cart[i].quantity += quantity;
			return;
		}
	}

	
	this->money -= product.price * quantity;
	this->cart_cost += product.price * quantity;
	product.quantity = quantity;
	this->cart.push_back(product);
}

void Client::show_cart(){
	int total = 0;
	std::cout << "Carrinho de compras:" << std::endl;
	for (size_t i = 0; i < this->cart.size(); ++i){
		Product product = this->cart[i];

		std::cout << i + 1 << ". " << 
		product.name << " x" << 
		product.quantity << " - " 
		<< int_to_money(product.price) << std::endl;

		total += product.price * product.quantity;
	}
	std::cout << "Total: " << int_to_money(total) << std::endl;
}

void Client::register_purchase(){
	int client_number = 1;
	std::string filename = "csv/client_" + std::to_string(client_number) + ".csv";
	std::ifstream file_check(filename);
	while(file_check.is_open()){
		file_check.close();
		client_number++;
		filename = "csv/client_" + std::to_string(client_number) + ".csv";
		file_check.open(filename);
	}
	file_check.close();


	std::ofstream file(filename);
	file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE,TOTAL" << std::endl;

	for (size_t i = 0; i < this->cart.size(); ++i){
		Product product = this->cart[i];

		file << product.code << "," << product.name 
		<< "," << product.measure 
		<< ",\"" << int_to_money(product.price)
		<< "\"," << product.quantity;

		/* if first product line write TOTAL */
		if (i == 0){
			file << ",\"" << int_to_money(this->cart_cost) << "\"";
		}

		file << std::endl;
	}
	file.close();
}

void Client::purchase_details(){
	std::cout << "********************************************\n";
	std::cout << "Detalhes da compra:" << std::endl;
	for (int i = 0; i < this->cart.size(); ++i){
		Product product = this->cart[i];

		std::cout << i + 1 << ". " << product.name << " "
		<< int_to_money(product.price) << " x" << product.quantity << " = " 
		<< int_to_money(product.price * product.quantity) << std::endl;
	}
	std::cout << "\nTotal: " << int_to_money(this->cart_cost) << std::endl;

	std::cout << "********************************************\n\n\n\n";
}