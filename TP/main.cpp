#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "baralho.h"
#include "carta.h"
#include "dupla.h"
#include "jogador.h"
#include "mao.h"
#include "partida.h"
#include "rodada.h"

int main() {
    
    bool jogar = true;
    while(jogar){

        std::cout << "Regras do truco mineiro:";

        std::cout << "Deseja jogar uma partida de truco mineiro?";
        std::string resposta;
        std::cin >> resposta;

        if(resposta == "Nao"){
            jogar = false;
        }

        if(jogar){
            std::vector<Jogador> jogadores(4);
            for (int i = 0; i < 4; ++i) {
                std::cout << "Digite o nome do Jogador " << i+1 << ": ";
                std::string nome;
                std::cin >> nome;
                Jogador j(i, nome, i%2);
                jogadores[i] = j;
            }

            Partida p(jogadores);
        }
        
    }
    
    return 0;
}
