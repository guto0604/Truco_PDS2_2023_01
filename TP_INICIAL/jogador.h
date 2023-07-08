/**
 * @file jogador.h
 * @brief Definições da classe Jogador.
 */

#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

/**
 * @class Jogador
 * @brief Representa um jogador em um jogo.
 */
class Jogador {
private:
    int numero; /**< Número do jogador. */
    std::string nome; /**< Nome do jogador. */

public:
    /**
     * @brief Construtor padrão da classe Jogador.
     *
     * Inicializa o número do jogador como 0 e o nome como uma string vazia.
     */
    Jogador();

    /**
     * @brief Define o número do jogador.
     * @param numero O número a ser atribuído ao jogador.
     */
    void setNumero(int numero);

    /**
     * @brief Define o nome do jogador.
     * @param nome O nome a ser atribuído ao jogador.
     */
    void setNome(const std::string& nome);

    /**
     * @brief Obtém o número do jogador.
     * @return O número do jogador.
     */
    int getNumero() const;

    /**
     * @brief Obtém o nome do jogador.
     * @return O nome do jogador.
     */
    std::string getNome() const;
};

#endif // JOGADOR_H
