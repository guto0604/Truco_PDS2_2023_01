/**
 * @file partida.h
 * @brief Definição da classe Partida
 */

#ifndef PLACAR_H
#define PLACAR_H

#include "dupla.h"
#include "jogador.h"
#include "mao.h"

#include <string>
#include <vector>

/**
 * @brief Classe que representa uma partida de truco.
 */
class Partida {
private:
    std::vector<Jogador> jogadores; /**< Os jogadores que participam da partida. */
    std::vector<Dupla> dupla; /**< As duplas que participam da partida. */
    int rodada; /**< O número da rodada atual. */

public:
    Partida(); /**< Construtor padrão da classe Partida. */
    Partida(std::vector<Jogador> jogadores); /**< Construtor da classe Partida. */
    void copy(Partida p);
    void definirDuplas();
    Dupla getDupla(int i); /**< Obtém a dupla com o índice especificado. */
    bool setRodada(); /**< Define a próxima rodada. */
    void iniciarMao(); /**< Inicia uma mão. */
    bool incrementarPontuacaoDupla(Dupla dupla, int pontos); /**< Incrementa a pontuação de uma dupla. */
    bool verificarVencedor() const; /**< Verifica se alguma dupla venceu a partida. */
    void imprimirParabens() const; /**< Imprime uma mensagem de parabéns para a dupla vencedora. */
    void imprimirTrofeu() const; /**< Imprime um troféu para a dupla vencedora. */
    void imprimirPartida() const; /**< Imprime o estado atual da partida. */
    Jogador getJogador(int jogador); /**< Obtém o jogador com o número especificado. */

    void iniciarPartida(); /**< Inicia a partida. */
};

#endif