
#ifndef MAO_H
#define MAO_H

#include "jogador.h"
#include "baralho.h"
#include "partida.h"
#include "dupla.h"
#include "rodada.h"

#include<vector>
#include<map>

class Mao {
private:
    Baralho baralho;
    Jogador embaralhou;
    Partida partida;
    std::vector<Jogador> ordem;
    std::map<int, int> rodadasVencidas;
    int rodada;
    int pontuacaoAlvo; //Numero de rodadas a serem venciadas para a mão ser ganha;
    int pontuacao;
    bool truco;
    bool seis;
    bool nove;
    bool doze;

public:
    Mao(Jogador embaralhou, Partida partida);
    void darCartas();
    void definirOrdemInicial();
    void pedir_truco();
    void pedir_seis();
    void pedir_nove();
    void pedir_doze();
    Dupla comecar_mao();
    void fim_mao(Dupla vencedor);

};

#endif

