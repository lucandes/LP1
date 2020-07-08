#include <iostream>
#include "carro.hpp"

using namespace std;

int main(){
    Carro c;
    c.tipo = "Sedan";
    c.numPortas = 4;
    c.placa = "XYZ-0102";

    cout << "Tipo do carro: " << c.tipo << endl;
    cout << "Quantidade de portas: " << c.numPortas << endl;
    cout << "Placa do carro: " << c.placa << endl;
    cout << "A cor do carro é: " << c.cor << endl;
    c.ligaCarro();
    c.acelera(50);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
    c.freia (20);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;

    cout << endl << endl << endl; 

    Carro a("Vermelho");
    a.tipo = "Pajero";
    a.numPortas = 4;
    a.placa = "KQZ-1022";

    cout << "Tipo do carro: " << a.tipo << endl;
    cout << "Quantidade de portas: " << a.numPortas << endl;
    cout << "Placa do carro: " << a.placa << endl;
    cout << "A cor do carro é: " << a.cor << endl;
    a.ligaCarro();
    a.acelera(70);
    cout << "A velocidade atual é: " << a.velocidade << "KM/H" << endl;
    a.freia (10);
    cout << "A velocidade atual é: " << a.velocidade << "KM/H" << endl;

    cout << endl << endl << "Quantidade de carros: " << a.obj_counter << endl;
    
    return 0;
}