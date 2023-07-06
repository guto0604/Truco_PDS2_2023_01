
#ifndef PARTIDA_H
#define PARTIDA_H

#include "jogador.h"

#include <string>
#include <sstream>

class Dupla{
public:
    int getPontuacao() const;
    bool aumentarPontuacao(int pontos);
    
    bool setNome(std::string nome);
    std::string getNome() const;
    

private:
    Dupla(Jogador j1, Jogador j2);
    Dupla(std::string nome, Jogador j1, Jogador j2);

    std::pair<Jogador, Jogador> dupla;
    int pontuacao;
    std::string nome;


};

#endif
