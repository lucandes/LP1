#include "Product.hpp"

Product::Product() : name(""), code(""), measure(""), price(0), quantity(0)
{} 

Product::Product(std::string name, std::string code, std::string measure, double price, int quantity)
: name(name), code(code), measure(measure), price(price), quantity(quantity)
{}