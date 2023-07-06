#include "mao.h"
#include <iostream>

Mao::Mao(Jogador embaralhou, Partida partida){
    Baralho baralho();
    Jogador embaralhou();
    this->partida = partida;
    this->embaralhou.copy(embaralhou);
    rodada = 1;
    for(int i = 0; i < 1; i++){
        rodadasVencidas[i] = 0;
    }
    pontuacaoAlvo = 2;
    pontuacao = 2;
    truco = false;
    seis = false;
    nove = false;
    doze = false;
    definirOrdemInicial();
    darCartas();
}

void Mao::definirOrdemInicial(){
    int n = embaralhou.getNumero() + 1;
    for (int i = 0; i < 4; i++){
        if(n == 4){
            n = 0;
        }
        ordem[i] = partida.getJogador(n);
        n += 1;
    }
    
}

void Mao::darCartas(){
    baralho.embaralhar();
    for(int j = 0; j < 4; j++){
        ordem[j].receberCartas(baralho, j);
    }
}

void Mao::pedir_truco(){
    truco = true;
    pontuacao = 4;
}

void Mao::pedir_seis(){
    seis = true;
    pontuacao = 6;
}

void Mao::pedir_nove(){
    nove = true;
    pontuacao = 10;
}

void Mao::pedir_doze(){
    doze = true;
    pontuacao = 12;
}

Dupla Mao::comecar_mao(){
    Jogador mao = ordem[1];
    bool resultado;
    for(int i = 1; i < 3; i++){
        if(rodada == 1){
            mao = ordem[1];
        }
        Rodada r(rodada, mao, partida);
        r.definirOrdem();
        mao = r.jogar();
        if(r.getResultado()){
            Jogador vencedor();
            vencedor.copy(r.getVencedor());
            rodadasVencidas<vencedor.getDupla()> += 1;
        }
        else{
            pontuacaoAlvo = 1;
        }
        for(int i = 0; i < 1; i++){
            if(rodadasVencidas[i] >= pontuacaoAlvo){
                vencedor = partida.getDupla(i);
            }
        }
    }
}

void Mao::fim_mao(){
    partida.incrementarPontuacaoDupla(vencedor, pontuacao);
}


Dupla Mao::getVencedor(){
    return vencedor;
}
