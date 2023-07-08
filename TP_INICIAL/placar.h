/**
 * @file placar.h
 * @brief Definições da classe Placar.
 */

#ifndef PLACAR_H
#define PLACAR_H

#include <string>

/**
 * @class Placar
 * @brief Representa o placar de um jogo entre duas duplas.
 */
class Placar {
private:
    std::string nomeDupla1; /**< Nome da primeira dupla. */
    std::string nomeDupla2; /**< Nome da segunda dupla. */
    int placarDupla1; /**< Placar da primeira dupla. */
    int placarDupla2; /**< Placar da segunda dupla. */

public:
    /**
     * @brief Construtor padrão da classe Placar.
     *
     * Inicializa os nomes das duplas como strings vazias e os placares como 0.
     */
    Placar();

    /**
     * @brief Construtor da classe Placar.
     * @param nomeDupla1 Nome da primeira dupla.
     * @param nomeDupla2 Nome da segunda dupla.
     *
     * Inicializa os nomes das duplas com os nomes fornecidos e os placares como 0.
     */
    Placar(const std::string& nomeDupla1, const std::string& nomeDupla2);

    /**
     * @brief Incrementa o placar da primeira dupla.
     * @param pontos Pontos a serem adicionados ao placar da primeira dupla.
     */
    void incrementarPlacarDupla1(int pontos);

    /**
     * @brief Incrementa o placar da segunda dupla.
     * @param pontos Pontos a serem adicionados ao placar da segunda dupla.
     */
    void incrementarPlacarDupla2(int pontos);

    /**
     * @brief Verifica se há um vencedor.
     * @return `true` se alguma das duplas alcançou 12 pontos ou mais, caso contrário `false`.
     */
    bool verificarVencedor() const;

    /**
     * @brief Imprime uma mensagem de parabéns para a dupla vencedora.
     */
    void imprimirParabens() const;

    /**
     * @brief Imprime um troféu.
     */
    void imprimirTrofeu() const;

    /**
     * @brief Imprime o placar atual das duplas.
     */
    void imprimirPlacar() const;
};

#endif // PLACAR_H
