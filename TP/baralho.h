/**
 * @file baralho.h
 * @brief Definição da classe Baralho
 */

#ifndef BARALHO_H
#define BARALHO_H

#include <string>
#include <map>
#include <vector>

#include "carta.h"

/**
 * @brief Classe que representa um baralho de cartas.
 */
class Baralho{
public:
    Baralho(); /**< Construtor da classe Baralho. */
    void embaralhar(); /**< Embaralha as cartas do baralho. */
    Carta darCarta(int carta); /**< Distribui uma carta do baralho. */

private:
    std::vector<Carta> baralho; /**< O vetor de cartas do baralho. */

};

#endif
