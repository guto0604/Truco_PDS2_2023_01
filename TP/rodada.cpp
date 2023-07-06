#include "rodada.h"
#include <iostream>

Rodada::Rodada(int rodada, Jogador mao, Partida partida){
    this->rodada = rodada;
    Jogador mao;
    this->mao.copy(mao);
    this->partida = partida;
    resultado = false;
    definirOrdem();
}

bool Rodada::getResultado(){
    return resultado;
}

Jogador Rodada::getVencedor(){
    return vencedor;
}

void Rodada::definirOrdem(){
    int n = mao.getNumero();
    for (int i = 0; i < 4; i++){
        if(n == 4){
            n = 0;
        }
        ordem[i] = partida.getJogador(n);
        n += 1;
    }
}

Jogador Rodada::jogar(){
    for(int i = 0; i < ordem.size(); i++){
        cartas[i] = ordem[i].jogarCarta();
        std::cout << cartas[i].getCarta();
    }
    if(definirVencedor == 0){
        return mao;
    }
    else{
        return vencedor;
    }
}

int Rodada::definirVencedor(){
    Carta maior = cartas[0];
    int j = 0;
    int n = 1;
    for(int i = 1; i < cartas.size(); i++){
        if(cartas[i].getValor() > maior.getValor()){
            maior = cartas[i];
            j = i;
            n = 1;
        }
        else if(cartas[i].getValor() == maior.getValor()){
            n += 1;
            j = 0;
        }
    }
    if(j != 0){
        vencedor = ordem[j];
        resultado = true;
    }
    return j;
}
