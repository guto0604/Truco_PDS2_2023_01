#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include <iostream>

#include "carta.h"
#include "baralho.h"

class Jogador {
private:
    int numero;
    std::string nome;
    int dupla;
    std::vector<Carta> cartas;

public:
    Jogador();
    Jogador(int numero, std::string nome, int dupla);
    void copy(Jogador j);
    int getNumero() const;
    std::string getNome() const;
    int getDupla() const;
    void receberCartas(Baralho baralho, int jogada);
    Carta jogarCarta();

};

#endif
