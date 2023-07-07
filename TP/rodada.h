/**
 * @file rodada.h
 * @brief Definição da classe Rodada
 */

#ifndef RODADA_H
#define RODADA_H

#include "partida.h"
#include "jogador.h"
#include "baralho.h"
#include "carta.h"

#include <string>
#include <vector>

/**
 * @brief Classe que representa uma rodada de truco.
 */
class Rodada {
private:
    Jogador mao; /**< O jogador que é a mão na rodada. */
    Partida partida; /**< A partida em que a rodada ocorre. */
    std::vector<Carta> cartas; /**< As cartas jogadas na rodada. */
    std::vector<Jogador> ordem; /**< A ordem dos jogadores na rodada. */
    bool resultado; /**< Indica se houve um vencedor (true) ou empate (false). */
    Jogador vencedor; /**< O jogador vencedor da rodada. */
    void aumentarPontuacao();
    void definirOrdem(); /**< Define a ordem dos jogadores na rodada. */
    int definirVencedor(); /**< Define o vencedor da rodada e retorna seu índice. */

public:
    Rodada(Jogador mao, Partida partida); /**< Construtor da classe Rodada. */
    bool getResultado(); /**< Obtém o resultado da rodada. */
    Jogador getVencedor(); /**< Obtém o jogador vencedor da rodada. */
    Jogador jogar(); /**< Realiza a jogada da rodada. */
};

#endif