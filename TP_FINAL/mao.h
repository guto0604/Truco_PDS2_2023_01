#ifndef MAO_H
#define MAO_H

#include "jogador.h"
#include "baralho.h"
#include "partida.h"
#include "dupla.h"
#include "rodada.h"

#include<vector>
#include<map>

class Mao {
private:
    Baralho baralho; /**< O baralho utilizado na mão. */
    Jogador embaralhou; /**< O jogador que embaralhou as cartas. */
    Partida partida; /**< A partida em que a mão está sendo jogada. */
    std::vector<Jogador> ordem; /**< A ordem dos jogadores na mão. */
    std::map<int, int> rodadasVencidas; /**< O número de rodadas vencidas por cada dupla. */
    bool resultado; /**< Indica se houve um vencedor na rodada. */
    Dupla vencedor; /**< A dupla vencedora da mão. */
    int rodada; /**< O número da rodada atual. */
    int pontuacaoAlvo; /**< O número de rodadas a serem vencidas para a mão ser ganha. */
    int pontuacao; /**< A pontuação atual da mão. */
    bool resultado; /**< Indica se houve um vencedor na mão. */
    bool truco; /**< Indica se foi solicitado truco. */
    bool seis; /**< Indica se foi solicitado seis. */
    bool nove; /**< Indica se foi solicitado nove. */
    bool doze; /**< Indica se foi solicitado doze. */

public:
    Mao(Jogador embaralhou, Partida partida);
    void darCartas(); /**< Distribui as cartas para cada jogador. */
    void definirOrdemInicial(); /**< Define a ordem inicial dos jogadores. */
    void pedir_truco(); /**< Solicita truco durante a mão. */
    void pedir_seis(); /**< Solicita seis durante a mão. */
    void pedir_nove(); /**< Solicita nove durante a mão. */
    void pedir_doze(); /**< Solicita doze durante a mão. */
    void comecar_mao(); /**< Começa a mão e realiza as rodadas. */
    void fim_mao(); /**< Finaliza a mão e incrementa a pontuação da dupla vencedora. */
    bool getResultado(); /**< Obtém a se houve um vencedor na mão. */
    Dupla getVencedor(); /**< Obtém a dupla vencedora da mão. */

};

#endif