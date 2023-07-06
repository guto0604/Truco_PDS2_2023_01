/**
 * @file rodada.cpp
 * @brief Implementação da classe Rodada
 */

#include "rodada.h"
#include <iostream>

/**
 * @brief Construtor da classe Rodada.
 * 
 * @param rodada O número da rodada.
 * @param mao O jogador que será a mão na rodada.
 * @param partida A partida em que a rodada está ocorrendo.
 */
Rodada::Rodada(int rodada, Jogador mao, Partida partida){
    this->rodada = rodada; /**< Inicializa o número da rodada. */
    Jogador mao; /**< Cria um objeto Jogador chamado mao. */
    this->mao.copy(mao); /**< Copia o jogador mao para o atributo mao da rodada. */
    this->partida = partida; /**< Inicializa a partida. */
    resultado = false; /**< Inicializa o resultado da rodada como falso. */
    definirOrdem(); /**< Define a ordem dos jogadores na rodada. */
}

/**
 * @brief Obtém o resultado da rodada.
 * 
 * @return Verdadeiro se a rodada teve resultado, falso caso contrário.
 */
bool Rodada::getResultado(){
    return resultado; /**< Retorna o resultado da rodada. */
}

/**
 * @brief Obtém o jogador vencedor da rodada.
 * 
 * @return O jogador vencedor da rodada.
 */
Jogador Rodada::getVencedor(){
    return vencedor; /**< Retorna o jogador vencedor da rodada. */
}

/**
 * @brief Define a ordem dos jogadores na rodada.
 */
void Rodada::definirOrdem(){
    int n = mao.getNumero();
    for (int i = 0; i < 4; i++){
        if(n == 4){
            n = 0;
        }
        ordem[i] = partida.getJogador(n); /**< Define a ordem dos jogadores com base no número da mão e na partida. */
        n += 1;
    }
}

/**
 * @brief Realiza a jogada da rodada.
 * 
 * @return O jogador vencedor da rodada, ou a mão se a rodada não teve resultado.
 */
Jogador Rodada::jogar(){
    for(int i = 0; i < ordem.size(); i++){
        cartas[i] = ordem[i].jogarCarta(); /**< Cada jogador joga uma carta. */
        std::cout << cartas[i].getCarta(); /**< Imprime a carta jogada na rodada. */
    }
    if(definirVencedor() == 0){
        return mao; /**< Retorna a mão se a rodada não teve resultado. */
    }
    else{
        return vencedor; /**< Retorna o jogador vencedor da rodada. */
    }
}

/**
 * @brief Define o vencedor da rodada e verifica se houve um resultado.
 * 
 * @return O índice do jogador vencedor, ou 0 se a rodada não teve resultado.
 */
int Rodada::definirVencedor(){
    Carta maior = cartas[0];
    int j = 0;
    int n = 1;
    for(int i = 1; i < cartas.size(); i++){
        if(cartas[i].getValor() > maior.getValor()){
            maior =cartas[i];
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
    return j; /**< Retorna o índice do jogador vencedor, ou 0 se a rodada não teve resultado. */
}
