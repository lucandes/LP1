#include <iostream>
#include <iomanip>

#include "Account.h"
#include "Agency.h"

void print_account(Account a);

int main(int argc, char* argv[]){

    std::cout << std::setprecision(2) << std::fixed; //iomanip

    Agency caixa("Caixa Econômica", 1617);
    Agency bradesco("Bradesco", 8956);
    Agency nubank("Nubank", 4957);

    Client joao("João Silva", "265.457.654-88");
    Client marcelo("Marcelo Pereira", "456.987.642-74");
    Client carlos("Carlos", "564.987.258-74");

    Account conta_joao(joao, caixa);
    conta_joao.deposit(1000.00);
    
    Account conta_marcelo(marcelo, bradesco);
    conta_marcelo.deposit(2000.53);

    Account conta_carlos(carlos, nubank);
    conta_carlos.deposit(200.10);

    print_account(conta_marcelo);
    print_account(conta_joao);

    double transfer_value = 400.50;
    std::cout << std::endl << "Transferindo $ " << transfer_value << " de Marcelo para João" << std::endl << std::endl; 
    if (conta_marcelo.transfer(conta_joao, transfer_value) == 1){
        std::cout << "Erro: valor transferido maior que saldo disponível." << std::endl;
        exit(1);
    }

    print_account(conta_marcelo);
    print_account(conta_joao);

    std::cout << "\nNumero de contas criadas: " << conta_joao.get_accounts_counter() << std::endl;

    return 0;
}

void print_account(Account a){
    std::cout << std::endl << "******************************************" << std::endl;
    std::cout << "Agency: " << a.agency.get_name() << ", " << a.agency.get_number() << std::endl;
    std::cout << "Client: " << a.client.get_name() << ", " << a.client.get_cpf() << std::endl;
    std::cout << "Account: " << a.get_number() << std::endl;
    std::cout << "Balance: $ " << a.get_balance() << std::endl;
}