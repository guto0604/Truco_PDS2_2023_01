/**
 * @file baralho.cpp
 * @brief Implementação da classe Baralho
 */

#include "baralho.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Construtor da classe Baralho.
 * 
 * Cria um novo baralho de cartas com 40 cartas, 
 * cada uma contendo um número e um naipe.
 */
Baralho::Baralho() {
    
    std::vector<Carta> cartas;

    std::vector<std::string> naipes;
    naipes.push_back("paus");
    naipes.push_back("copas");
    naipes.push_back("espadas");
    naipes.push_back("ouros");

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
            cartas.push_back(Carta((j+1), naipes[i]));
        }
    }

    for(int i = 0; i < 40; i++){
        baralho.push_back(cartas[i]);
    }
    
}

/**
 * @brief Embaralha o baralho de cartas.
 * 
 * Utiliza o algoritmo Fisher-Yates para embaralhar as cartas no baralho.
 * A função `rand()` é utilizada para gerar números aleatórios.
 */
void Baralho::embaralhar(){

    unsigned seed = time(0);
    for (int i = 39; i >= 0; i--) {
        int j = rand() % (i + 1);
        Carta tmp = baralho[j];
        baralho[j] = baralho[i];
        baralho[i] = tmp;
    }

}

/**
 * @brief Retorna uma carta do baralho.
 * 
 * @param carta O índice da carta a ser retornada.
 * @return A carta do baralho correspondente ao índice fornecido.
 */
Carta Baralho::darCarta(int carta){
    return baralho[carta];
}