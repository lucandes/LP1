#include "Account.h"

Account::Account() : client(), agency(), number("0"), balance(0){
}

Account::Account(Client new_client, Agency new_agency) : client(new_client), agency(new_agency), balance(0){
    /* get a random account number using agency number */
    srand((unsigned) this->agency.get_number());
    int temp_number = 1000000 + (rand() % 9999999);
    this->number = std::to_string(temp_number);
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

void Account::set_number(std::string new_number){
    this->number = new_number;
}

void Account::set_client_name(std::string name){
    this->client.set_name(name);
}

std::string Account::get_client_name(){
    return this->client.get_name();
}

std::string Account::get_number(){
    return this->number;
}

double Account::get_balance(){
    return this->balance;
}