#include "Account.h"

Account::Account(){
    this->client_name = "";
    this->number = 0; // note: make it random
    this->balance = 0;
}

Account::Account(std::string client_name) : client_name(client_name){
    this->number = 0;
    this->balance = 0;
}

int Account::deposit(double value){
    this->balance += value;
    return 0;
}

int Account::withdraw(double value){
    if (this->balance < value){
        return 1;
    }
    this->balance -= value;
    return 0;
}

int Account::transfer(Account &destiny, double value){
    if (this->balance < value){
        return 1;
    }
    this->balance -= value;
    destiny.balance += value;
    return 0;
}

void Account::set_number(int new_number){
    this->number = new_number;
}

void Account::set_client_name(std::string name){
    this->client_name = name;
}

std::string Account::get_client_name(){
    return this->client_name;
}

int Account::get_number(){
    return this->number;
}

double Account::get_balance(){
    return this->balance;
}