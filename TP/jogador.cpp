/**
 * @file jogador.cpp
 * @brief Implementação da classe Jogador
 */

#include "jogador.h"

/**
 * @brief Construtor padrão da classe Jogador.
 */
Jogador::Jogador(){}

/**
 * @brief Construtor da classe Jogador.
 * 
 * @param numero O número do jogador.
 * @param nome O nome do jogador.
 * @param dupla O número da dupla à qual o jogador pertence.
 */
Jogador::Jogador(int numero, std::string nome, int dupla){
    this->numero = numero;
    this->nome = nome;
    this->dupla = dupla;
}

/**
 * @brief Copia os dados de outro jogador.
 * 
 * @param j O jogador a ser copiado.
 */
void Jogador::copy(Jogador j){
    numero = j.getNumero();
    nome = j.getNome();
    dupla = j.getDupla();
}

/**
 * @brief Obtém o número do jogador.
 * 
 * @return O número do jogador.
 */
int Jogador::getNumero() const {
    return numero;
}

/**
 * @brief Obtém o nome do jogador.
 * 
 * @return O nome do jogador.
 */
std::string Jogador::getNome() const {
    return nome;
}

/**
 * @brief Obtém o número da dupla à qual o jogador pertence.
 * 
 * @return O número da dupla.
 */
int Jogador::getDupla() const {
    return dupla;
}

/**
 * @brief Recebe as cartas do baralho para uma jogada.
 * 
 * @param baralho O baralho de cartas.
 * @param jogada O número do jogador na ordem.
 */
void Jogador::receberCartas(Baralho baralho, int jogada){
    for(int i = 0; i < 3; i++){
        cartas[i] = baralho.darCarta((jogada*3 + i));
    }
}

/**
 * @brief Joga uma carta.
 * 
 * Solicita ao jogador que escolha uma carta para jogar e a retorna.
 * 
 * @return A carta jogada.
 */
Carta Jogador::jogarCarta(){
    while(true){
        std::cout << "Suas cartas:" << std::endl;
        for (int i = 0; i < cartas.size(); i++){
            if(!cartas[i].jogada()){
                std::cout << i << ": " << cartas[i].getCarta() << std::endl;
            }
        }
        std::cout << "Índice da carta a ser jogada: " << std::endl;
        int jogar;
        while(true){
            std::cin >> jogar;
            if(jogar >= 0 & jogar < cartas.size()){
                break;
            }
            else{
                std::cout << "Carta não existe, digite um número válido" << std::endl;
            }
        }
        if(!cartas[jogar].jogada()){
            return cartas[jogar];
        }
        else{
            std::cout << "Carta " << cartas[jogar].getCarta() << " já jogada" << std::endl;
        }
    }
}
