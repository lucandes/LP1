#ifndef STORE_HPP
#define STORE_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "Product.hpp"

class Store{
public:
	std::vector<Product> stock;

	Store();
	~Store();
	void show_stock();
	void sell(int index, int quantity);
	void show_log();
	int find(std::string code);
	void load_stock();
	void register_stock();
};

#endif