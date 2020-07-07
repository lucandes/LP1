#include "Agency.h"

Agency::Agency() : name(""), number(0)
{}

Agency::Agency(std::string new_name, int new_number) : name(new_name), number(new_number)
{}

void Agency::set_name(std::string new_name){
    this->name = new_name;
}

void Agency::set_number(int new_number){
    this->number = new_number;
}

std::string Agency::get_name(){
    return this->name;
}

int Agency::get_number(){
    return this->number;
}