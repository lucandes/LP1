#include <iostream>
#include <iomanip>
#include "Account.h"

int main(int argc, char* argv[]){

    std::cout << std::setprecision(2) << std::fixed; //iomanip

    Account conta1("Marcelo Oliveira");
    conta1.deposit(1000.00);
    std::cout << conta1.get_client_name() << ": $ " << conta1.get_balance() << std::endl;
    
    Account conta2("João Silva");
    conta2.deposit(2000.53);
    std::cout << conta2.get_client_name() << ": $ " << conta2.get_balance() << std::endl;

    double transfer_value = 400.50;
    std::cout << std::endl << "Transferindo $ " << transfer_value << " de Marcelo para João" << std::endl << std::endl; 
    if (conta1.transfer(conta2, transfer_value) == 1){
        std::cout << "Erro: valor transferido maior que saldo disponível." << std::endl;
        exit(1);
    }

    std::cout << conta1.get_client_name() << ": $ " << conta1.get_balance() << std::endl;
    std::cout << conta2.get_client_name() << ": $ " << conta2.get_balance() << std::endl;

    return 0;
}