#include "partida.h"
#include <iostream>

bool Partida::setRodada(){
    rodada +=1;
    if(rodada == 5){
        rodada = 1;
    }
}

bool Partida::incrementarPontuacaoDupla(Dupla dupla, int pontos) {
    dupla.aumentarPontuacao(pontos);
}

bool Partida::verificarVencedor() const {
    return dupla1.getPontuacao() >= 12 || dupla2.getPontuacao() >= 12;
}

void Partida::imprimirParabens() const {
    if (dupla1.getPontuacao() >= 12) {
        std::cout << "Parabéns à Dupla " << dupla1.getNome() << " (" << dupla1.getPontuacao() << " pontos)!" << std::endl;
    } else if (dupla2.getPontuacao() >= 12) {
        std::cout << "Parabéns à Dupla " << dupla1.getNome() << " (" << dupla1.getPontuacao() << " pontos)!" << std::endl;
    }
}

void Partida::imprimirTrofeu() const {
    std::cout << "         .-=========-.\n"
                 "          \'-=======-'/\n"
                 "          _|   .=.   |_\n"
                 "         ((|  {{1}}  |))\n"
                 "          \\|   /|\\   |/\n"
                 "           \\__ '`' __/\n"
                 "             _`) (`_\n"
                 "           _/_______\\_\n"
                 "          /___________\\ " << std::endl;
}

void Partida::imprimirPartida() const {
    std::cout << "Partida:" << std::endl;
    std::cout << dupla1.getNome() << ": " << dupla1.getPontuacao() << " pontos" << std::endl;
    std::cout << dupla2.getNome() << ": " << dupla2.getPontuacao() << " pontos" << std::endl;
}