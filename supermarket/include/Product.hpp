#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product{
public:
	std::string name;
	std::string code;
	std::string measure;
	int price;
	int quantity;

	Product();
	Product(std::string name, std::string code, std::string measure, double price, int quantity);
	std::string get_price_formated();
};

#endif
