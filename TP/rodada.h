#ifndef RODADA_H
#define RODADA_H

#include "partida.h"
#include "jogador.h"
#include "baralho.h"
#include "carta.h"

#include <string>
#include <vector>

class Rodada {
private:
    int rodada;
    Jogador mao;
    Partida partida;
    std::vector<Carta> cartas;
    std::vector<Jogador> ordem;
    bool resultado; //true se houve vencedor, false se houve empate
    Jogador vencedor;
    int definirVencedor();

public:
    Rodada(int rodada, Jogador mao, Partida partida);
    bool getResultado();
    void definirOrdem();
    Jogador getVencedor();
    Jogador jogar();

};

#endif

