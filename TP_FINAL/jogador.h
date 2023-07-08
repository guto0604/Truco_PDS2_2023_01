/**
 * @file jogador.h
 * @brief Definição da classe Jogador
 */

#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <vector>
#include <iostream>

#include "carta.h"
#include "baralho.h"

/**
 * @class Jogador
 * @brief Classe que representa um jogador de truco.
 * 
 * Um jogador possui um número, um nome, pertence a uma dupla
 * e pode receber cartas do baralho e jogar uma carta.
 */
class Jogador {
private:
    int numero; /**< O número do jogador. */
    std::string nome; /**< O nome do jogador. */
    int dupla; /**< O número da dupla à qual o jogador pertence. */
    std::vector<Carta> cartas; /**< As cartas do jogador. */

public:
    /**
     * @brief Construtor padrão da classe Jogador.
     */
    Jogador();

    /**
     * @brief Construtor da classe Jogador.
     * 
     * @param numero O número do jogador.
     * @param nome O nome do jogador.
     * @param dupla O número da dupla à qual o jogador pertence.
     */
    Jogador(int numero, std::string nome, int dupla);

    /**
     * @brief Copia os dados de outro jogador.
     * 
     * @param j O jogador a ser copiado.
     */
    void copy(Jogador j);

    /**
     * @brief Obtém o número do jogador.
     * 
     * @return O número do jogador.
     */
    int getNumero() const;

    /**
     * @brief Obtém o nome do jogador.
     * 
     * @return O nome do jogador.
     */
    std::string getNome() const;

    /**
     * @brief Obtém o número da dupla à qual o jogador pertence.
     * 
     * @return O número da dupla.
     */
    int getDupla() const;

    /**
     * @brief Recebe as cartas do baralho para uma jogada.
     * 
     * @param baralho O baralho de cartas.
     * @param jogada O número da jogada.
     */
    void receberCartas(Baralho baralho, int jogada);

    /**
     * @brief Joga uma carta.
     * 
     * Solicita ao jogador que escolha uma carta para jogar e a retorna.
     * 
     * @return A carta jogada.
     */
    Carta jogarCarta();

};

#endif