#include "baralho.h"
#include <cstdlib>
#include <ctime>

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

void Baralho::embaralhar(){

    unsigned seed = time(0);
    for (int i = 39; i >= 0; i--) {
        int j = rand() % (i + 1);
        Carta tmp = baralho[j];
        baralho[j] = baralho[i];
        baralho[i] = tmp;
    }

}

