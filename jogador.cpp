/**
 * @file jogador.cpp
 * @brief Implementação da classe Jogador.
 */

#include "jogador.h"

/**
 * @brief Construtor padrão da classe Jogador.
 *
 * Inicializa o número do jogador como 0 e o nome como uma string vazia.
 */
Jogador::Jogador() : numero(0), nome("") {}

/**
 * @brief Define o número do jogador.
 * @param numero O número a ser atribuído ao jogador.
 */
void Jogador::setNumero(int numero) {
    this->numero = numero;
}

/**
 * @brief Define o nome do jogador.
 * @param nome O nome a ser atribuído ao jogador.
 */
void Jogador::setNome(const std::string& nome) {
    this->nome = nome;
}

/**
 * @brief Obtém o número do jogador.
 * @return O número do jogador.
 */
int Jogador::getNumero() const {
    return numero;
}

/**
 * @brief Obtém o nome do jogador.
 * @return O nome do jogador.
 */
std::string Jogador::getNome() const {
    return nome;
}
