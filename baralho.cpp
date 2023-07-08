/**
 * @file baralho.cpp
 * @brief Implementação das funções relacionadas ao baralho de cartas.
 */

#include "baralho.h"
#include <cstdlib>
#include <ctime>

std::map<std::string, int> cartas; /**< Mapa para armazenar o valor das cartas. */
std::vector<std::string> baralho; /**< Vetor para armazenar as cartas do baralho. */

/**
 * @brief Cria o baralho de cartas.
 *
 * Esta função preenche o mapa `cartas` com o valor das cartas e o vetor `baralho` com as cartas do baralho.
 */
void criarBaralho() {
    // Inicializa o mapa cartas com os valores das cartas
    cartas["4 de Paus"] = 14;
    cartas["7 de Copas"] = 13;
    cartas["As de Espadas"] = 12;
    // ...

    // Adiciona as cartas ao vetor baralho
    baralho.push_back("4 de Paus");
    baralho.push_back("7 de Copas");
    baralho.push_back("As de Espadas");
    // ...
}

/**
 * @brief Remove uma carta aleatória do baralho.
 * @return Um par contendo a carta removida e seu valor.
 */
std::pair<std::string, int> removerCartaAleatoria() {
    std::srand(std::time(0));
    int index = std::rand() % baralho.size();
    std::string carta = baralho[index];
    int valor = cartas[carta];

    baralho.erase(baralho.begin() + index);

    return std::make_pair(carta, valor);
}
