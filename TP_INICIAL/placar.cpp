/**
 * @file placar.cpp
 * @brief Implementação da classe Placar.
 */

#include "placar.h"
#include <iostream>

/**
 * @brief Construtor padrão da classe Placar.
 *
 * Inicializa os nomes das duplas como strings vazias e os placares como 0.
 */
Placar::Placar()
    : nomeDupla1(""), nomeDupla2(""), placarDupla1(0), placarDupla2(0) {}

/**
 * @brief Construtor da classe Placar.
 * @param nomeDupla1 Nome da primeira dupla.
 * @param nomeDupla2 Nome da segunda dupla.
 *
 * Inicializa os nomes das duplas com os nomes fornecidos e os placares como 0.
 */
Placar::Placar(const std::string& nomeDupla1, const std::string& nomeDupla2)
    : nomeDupla1(nomeDupla1), nomeDupla2(nomeDupla2), placarDupla1(0), placarDupla2(0) {}

/**
 * @brief Incrementa o placar da primeira dupla.
 * @param pontos Pontos a serem adicionados ao placar da primeira dupla.
 */
void Placar::incrementarPlacarDupla1(int pontos) {
    placarDupla1 += pontos;
}

/**
 * @brief Incrementa o placar da segunda dupla.
 * @param pontos Pontos a serem adicionados ao placar da segunda dupla.
 */
void Placar::incrementarPlacarDupla2(int pontos) {
    placarDupla2 += pontos;
}

/**
 * @brief Verifica se há um vencedor.
 * @return `true` se alguma das duplas alcançou 12 pontos ou mais, caso contrário `false`.
 */
bool Placar::verificarVencedor() const {
    return placarDupla1 >= 12 || placarDupla2 >= 12;
}

/**
 * @brief Imprime uma mensagem de parabéns para a dupla vencedora.
 */
void Placar::imprimirParabens() const {
    if (placarDupla1 >= 12) {
        std::cout << "Parabéns à Dupla " << nomeDupla1 << " (" << placarDupla1 << " pontos)!" << std::endl;
    } else if (placarDupla2 >= 12) {
        std::cout << "Parabéns à Dupla " << nomeDupla2 << " (" << placarDupla2 << " pontos)!" << std::endl;
    }
}

/**
 * @brief Imprime um troféu.
 */
void Placar::imprimirTrofeu() const {
    std::cout << "         .-=========-.\n"
                 "          \'-=======-'/\n"
                 "          _|   .=.   |_\n"
                 "         ((|  {{1}}  |))\n"
                 "          \\|   /|\\   |/\n"
                 "           \\__ '`' __/\n"
                 "             _`) (`_\n"
                 "           _/_______\\_\n"
                 "          /___________\\ " << std::endl;
}

/**
 * @brief Imprime o placar atual das duplas.
 */
void Placar::imprimirPlacar() const {
    std::cout << "Placar:" << std::endl;
    std::cout << nomeDupla1 << ": " << placarDupla1 << " pontos" << std::endl;
    std::cout << nomeDupla2 << ": " << placarDupla2 << " pontos" << std::endl;
}
