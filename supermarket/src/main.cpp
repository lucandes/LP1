#include <iostream>
#include <string>

#include "Store.hpp"
#include "Client.hpp"
#include "Product.hpp"

int main(){
	char repeat;
	Store store;
	do {
		Client client(50000); //R$ 500,00 

		std::string product_code;
		store.show_stock();
		do {
			std::cout << "-------------------------------------------------\n"; 
			if (product_code == "-1"){
				std::cout << "\n";
				store.show_stock();
			}
			std::cout << "\nType 0 to finish\nType -1 to show stock" << std::endl;
			std::cout << "\nProduct code: ";
			std::cin >> product_code;

			if (product_code != "0"){
				int product_index = store.find(product_code);

				if (product_index == -1){
					std::cout << "Error: no product found with code '"<< product_code << "'" << std::endl;
					continue;
				}

				int quantity;
				std::cout << "Product quantity: ";
				std::cin >> quantity;
				int avaliable_quantity = store.stock[product_index].quantity;

				if (quantity == 0 || quantity > avaliable_quantity){
					std::cout << "Error: invalid quantity. Avaliable on stock: " << avaliable_quantity << std::endl;
					continue;
				}

				int product_price = store.stock[product_index].price * quantity;
				if (product_price + client.get_cart_cost() > client.get_money()){
					/* MUDE ISSO DEPOIS */
					std::cout << "Error: CLIENTE POBRE" << std::endl; 
					continue;
				}


				client.buy(store.stock[product_index], quantity);
				store.sell(product_index, quantity);

				std::cout << std::endl << store.stock[product_index].name << " added to client's shopping cart\n";
				std::cout << "Client money: " << std::put_money(client.get_money()) << std::endl;
			}

			if (product_code == "0"){
				char finish;
				std::cout << "\n\nFinish purchase? (Y/N): ";
				std::cin >> finish;

				if (finish == 'n' || finish == 'N'){
					product_code = "1";
				} else{
					product_code = "0";
				}
			}
		} while(product_code != "0");

		/* PURCHASE DETAILS HERE */
		std::cout << "PURCHASE DETAILS" << std::endl;

		client.register_purchase();
		std::cout << "New client? (Y/N): ";
		std::cin >> repeat;
	} while(repeat == 'Y' || repeat == 'y');

	return 0;
}