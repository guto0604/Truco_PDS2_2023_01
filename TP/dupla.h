/**
 * @file dupla.h
 * @brief Definição da classe Dupla
 */

#ifndef DUPLA_H
#define DUPLA_H

#include "jogador.h"

#include <string>
#include <sstream>

/**
 * @class Dupla
 * @brief Classe que representa uma dupla de jogadores.
 * 
 * Uma dupla é composta por dois jogadores e possui uma pontuação e um nome.
 */
class Dupla{
public:
    /**
     * @brief Construtor da classe Dupla.
     * 
     * @param j1 O primeiro jogador da dupla.
     * @param j2 O segundo jogador da dupla.
     */
    Dupla(Jogador j1, Jogador j2);

    /**
     * @brief Construtor da classe Dupla.
     * 
     * @param nome O nome da dupla.
     * @param j1 O primeiro jogador da dupla.
     * @param j2 O segundo jogador da dupla.
     */
    Dupla(std::string nome, Jogador j1, Jogador j2);
    /**
     * @brief Obtém a pontuação da dupla.
     * 
     * @return A pontuação da dupla.
     */
    int getPontuacao() const;

    /**
     * @brief Aumenta a pontuação da dupla.
     * 
     * @param pontos Os pontos a serem adicionados à pontuação da dupla.
     * @return true se a pontuação foi aumentada com sucesso, false caso contrário.
     */
    bool aumentarPontuacao(int pontos);
    
    /**
     * @brief Define o nome da dupla.
     * 
     * @param nome O nome a ser atribuído à dupla.
     * @return true se o nome foi definido com sucesso, false caso contrário.
     */
    bool setNome(std::string nome);

    /**
     * @brief Obtém o nome da dupla.
     * 
     * @return O nome da dupla.
     */
    std::string getNome() const;

private:

    std::pair<Jogador, Jogador> dupla; /**< Os jogadores que formam a dupla. */
    int pontuacao; /**< A pontuação da dupla. */
    std::string nome; /**< O nome da dupla. */

};

#endif