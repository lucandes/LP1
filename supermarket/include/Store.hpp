#ifndef STORE_HPP
#define STORE_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "Product.hpp"
#include "Util.hpp"

class Store{
public:
	std::vector<Product> stock;
	std::vector<Product> sold;
	int total_gain;
	std::string	stock_file;
	std::string caixa_file;

	Store(std::string stock_file, std::string caixa_file);
	~Store();
	void show_stock();
	void show_caixa();
	void sell(int index, int quantity);
	int  find(std::string code);
	void load_stock();
	void register_stock();
	void load_caixa();
	void register_caixa();
};

#endif