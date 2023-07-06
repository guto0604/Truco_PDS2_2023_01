/**
 * @file placar.h
 * @brief Definição da classe Placar
 */

#ifndef PLACAR_H
#define PLACAR_H

#include <string>

/**
 * @brief Classe que representa um placar de truco.
 */
class Placar {
private:
    std::string nomeDupla1; /**< O nome da primeira dupla. */
    std::string nomeDupla2; /**< O nome da segunda dupla. */
    int placarDupla1; /**< O placar da primeira dupla. */
    int placarDupla2; /**< O placar da segunda dupla. */

public:
    Placar(); /**< Construtor padrão da classe Placar. */
    Placar(const std::string& nomeDupla1, const std::string& nomeDupla2); /**< Construtor da classe Placar. */
    void incrementarPlacarDupla1(int pontos); /**< Incrementa o placar da primeira dupla. */
    void incrementarPlacarDupla2(int pontos); /**< Incrementa o placar da segunda dupla. */
    bool verificarVencedor() const; /**< Verifica se alguma das duplas venceu o jogo. */
    void imprimirParabens() const; /**< Imprime uma mensagem de parabéns para a dupla vencedora. */
    void imprimirTrofeu() const; /**< Imprime um troféu na saída padrão. */
    void imprimirPlacar() const; /**< Imprime o placar atual na saída padrão. */
};

#endif
