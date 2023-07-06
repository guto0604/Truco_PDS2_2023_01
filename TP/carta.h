
#ifndef CARTA_H
#define CARTA_H

#include "jogador.h"

#include <string>
#include <sstream>

class Carta{
public:
    Carta(int numero, std::string naipe);
    

private:

    int numero;
    std::string naipe;
    int valor;
    Jogador jogador;

};

#endif
