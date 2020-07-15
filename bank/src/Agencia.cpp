#include "Agencia.hpp"

Agencia::Agencia() : name(""), number(0)
{}

Agencia::Agencia(std::string new_name, int new_number) : name(new_name), number(new_number)
{}

void Agencia::set_name(std::string new_name){
    this->name = new_name;
}

void Agencia::set_number(int new_number){
    this->number = new_number;
}

std::string Agencia::get_name(){
    return this->name;
}

int Agencia::get_number(){
    return this->number;
}