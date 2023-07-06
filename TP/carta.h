
#ifndef CARTA_H
#define CARTA_H

#include "jogador.h"

#include <string>
#include <sstream>

class Carta{
public:
    Carta(int numero, std::string naipe);
    void entregarCarta(Jogador jogador);
    int getValor();
    std::string getCarta();
    bool jogada();

private:

    int numero;
    std::string naipe;
    int valor;
    Jogador jogador;
    bool ja_jogada;

};

#endif
