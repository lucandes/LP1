#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Product.hpp"

class Client{
private:
	int money;
	int cart_cost;
	std::vector<Product> cart;

public:
	Client(int money);
	int get_money();
	int get_cart_cost();
	
	void buy(Product product, int quantity);
	void show_cart();
	void register_purchase();
};

#endif