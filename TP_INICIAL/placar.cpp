#include "placar.h"
#include <iostream>

Placar::Placar()
    : nomeDupla1(""), nomeDupla2(""), placarDupla1(0), placarDupla2(0) {}

Placar::Placar(const std::string& nomeDupla1, const std::string& nomeDupla2)
    : nomeDupla1(nomeDupla1), nomeDupla2(nomeDupla2), placarDupla1(0), placarDupla2(0) {}


void Placar::incrementarPlacarDupla1(int pontos) {
    placarDupla1 += pontos;
}

void Placar::incrementarPlacarDupla2(int pontos) {
    placarDupla2 += pontos;
}

bool Placar::verificarVencedor() const {
    return placarDupla1 >= 12 || placarDupla2 >= 12;
}

void Placar::imprimirParabens() const {
    if (placarDupla1 >= 12) {
        std::cout << "Parabéns à Dupla " << nomeDupla1 << " (" << placarDupla1 << " pontos)!" << std::endl;
    } else if (placarDupla2 >= 12) {
        std::cout << "Parabéns à Dupla " << nomeDupla2 << " (" << placarDupla2 << " pontos)!" << std::endl;
    }
}

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

void Placar::imprimirPlacar() const {
    std::cout << "Placar:" << std::endl;
    std::cout << nomeDupla1 << ": " << placarDupla1 << " pontos" << std::endl;
    std::cout << nomeDupla2 << ": " << placarDupla2 << " pontos" << std::endl;
}