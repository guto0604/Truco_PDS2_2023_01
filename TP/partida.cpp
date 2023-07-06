#include "partida.h"
#include <iostream>

Partida::Partida(std::vector<Jogador> jogadores){
    Dupla duplas();
    for(int i = 0; i<jogadores.size(); i++){
        this->jogadores.copy(jogadores[i]);
    }
    dupla[0](jogadores[0], jogadores[2]);
    dupla[1](jogadores[1], jogadores[3]);
    rodada = 0;
}

bool Partida::setRodada(){
    rodada +=1;
    if(rodada == 4){
        rodada = 0;
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


void Partida::iniciarPartida(){
    while(true){
        Mao mao(jogadores[rodada], this);
        mao.comecar_mao();
        if(mao.getVencedor() != nullptr){
            mao.fim_mao();
        }
        if(verificarVencedor){
            imprimirParabens();
            imprimirTrofeu();
            imprimirPartida();
            break;
        }
        setRodada();
    }
}