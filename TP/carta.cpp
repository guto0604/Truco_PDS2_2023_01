#include "carta.h"

Carta::Carta(int numero, std::string naipe){
    this->numero = numero;
    this->naipe = naipe;
    
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
