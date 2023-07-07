/**
 * @file partida.cpp
 * @brief Implementação da classe Partida
 */

#include "partida.h"
#include <iostream>
/**
 * @brief Construtor padrão da classe Partida.
 * 
 * @param 
 */
Partida::Partida(){
    rodada = 0; /**< O número da rodada atual. */
}

/**
 * @brief Construtor da classe Partida.
 * 
 * @param jogadores Os jogadores que participam da partida.
 */
Partida::Partida(std::vector<Jogador> jogadores){
    Dupla duplas(); /**< As duplas que participam da partida. */
    for(int i = 0; i<jogadores.size(); i++){
        this->jogadores[i] = jogadores[i]; /**< Copia os dados de cada jogador. */
    }
    definirDuplas();
    rodada = 0; /**< O número da rodada atual. */
}

void Partida::copy(Partida p){
    for(int i = 0; i < 2; i++){
        jogadores[i] = p.getJogador(i);
    }
    definirDuplas();
}

void Partida::definirDuplas(){
    for (int i = 0; i < 2; i++){
        Dupla d(jogadores[i], jogadores[i+2]);
        dupla[i] = d;
    }
    
}

/**
 * @brief Define a próxima rodada.
 * 
 * @return Verdadeiro se a rodada foi definida com sucesso, falso caso contrário.
 */
void Partida::setRodada(){
    rodada +=1; /**< Incrementa o número da rodada. */
    if(rodada == 4){
        rodada = 0; /**< Volta para a primeira rodada se atingiu o limite. */
    }
}

/**
 * @brief Incrementa a pontuação de uma dupla.
 * 
 * @param dupla A dupla que terá a pontuação incrementada.
 * @param pontos O número de pontos a ser incrementado na pontuação da dupla.
 * @return Verdadeiro se a pontuação foi incrementada com sucesso, falso caso contrário.
 */
bool Partida::incrementarPontuacaoDupla(Dupla dupla, int pontos) {
    dupla.aumentarPontuacao(pontos); /**< Incrementa a pontuação da dupla. */
}

/**
 * @brief Verifica se alguma dupla atingiu a pontuação para vencer a partida.
 * 
 * @return Verdadeiro se alguma dupla venceu a partida, falso caso contrário.
 */
bool Partida::verificarVencedor() const {
    for(int i = 0; i < dupla.size(); i++){
        if (dupla[i].getPontuacao() >= 12) {
            return true; /**< Retorna verdadeiro se alguma dupla venceu a partida. */
        }
    }
    return false; /**< Retorna falso se nenhuma dupla venceu a partida. */
}

/**
 * @brief Imprime uma mensagem de parabéns para a dupla vencedora da partida.
 */
void Partida::imprimirParabens() const {
    for(int i = 0; i < dupla.size(); i++){
        if (dupla[i].getPontuacao() >= 12) {
            std::cout << "Parabéns à Dupla " << dupla[i].getNome() << " (" << dupla[i].getPontuacao() << " pontos)!" << std::endl;
            break;
        }
    }
}

/**
 * @brief Imprime um troféu para a dupla vencedora da partida.
 */
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

/**
 * @brief Imprime o estado atual da partida.
 */
void Partida::imprimirPartida() const {
    std::cout << "Partida:" << std::endl;
    for(int i = 0; i < dupla.size(); i++){
        std::cout << dupla[i].getNome() << ": " << dupla[i].getPontuacao() << " pontos" << std::endl;
    }
}

/**
 * @brief Obtém o jogador com o número especificado.
 * 
 * @param jogador O número do jogador a ser obtido.
 * @return O jogador correspondente ao número.
 */
Jogador Partida::getJogador(int jogador){
    return jogadores[jogador]; /**< Retorna o jogador correspondente ao número. */
}

/**
 * @brief Obtém a dupla com o índice especificado.
 * 
 * @param i O índice da dupla a ser obtida.
 * @return A dupla correspondente ao índice.
 */
Dupla Partida::getDupla(int i){
    return dupla[i]; /**< Retorna a dupla correspondente ao índice. */
}


/**
 * @brief Inicia a partida.
 * 
 * Realiza as mãos até que uma das duplas atinja a pontuação para vencer a partida.
 */
void Partida::iniciarPartida(){
    while(true){
        Mao mao(jogadores[rodada], *this); /**< Cria uma nova mão. */
        mao.comecar_mao(); /**< Inicia a mão. */
        if(mao.getResultado()){
            mao.fim_mao(); /**< Finaliza a mão e incrementa a pontuação da dupla vencedora. */
        }
        if(verificarVencedor){
            imprimirParabens(); /**< Imprime uma mensagem de parabéns para a dupla vencedora. */
            imprimirTrofeu(); /**< Imprime um troféu para a dupla vencedora. */
            imprimirPartida(); /**< Imprime o estado atual da partida. */
            break; /**< Encerra a partida. */
        }
        setRodada(); /**< Define a próxima rodada. */
    }
}
