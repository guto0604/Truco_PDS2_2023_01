#include "carta.h"

Carta::Carta(int numero, std::string naipe){
    this->numero = numero;
    this->naipe = naipe;
    ja_jogada = false;
    
    if(numero >= 4 & numero < 10){
        valor = numero - 3;
    }
    else{
        valor = numero + 7;
    }

    if(numero == 4 & naipe == "paus"){
        valor = 14;
    } else if(numero == 7 & naipe == "copas"){
        valor = 13;
    } else if(numero == 1 & naipe == "espadas"){
        valor = 12;
    } else if(numero == 7 & naipe == "ouros"){
        valor = 11;
    }

}

void Carta::entregarCarta(Jogador jogador){
    this->jogador = jogador;
}

int Carta::getValor(){
    return valor;
}
    
std::string Carta::getCarta(){
    std::ostringstream texto;
    texto << numero << " de " << naipe;
    return texto.str();
}

bool Carta::jogada(){
    return ja_jogada;
}
