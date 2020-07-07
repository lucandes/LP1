#include "Client.h"

Client::Client() : name(""), cpf("")
{}

Client::Client(std::string new_name) : name(new_name), cpf("")
{}

Client::Client(std::string new_name, std::string new_cpf) : name(new_name), cpf(new_cpf)
{}

void Client::set_name(std::string new_name){
    this->name = new_name;
}

void Client::set_cpf(std::string new_cpf){
    this->cpf = new_cpf;
}

std::string Client::get_name(){
    return this->name;
}

std::string Client::get_cpf(){
    return this->cpf;
}