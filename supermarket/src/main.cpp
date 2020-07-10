#include <iostream>
#include <string>

#include "Store.hpp"
#include "Client.hpp"
#include "Product.hpp"
#include "Util.hpp"

int main(){
	char repeat;
	Store store("csv/estoque.csv", "csv/caixa.csv");

	/* new client loop*/
	do {
		std::cout << "SUPERMERCADO" << std::endl;
		std::cout << "\nInsira a quantia do cliente: R$ ";
		std::string temp;
		std::cin >> temp;
		
		int client_money = money_to_int(temp);
		Client client(client_money); 

		std::string product_code = "";

		/* product purchase loop */
		do {
			std::cout << "-------------------------------------------------\n"; 
			std::cout << "Saldo do cliente: " << int_to_money(client.get_money()) << std::endl << std::endl;

			/* ESTOQUE */
			if (product_code == "-1"){
				store.show_stock();
			}

			/* CAIXA */
			if (product_code == "-2"){
				store.show_caixa();
			}

			/* CARRINHO */
			if (product_code == "-3"){
				client.show_cart();
			}

			/* get product code */
			std::cout << "\nDigite  0 para FINALIZAR" << std::endl;
			std::cout << "Digite -1 para ESTOQUE" << std::endl;
			std::cout << "Digite -2 para CAIXA" << std::endl;
			std::cout << "Digite -3 para CARRINHO" << std::endl;

			std::cout << "\nCodigo do produto: ";
			std::cin >> product_code;

			std::cout << std::endl;

			if (product_code != "0"){
				/* if option show stock selected or other */
				if (product_code[0] == '-'){
					continue;
				}

				int product_index = store.find(product_code);
				/* if no product found with code */
				if (product_index == -1){
					std::cout << "Erro: nenhum produto encontrado com o codigo '" << product_code << "'\n";
					continue;
				}


				int quantity;
				std::cout << "Quantidade por medida: ";
				std::cin >> quantity;
				int avaliable_quantity = store.stock[product_index].quantity;

				/* Invalid input quantity */
				if (quantity == 0 || quantity > avaliable_quantity){
					std::cout << "Erro: quantidade invalida. Disponivel no estoque: " << avaliable_quantity << std::endl;
					continue;
				}


				int product_price = store.stock[product_index].price * quantity;
				/* Client can't pay for product */
				if (product_price > client.get_money()){
					std::cout << "Erro: o saldo do cliente é insuficiente. Preço: " << int_to_money(product_price) << ". Saldo: " << int_to_money(client.get_money()) << std::endl; 
					continue;
				}


				/* Succesful purchase */
				client.buy(store.stock[product_index], quantity);
				store.sell(product_index, quantity);

				Product product = store.stock[product_index];

				std::cout << std::endl << quantity << " " << product.measure << "(s) de "
				<< product.name << " adicionado ao carrinho" << std::endl;
			}
			/* End if */

			/* If client wants to finish */
			if (product_code == "0"){
				char finish;
				std::cout << "\n\nFinalizar compra? (S/N): ";
				std::cin >> finish;

				if (finish == 's' || finish == 'S'){
					product_code = "0";
				} else{
					product_code = "1";
				}
			}
		} while(product_code != "0");
		/* End product purchase loop */

		client.purchase_details();
		client.register_purchase();


		std::cout << "Novo cliente? (S/N): ";
		std::cin >> repeat;
	} while(repeat == 'S' || repeat == 's');
	/* End new client loop */

	return 0;
}