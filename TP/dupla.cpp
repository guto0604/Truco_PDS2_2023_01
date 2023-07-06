#include "dupla.h"

Dupla::Dupla(Jogador j1, Jogador j2){
    pontuacao = 0;
    nome = "";
    dupla = std::make_pair(j1,j2);
}

Dupla::Dupla(std::string nome, Jogador j1, Jogador j2){
    pontuacao = 0;
    this->nome = nome;
    dupla = std::make_pair(j1,j2);
}

int Dupla::getPontuacao() const {
    return pontuacao;
}

bool Dupla::aumentarPontuacao(int pontos) {
    pontuacao += pontos;
}

bool Dupla::setNome(std::string nome) {
    this->nome = nome;
    return true;
}

std::string Dupla::getNome() const {
    return this->nome;
}
