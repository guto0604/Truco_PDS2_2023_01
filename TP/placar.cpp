/**
 * @file placar.cpp
 * @brief Implementação da classe Placar
 */

#include "placar.h"
#include <iostream>

/**
 * @brief Construtor padrão da classe Placar.
 * 
 * Inicializa o placar com nomes de duplas vazios e pontuações zeradas.
 */
Placar::Placar()
    : nomeDupla1(""), nomeDupla2(""), placarDupla1(0), placarDupla2(0) {}

/**
 * @brief Construtor da classe Placar.
 * 
 * @param nomeDupla1 O nome da primeira dupla.
 * @param nomeDupla2 O nome da segunda dupla.
 */
Placar::Placar(const std::string& nomeDupla1, const std::string& nomeDupla2)
    : nomeDupla1(nomeDupla1), nomeDupla2(nomeDupla2), placarDupla1(0), placarDupla2(0) {}

/**
 * @brief Incrementa o placar da primeira dupla.
 * 
 * @param pontos O número de pontos a serem incrementados.
 */
void Placar::incrementarPlacarDupla1(int pontos) {
    placarDupla1 += pontos; /**< Incrementa o placar da primeira dupla. */
}

/**
 * @brief Incrementa o placar da segunda dupla.
 * 
 * @param pontos O número de pontos a serem incrementados.
 */
void Placar::incrementarPlacarDupla2(int pontos) {
    placarDupla2 += pontos; /**< Incrementa o placar da segunda dupla. */
}

/**
 * @brief Verifica se alguma das duplas venceu o jogo.
 * 
 * @return Verdadeiro se alguma dupla venceu, falso caso contrário.
 */
bool Placar::verificarVencedor() const {
    return placarDupla1 >= 12 || placarDupla2 >= 12; /**< Verifica se alguma das duplas atingiu a pontuação necessária para vencer. */
}

/**
 * @brief Imprime uma mensagem de parabéns para a dupla vencedora.
 */
void Placar::imprimirParabens() const {
    if (placarDupla1 >= 12) {
        std::cout << "Parabéns à Dupla " << nomeDupla1 << " (" << placarDupla1 << " pontos)!" << std::endl; /**< Imprime a mensagem de parabéns para a primeira dupla. */
    } else if (placarDupla2 >= 12) {
        std::cout << "Parabéns à Dupla " << nomeDupla2 << " (" << placarDupla2 << " pontos)!" << std::endl; /**< Imprime a mensagem de parabéns para a segunda dupla. */
    }
}

/**
 * @brief Imprime um troféu na saída padrão.
 */
void Placar::imprimirTrofeu() const {
    std::cout << "         .-=========-.\n"
                 "          \'-=======-'/\n"
                 "          _|   .=.   |_\n"
                 "         ((|  {{1}}  |))\n"
                 "          \\|   /|\\   |/\n"
                 "           \\__ '`' __/\n"
                 "             _`)("`_ \n"
                 "           _/_______\\_\n"
                 "          /___________\\ " << std::endl;
}

/**
 * @brief Imprime o placar atual na saída padrão.
 */
void Placar::imprimirPlacar() const {
    std::cout << "Placar:" << std::endl;
    std::cout << nomeDupla1 << ": " << placarDupla1 << " pontos" << std::endl; /**< Imprime o placar da primeira dupla. */
    std::cout << nomeDupla2 << ": " << placarDupla2 << " pontos" << std::endl; /**< Imprime o placar da segunda dupla. */
}
