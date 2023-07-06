/**
 * @file dupla.cpp
 * @brief Implementação da classe Dupla
 */

#include "dupla.h"

/**
 * @brief Construtor da classe Dupla.
 * 
 * @param j1 O primeiro jogador da dupla.
 * @param j2 O segundo jogador da dupla.
 */
Dupla::Dupla(Jogador j1, Jogador j2){
    pontuacao = 0;
    nome = "";
    dupla = std::make_pair(j1,j2);
}

/**
 * @brief Construtor da classe Dupla.
 * 
 * @param nome O nome da dupla.
 * @param j1 O primeiro jogador da dupla.
 * @param j2 O segundo jogador da dupla.
 */
Dupla::Dupla(std::string nome, Jogador j1, Jogador j2){
    pontuacao = 0;
    this->nome = nome;
    dupla = std::make_pair(j1,j2);
}

/**
 * @brief Obtém a pontuação da dupla.
 * 
 * @return A pontuação da dupla.
 */
int Dupla::getPontuacao() const {
    return pontuacao;
}

/**
 * @brief Aumenta a pontuação da dupla.
 * 
 * @param pontos Os pontos a serem adicionados à pontuação da dupla.
 * @return true se a pontuação foi aumentada com sucesso, false caso contrário.
 */
bool Dupla::aumentarPontuacao(int pontos) {
    pontuacao += pontos;
    return true;
}

/**
 * @brief Define o nome da dupla.
 * 
 * @param nome O nome a ser atribuído à dupla.
 * @return true se o nome foi definido com sucesso, false caso contrário.
 */
bool Dupla::setNome(std::string nome) {
    this->nome = nome;
    return true;
}

/**
 * @brief Obtém o nome da dupla.
 * 
 * @return O nome da dupla.
 */
std::string Dupla::getNome() const {
    return this->nome;
}
