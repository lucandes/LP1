#ifndef Conta_H
#define Conta_H

#include "Cliente.hpp"
#include "Agencia.hpp"

#include <string>
#include <ctime>

class Conta{
    private:
        std::string number;
        double balance;
        size_t static contas_counter;
    
    public:
        Cliente cliente;
        Agencia agencia;
        
        Conta(Cliente new_cliente, Agencia new_agencia);
        int deposit(double value);
        int withdraw(double value);
        int transfer(Conta &destiny, double value);

        /* setters & getters */
        void set_number(std::string new_number);
        void set_Cliente_name(std::string name);
        std::string get_Cliente_name();
        std::string get_number();
        double get_balance();
        size_t get_Contas_counter();
};


#endif