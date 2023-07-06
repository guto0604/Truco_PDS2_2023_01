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
    for(int i = 0; i < dupla.size(); i++){
        if (dupla[i].getPontuacao() >= 12) {
            return true;
        }
    }
    return false;
}

void Partida::imprimirParabens() const {
    for(int i = 0; i < dupla.size(); i++){
        if (dupla[i].getPontuacao() >= 12) {
            std::cout << "Parabéns à Dupla " << dupla[i].getNome() << " (" << dupla[i].getPontuacao() << " pontos)!" << std::endl;
            break;
        }
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
    for(int i = 0; i < dupla.size(); i++){
        std::cout << dupla[i].getNome() << ": " << dupla[i].getPontuacao() << " pontos" << std::endl;
    }
}

Jogador Partida::getJogador(int jogador){
    return jogadores[jogador];
}

Dupla Partida::getDupla(int i){
    return dupla[i];
}
