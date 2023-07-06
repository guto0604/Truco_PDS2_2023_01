#ifndef RODADA_H
#define RODADA_H

#include "jogador.h"
#include "baralho.h"

#include <string>
#include <vector>

class Rodada {
private:
    Baralho baralho;
    std::vector<Jogador> ordem;

public:
    void darCartas();
    
};

#endif

