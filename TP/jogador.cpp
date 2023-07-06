#include "jogador.h"

Jogador::Jogador() : numero(0), nome("") {}

void Jogador::setNumero(int numero) {
    this->numero = numero;
}

void Jogador::setNome(const std::string& nome) {
    this->nome = nome;
}

int Jogador::getNumero() const {
    return numero;
}

std::string Jogador::getNome() const {
    return nome;
}
