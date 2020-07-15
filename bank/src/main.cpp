#include <iostream>
#include <iomanip>

#include "Conta.hpp"
#include "Cliente.hpp"
#include "ClientePJ.hpp"
#include "Agencia.hpp"
#include "Fila.hpp"
#include "Fila.cpp"

void print_Conta(Conta a);

int main(int argc, char* argv[]){

    std::cout << std::setprecision(2) << std::fixed; //iomanip

    Agencia caixa("Caixa Econômica", 1617);
    Agencia bradesco("Bradesco", 8956);
    Agencia nubank("Nubank", 4957);

    Cliente joao("João PF", "265.457.654-88");
    Cliente marcelo("Marcelo PF", "456.987.642-74");
    Cliente carlos("Carlos PF", "564.987.258-74");

    Fila<Cliente> clientes(10);
    clientes.push(joao);
    std::cout << "Ultimo na fila PF: ";
    std::cout << clientes.back().get_name() << std::endl;
    clientes.push(marcelo);
    std::cout << "Ultimo na fila PF: ";
    std::cout << clientes.back().get_name() << std::endl;
    clientes.push(carlos);
    std::cout << "Ultimo na fila PF: ";
    std::cout << clientes.back().get_name() << std::endl;

    ClientePJ joana("Joana PJ", "74.895.654/6755-77");
    ClientePJ maria("Maria PJ", "32.005.124/2354-12");
    ClientePJ vitoria("Vitoria PJ", "65.425.689/4578-87");

    Fila<ClientePJ> clientesPJ(10);
    clientesPJ.push(joana);
    std::cout << "\nUltimo na fila PJ: ";
    std::cout << clientesPJ.back().get_razao_social() << std::endl;
    clientesPJ.push(maria);
    std::cout << "Ultimo na fila PJ: ";
    std::cout << clientesPJ.back().get_razao_social() << std::endl;
    clientesPJ.push(vitoria);
    std::cout << "Ultimo na fila PJ: ";
    std::cout << clientesPJ.back().get_razao_social() << std::endl;

    std::cout << "\nResize clientePJ to 2\n";
    clientesPJ.resize(2);
    std::cout << "Ultimo na fila PJ: ";
    std::cout << clientesPJ.back().get_razao_social() << std::endl;    

    return 0;
}

void print_Conta(Conta a){
    std::cout << std::endl << "******************************************" << std::endl;
    std::cout << "Agencia: " << a.agencia.get_name() << ", " << a.agencia.get_number() << std::endl;
    std::cout << "Cliente: " << a.cliente.get_name() << ", " << a.cliente.get_cpf() << std::endl;
    std::cout << "Conta: " << a.get_number() << std::endl;
    std::cout << "Balance: $ " << a.get_balance() << std::endl;
}