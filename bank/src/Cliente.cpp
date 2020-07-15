#include "Cliente.hpp"

Cliente::Cliente() : name(""), cpf("")
{}

Cliente::Cliente(std::string new_name) : name(new_name), cpf("")
{}

Cliente::Cliente(std::string new_name, std::string new_cpf) : name(new_name), cpf(new_cpf)
{}

void Cliente::set_name(std::string new_name){
    this->name = new_name;
}

void Cliente::set_cpf(std::string new_cpf){
    this->cpf = new_cpf;
}

std::string Cliente::get_name(){
    return this->name;
}

std::string Cliente::get_cpf(){
    return this->cpf;
}