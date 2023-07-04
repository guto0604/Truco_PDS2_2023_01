#include <iostream>
#include <vector>
#include "baralho.h"

int main() {
    criarBaralho();

    std::vector<std::pair<std::string, int>> cartasJogadores[4];

    for (int i = 0; i < 12; ++i) {
        std::pair<std::string, int> carta = removerCartaAleatoria();
        cartasJogadores[i % 4].push_back(carta);
    }

    for (int i = 0; i < 4; ++i) {
        std::cout << "Jogador " << i+1 << ":" << std::endl;
        for (const auto& carta : cartasJogadores[i]) {
            std::cout << "  Carta: " << carta.first << ", Valor: " << carta.second << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
