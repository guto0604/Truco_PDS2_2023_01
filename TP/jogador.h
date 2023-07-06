#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>

#include "carta.h"
#include "baralho.h"

class Jogador {
private:
    int numero;
    std::string nome;
    std::vector<Carta> cartas;

public:
    Jogador();
    void setNumero(int numero);
    void setNome(const std::string& nome);
    int getNumero() const;
    std::string getNome() const;
    void receberCartas(Baralho baralho, int jogada);

};

#endif
