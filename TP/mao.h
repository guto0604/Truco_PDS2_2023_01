
#ifndef MAO_H
#define MAO_H

#include "jogador.h"
#include "baralho.h"

#include<vector>

class Mao {
private:
    Baralho baralho;
    std::vector<Jogador> ordem;

public:
    Mao(Jogador pe);
    void darCartas();
    void definirOrdem();

};

#endif

