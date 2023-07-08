#include "baralho.h"
#include <cstdlib>
#include <ctime>

std::map<std::string, int> cartas;
std::vector<std::string> baralho;

void criarBaralho() {

    cartas["4 de Paus"] = 14;
        cartas["7 de Copas"] = 13;
        cartas["As de Espadas"] = 12;
        cartas["7 de Ouros"] = 11;
        cartas["3 de Paus"] = 10;
        cartas["3 de Copas"] = 10;
        cartas["3 de Espadas"] = 10;
        cartas["3 de Ouros"] = 10;
        cartas["2 de Paus"] = 9;
        cartas["2 de Copas"] = 9;
        cartas["2 de Espadas"] = 9;
        cartas["2 de Ouros"] = 9;
        cartas["As de Paus"] = 8;
        cartas["As de Copas"] = 8;
        cartas["As de Ouros"] = 8;
        cartas["K de Paus"] = 7;
        cartas["K de Copas"] = 7;
        cartas["K de Espadas"] = 7;
        cartas["K de Ouros"] = 7;
        cartas["J de Paus"] = 6;
        cartas["J de Copas"] = 6;
        cartas["J de Espadas"] = 6;
        cartas["J de Ouros"] = 6;
        cartas["Q de Paus"] = 5;
        cartas["Q de Copas"] = 5;
        cartas["Q de Espadas"] = 5;
        cartas["Q de Ouros"] = 5;
        cartas["7 de Paus"] = 4;
        cartas["7 de Espadas"] = 4;
        cartas["6 de Paus"] = 3;
        cartas["6 de Copas"] = 3;
        cartas["6 de Espadas"] = 3;
        cartas["6 de Ouros"] = 3;
        cartas["5 de Paus"] = 2;
        cartas["5 de Copas"] = 2;
        cartas["5 de Espadas"] = 2;
        cartas["5 de Ouros"] = 2;
        cartas["4 de Copas"] = 1;
        cartas["4 de Espadas"] = 1;
        cartas["4 de Ouros"] = 1;
    

    baralho.push_back("4 de Paus");
        baralho.push_back("7 de Copas");
        baralho.push_back("As de Espadas");
        baralho.push_back("7 de Ouros");
        baralho.push_back("3 de Paus");
        baralho.push_back("3 de Copas");
        baralho.push_back("3 de Espadas");
        baralho.push_back("3 de Ouros");
        baralho.push_back("2 de Paus");
        baralho.push_back("2 de Copas");
        baralho.push_back("2 de Espadas");
        baralho.push_back("2 de Ouros");
        baralho.push_back("As de Paus");
        baralho.push_back("As de Copas");
        baralho.push_back("As de Ouros");
        baralho.push_back("K de Paus");
        baralho.push_back("K de Copas");
        baralho.push_back("K de Espadas");
        baralho.push_back("K de Ouros");
        baralho.push_back("J de Paus");
        baralho.push_back("J de Copas");
        baralho.push_back("J de Espadas");
        baralho.push_back("J de Ouros");
        baralho.push_back("Q de Paus");
        baralho.push_back("Q de Copas");
        baralho.push_back("Q de Espadas");
        baralho.push_back("Q de Ouros");
        baralho.push_back("7 de Paus");
        baralho.push_back("7 de Espadas");
        baralho.push_back("6 de Paus");
        baralho.push_back("6 de Copas");
        baralho.push_back("6 de Espadas");
        baralho.push_back("6 de Ouros");
        baralho.push_back("5 de Paus");
        baralho.push_back("5 de Copas");
        baralho.push_back("5 de Espadas");
        baralho.push_back("5 de Ouros");
        baralho.push_back("4 de Copas");
        baralho.push_back("4 de Espadas");
        baralho.push_back("4 de Ouros");
    
}

std::pair<std::string, int> removerCartaAleatoria() {
    std::srand(std::time(0));
    int index = std::rand() % baralho.size();
    std::string carta = baralho[index];
    int valor = cartas[carta];

    baralho.erase(baralho.begin() + index);

    return std::make_pair(carta, valor);
}
