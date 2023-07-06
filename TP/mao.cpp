/**
 * @file mao.cpp
 * @brief Implementação da classe Mao
 */

#include "mao.h"
#include <iostream>

/**
 * @brief Construtor da classe Mao.
 * 
 * @param embaralhou O jogador que embaralhou as cartas.
 * @param partida A partida em que a mão está sendo jogada.
 */
Mao::Mao(Jogador embaralhou, Partida p){
    Baralho baralho(); /**< O baralho de cartas. */
    Partida partida();
    Jogador embaralhou(); /**< O jogador que embaralhou as cartas. */
    partida.copy(p); /**< A partida em que a mão está sendo jogada. */
    this->embaralhou.copy(embaralhou); /**< Copia os dados do jogador embaralhou. */
    rodada = 1; /**< O número da rodada atual. */
    for(int i = 0; i < 1; i++){
        rodadasVencidas[i] = 0; /**< O número de rodadas vencidas por cada dupla. */
    }
    pontuacaoAlvo = 2; /**< A pontuação alvo para vencer a mão. */
    pontuacao = 2; /**< A pontuação atual da mão. */
    truco = false; /**< Indica se foi solicitado truco. */
    seis = false; /**< Indica se foi solicitado seis. */
    nove = false; /**< Indica se foi solicitado nove. */
    doze = false; /**< Indica se foi solicitado doze. */
    definirOrdemInicial(); /**< Define a ordem inicial dos jogadores. */
    darCartas(); /**< Distribui as cartas do baralho para cada jogador. */
}

/**
 * @brief Define a ordem inicial dos jogadores.
 * 
 * A ordem inicial é determinada com base no número do jogador que embaralhou.
 */
void Mao::definirOrdemInicial(){
    int n = embaralhou.getNumero() + 1;
    for (int i = 0; i < 4; i++){
        if(n == 4){
            n = 0;
        }
        ordem[i] = partida.getJogador(n); /**< Obtém o jogador correspondente ao número da ordem. */
        n += 1;
    }
    
}

/**
 * @brief Distribui as cartas do baralho para cada jogador.
 */
void Mao::darCartas(){
    baralho.embaralhar(); /**< Embaralha o baralho de cartas. */
    for(int j = 0; j < 4; j++){
        ordem[j].receberCartas(baralho, j); /**< Distribui as cartas para cada jogador. */
    }
}

/**
 * @brief Solicita truco durante a mão.
 */
void Mao::pedir_truco(){
    truco = true; /**< Define a variável truco como true. */
    pontuacao = 4; /**< Define a pontuação como 4. */
}

/**
 * @brief Solicita seis durante a mão.
 */
void Mao::pedir_seis(){
    seis = true; /**< Define a variável seis como true. */
    pontuacao = 6; /**< Define a pontuação como 6. */
}

/**
 * @brief Solicita nove durante a mão.
 */
void Mao::pedir_nove(){
    nove = true; /**< Define a varinte nove como true. */
    pontuacao = 10; /**< Define a pontuação como 10. */
}

/**
 * @brief Solicita doze durante a mão.
 */
void Mao::pedir_doze(){
    doze = true; /**< Define a variável doze como true. */
    pontuacao = 12; /**< Define a pontuação como 12. */
}

/**
 * @brief Começa a mão e realiza as rodadas.
 * 
 * @return A dupla vencedora da mão.
 */
void Mao::comecar_mao(){
    Jogador mao = ordem[1]; /**< O jogador que começa a mão. */
    bool resultado;
    for(int i = 1; i < 3; i++){
        if(rodada == 1){
            mao = ordem[1]; /**< Define o jogador da mão como o segundo jogador da ordem. */
        }
        Rodada r(rodada, mao, partida); /**< Cria uma nova rodada. */
        r.definirOrdem(); /**< Define a ordem de jogada na rodada. */
        mao = r.jogar(); /**< Realiza a rodada e obtém o próximo jogador da mão. */
        if(r.getResultado()){
            Jogador vencedor = r.getVencedor(); /**< O jogador vencedor da rodada. */
            int duplaVencedora = vencedor.getDupla();
            rodadasVencidas[duplaVencedora] += 1; /**< Incrementa o número de rodadas vencidas pela dupla do jogador vencedor. */
        }
        else{
            pontuacaoAlvo = 1; /**< Define a pontuação alvo como 1 caso a rodada termine em empate. */
        }
        for(int i = 0; i < 1; i++){
            if(rodadasVencidas[i] >= pontuacaoAlvo){
                vencedor = partida.getDupla(i); /**< Obtém a dupla vencedora da mão. */
            }
        }
    }
}

/**
 * @brief Finaliza a mão e incrementa a pontuação da dupla vencedora.
 */
void Mao::fim_mao(){
    partida.incrementarPontuacaoDupla(vencedor, pontuacao); /**< Incrementa a pontuação da dupla vencedora. */
}


/**
 * @brief Obtém a dupla vencedora da mão.
 * 
 * @return A dupla vencedora da mão.
 */
Dupla Mao::getVencedor(){
    return vencedor; /**< Retorna a dupla vencedora da mão. */
}