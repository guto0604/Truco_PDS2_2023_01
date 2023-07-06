#ifndef PLACAR_H
#define PLACAR_H

#include <string>
#include "dupla.h"
#include "jogador.h"

class Partida {
private:
    Dupla dupla1;
    Dupla dupla2;
    int rodada;

public:
    Partida();
    Partida(const std::string& nomeDupla1, const std::string& nomeDupla2);
    bool setRodada();
    bool Partida::incrementarPontuacaoDupla(Dupla dupla, int pontos);
    bool verificarVencedor() const;
    void imprimirParabens() const;
    void imprimirTrofeu() const;
    void imprimirPartida() const;
    
};

#endif
