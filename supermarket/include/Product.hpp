#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product{
public:
	std::string name;
	std::string code;
	std::string measure;
	double price;
	int quantity;

	Product();
	Product(std::string name, std::string code, std::string measure, double price, int quantity);
};

#endif
