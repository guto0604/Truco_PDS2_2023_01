/**
 * @file carta.cpp
 * @brief Implementação da classe Carta
 */

#include "carta.h"

/**
 * @brief Construtor da classe Carta.
 * 
 * @param numero O número da carta.
 * @param naipe O naipe da carta.
 */
Carta::Carta(int numero, std::string naipe){
    this->numero = numero;
    this->naipe = naipe;
    ja_jogada = false;
    
    if(numero >= 4 && numero < 10){
        valor = numero - 3;
    }
    else{
        valor = numero + 7;
    }

    if(numero == 4 && naipe == "paus"){
        valor = 14;
    } else if(numero == 7 && naipe == "copas"){
        valor = 13;
    } else if(numero == 1 && naipe == "espadas"){
        valor = 12;
    } else if(numero == 7 && naipe == "ouros"){
        valor = 11;
    }

}

/**
 * @brief Entrega a carta a um jogador.
 * 
 * @param jogador O jogador que receberá a carta.
 */
void Carta::entregarCarta(Jogador jogador){
    this->jogador = jogador;
}

/**
 * @brief Obtém o valor da carta.
 * 
 * @return O valor da carta.
 */
int Carta::getValor(){
    return valor;
}
    
/**
 * @brief Obtém a representação da carta como uma string.
 * 
 * @return A representação da carta como uma string.
 */
std::string Carta::getCarta(){
    std::ostringstream texto;
    texto << numero << " de " << naipe;
    return texto.str();
}

/**
 * @brief Verifica se a carta já foi jogada.
 * 
 * @return true se a carta já foi jogada, false caso contrário.
 */
bool Carta::jogada(){
    return ja_jogada;
}
