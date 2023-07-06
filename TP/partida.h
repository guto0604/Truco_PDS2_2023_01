#ifndef PLACAR_H
#define PLACAR_H

#include "dupla.h"
#include "jogador.h"
#include "mao.h"

#include <string>
#include <vector>

class Partida {
private:
    std::vector<Jogador> jogadores;
    std::vector<Dupla> dupla;
    int rodada;

public:
    Partida(std::vector<Jogador> jogadores);
    Partida(const std::string& nomeDupla1, const std::string& nomeDupla2);
    Dupla getDupla(int i);
    bool setRodada();
    void iniciarMao();
    bool incrementarPontuacaoDupla(Dupla dupla, int pontos);
    bool verificarVencedor() const;
    void imprimirParabens() const;
    void imprimirTrofeu() const;
    void imprimirPartida() const;
    Jogador getJogador(int jogador);

    void iniciarPartida();
};

#endif
