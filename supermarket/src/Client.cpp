#include "Client.hpp"

Client::Client(int money) : money(money), cart_cost(0){
	std::cout.imbue(std::locale("pt_BR.UTF-8")); // to write inf format R$ x.xxx,xx
	std::cout << std::showbase;
}

int Client::get_money(){
	return this->money;
}

int Client::get_cart_cost(){
	return this->cart_cost;
}

void Client::buy(Product product, int quantity){
	for (size_t i = 0; i < cart.size(); ++i){
		if (cart[i].code == product.code)
			this->money -= product.price * quantity;
			cart[i].quantity += quantity;
			return;
	}

	product.quantity = quantity;
	this->money -= product.price * quantity;
	this->cart.push_back(product);
}

void Client::show_cart(){
	int total = 0;
	std::cout << "Shopping Cart:" << std::endl;
	for (size_t i = 0; i < this->cart.size(); ++i){
		Product product = this->cart[i];

		std::cout << i + 1 << ". " << 
		product.name << " x" << 
		product.quantity << " - " 
		<< std::put_money(product.price) << std::endl;

		total += product.price;
	}
	std::cout << "Total: " << std::put_money(total) << std::endl;
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
	file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

	for (size_t i = 0; i < this->cart.size(); ++i){
		Product product = this->cart[i];

		file << i + 1 << "," << product.name 
		<< "," << product.measure 
		<< ",\"" << std::put_money(product.price)
		<< "\"," << product.quantity << std::endl;
	}
	file.close();
}