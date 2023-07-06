#include "jogador.h"

Jogador::Jogador(){}

Jogador::Jogador(int numero, std::string nome, int dupla){
    this->numero = numero;
    this->nome = nome;
    this->dupla = dupla;
}

void Jogador::copy(Jogador j){
    numero = j.getNumero();
    nome = j.getNome();
    dupla = j.getDupla();
}

int Jogador::getNumero() const {
    return numero;
}

std::string Jogador::getNome() const {
    return nome;
}

int Jogador::getDupla() const {
    return dupla;
}

void Jogador::receberCartas(Baralho baralho, int jogada){
    for(int i = 0; i < 3; i++){
        cartas[i] = baralho.darCarta((jogada*3 + i));
    }
}

Carta Jogador::jogarCarta(){
    while(true){
        int jogar;
        std::cin >> jogar;
        if(!cartas[jogar].jogada()){
            return cartas[jogar];
        }
        else{
            std::cout << "Carta " << cartas[jogar].getCarta() << " já jogada";
        }
    }
}

