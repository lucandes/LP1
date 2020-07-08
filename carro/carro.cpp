#include "carro.hpp"

size_t Carro::obj_counter = 0;

Carro::Carro(string cor){
    this->cor = cor;
    this->obj_counter++;
}

Carro::Carro(){
    this->cor = "Branco";
    this->obj_counter++;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}