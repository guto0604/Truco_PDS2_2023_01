/**
 * @file carta.h
 * @brief Definição da classe Carta
 */

#ifndef CARTA_H
#define CARTA_H

#include "jogador.h"

#include <string>
#include <sstream>

/**
 * @brief Classe que representa uma carta de baralho.
 */
class Carta{
public:
    Carta(int numero, std::string naipe); /**< Construtor da classe Carta. */
    void entregarCarta(Jogador jogador); /**< Entrega a carta a um jogador. */
    int getValor(); /**< Obtém o valor da carta. */
    std::string getCarta(); /**< Obtém a representação da carta em forma de string. */
    bool jogada(); /**< Verifica se a carta já foi jogada. */

private:
    int numero; /**< O número da carta. */
    std::string naipe; /**< O naipe da carta. */
    int valor; /**< O valor da carta. */
    Jogador jogador; /**< O jogador que possui a carta. */
    bool ja_jogada; /**< Indica se a carta já foi jogada ou não. */

};

#endif