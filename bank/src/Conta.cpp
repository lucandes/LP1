#include "Conta.hpp"

size_t Conta::contas_counter = 0;


Conta::Conta(Cliente new_cliente, Agencia new_agencia) : cliente(new_cliente), agencia(new_agencia), balance(0){
    /* get a random conta number using Agencia number */
    srand((unsigned) this->agencia.get_number());
    int temp_number = 1000000 + (rand() % 9999999);
    this->number = std::to_string(temp_number);

    this->contas_counter += 1;
}

int Conta::deposit(double value){
    this->balance += value;
    return 0;
}

int Conta::withdraw(double value){
    if (this->balance < value){
        return 1;
    }
    this->balance -= value;
    return 0;
}

int Conta::transfer(Conta &destiny, double value){
    if (this->balance < value){
        return 1;
    }
    this->balance -= value;
    destiny.balance += value;
    return 0;
}

void Conta::set_number(std::string new_number){
    this->number = new_number;
}

void Conta::set_Cliente_name(std::string name){
    this->cliente.set_name(name);
}

std::string Conta::get_Cliente_name(){
    return this->cliente.get_name();
}

std::string Conta::get_number(){
    return this->number;
}

double Conta::get_balance(){
    return this->balance;
}

size_t Conta::get_Contas_counter(){
    return this->contas_counter;
}