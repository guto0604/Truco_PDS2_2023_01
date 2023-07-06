#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "baralho.h"
#include "jogador.h"
#include "placar.h"

int main() {
    

    std::vector<Jogador> jogadores(4);
    for (int i = 0; i < 4; ++i) {
        jogadores[i].setNumero(i+1);
        std::cout << "Digite o nome do Jogador " << i+1 << ": ";
        std::string nome;
        std::cin >> nome;
        jogadores[i].setNome(nome);
    }

    std::string nomeDupla1 = jogadores[0].getNome() + " - " + jogadores[2].getNome();
    std::string nomeDupla2 = jogadores[1].getNome() + " - " + jogadores[3].getNome();

    Placar placar(nomeDupla1, nomeDupla2);

    // Inicio de um Jogo, que se repete até alguem obter 12 pontos.
    while(! placar.verificarVencedor()) {


    criarBaralho();

    std::vector<std::pair<std::string, int>> cartasJogadores[4];

    // Distribute 3 cards to each player
    for (int i = 0; i < 12; ++i) {
        std::pair<std::string, int> carta = removerCartaAleatoria();
        cartasJogadores[i % 4].push_back(carta);
    }

    std::vector<int> chosenCards;
    std::vector<int> team1Scores(3, 0);  // Scores for Team 1 (players 1 and 3)
    std::vector<int> team2Scores(3, 0);  // Scores for Team 2 (players 2 and 4)

    for (int turn = 1; turn <= 3; ++turn) {
        std::cout << "=== Turno " << turn << " ===" << std::endl;

        int numCards = (turn == 1) ? 1 : (turn == 2) ? 2 : 1;

        // Choose cards for each player
        for (int i = 0; i < 4; ++i) {
             std::cout << "Jogador " << jogadores[i].getNumero() << " (" << jogadores[i].getNome() << "), escolha 1 carta:" << std::endl;

            std::cout << "  Cartas disponíveis:" << std::endl;
            for (int j = 0; j < cartasJogadores[i].size(); ++j) {
                std::cout << "    " << j+1 << ". " << cartasJogadores[i][j].first << std::endl;
            }

            int chosenCard;
            std::cout << "  Escolha o número da carta: ";
            std::cin >> chosenCard;

            while (chosenCard < 1 || chosenCard > cartasJogadores[i].size()) {
                std::cout << "Carta inválida. Tente novamente: ";
                std::cin >> chosenCard;
            }

            chosenCard--;  // Adjust input to match vector index (0-based)
            chosenCards.push_back(chosenCard);
        }

        std::cout << std::endl;

       std::cout << "Cartas escolhidas no turno " << turn << ":" << std::endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << "Jogador " << jogadores[i].getNumero() << " (" << jogadores[i].getNome() << "): " << cartasJogadores[i][chosenCards[i]].first << std::endl;
        }

        // Determine winners in the current turn
        int highestPlayer = -1;
        int highestValue = 0;
        bool tie = false;
        std::vector<int> highestPlayers;

        for (int i = 0; i < 4; ++i) {
            int cardValue = cartasJogadores[i][chosenCards[i]].second;
            if (cardValue > highestValue) {
                highestPlayers.clear();
                highestPlayer = i;
                highestValue = cardValue;
                tie = false;
            } else if (cardValue == highestValue) {
                tie = true;
                highestPlayers.push_back(i);
            }
}


        if (!tie) {
            if (highestPlayer == 0 || highestPlayer == 2) {
                // Team 1 (players 1 and 3) wins the round
                team1Scores[turn - 1]++;
                std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o turno!" << std::endl;
            } else {
                // Team 2 (players 2 and 4) wins the round
                team2Scores[turn - 1]++;
                std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o turno!" << std::endl;
            }
        } else {
            // Check if tie involves members of the same team or different teams
            bool sameTeam = true;
            for (int i = 0; i <= highestPlayers.size(); ++i) {
                if ((highestPlayers[i - 1] % 2) != (highestPlayers[i] % 2)) {
                    sameTeam = false;
                    break;
                }
            }
            
                
            if (sameTeam) {
                // Tie between members of the same team, the team wins the round
                int team = (highestPlayers[0] % 2) + 1;
                if (team == 1) {
                    team1Scores[turn - 1]++;
                    std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o turno!" << std::endl;
                } else {
                    team2Scores[turn - 1]++;
                    std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o turno!" << std::endl;
                }
            } else {
                // Tie between members of different teams, both teams get a point
                team1Scores[turn - 1]++;
                team2Scores[turn - 1]++;
                std::cout << "Empate! Ambas as duplas ganham um ponto." << std::endl;
            }
        }

        // Remove the chosen cards from the available options
        for (int i = 0; i < 4; ++i) {
            cartasJogadores[i].erase(cartasJogadores[i].begin() + chosenCards[i]);
        }

        chosenCards.clear();

        if(turn == 2){
            int team1TotalScore = 0;
            int team2TotalScore = 0;

            for (int i = 0; i < 3; ++i) {
                team1TotalScore += team1Scores[i];
                team2TotalScore += team2Scores[i];
    }
        if(team1TotalScore == team2TotalScore){} // Condição de ir para o terceiro turno
        else{std::cout << std::endl;
            break;
            }
        }

        std::cout << std::endl;
    }

    // Display the final result
    int team1TotalScore = 0;
    int team2TotalScore = 0;

    for (int i = 0; i < 3; ++i) {
        team1TotalScore += team1Scores[i];
        team2TotalScore += team2Scores[i];
    }

    if (team1TotalScore > team2TotalScore) {
        std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o jogo!" << std::endl;

        placar.incrementarPlacarDupla1(6);

        std::cout << team1TotalScore << " x " << team2TotalScore << std::endl;

    } else if (team2TotalScore > team1TotalScore) {
        std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o jogo!" << std::endl;

        placar.incrementarPlacarDupla2(6);

        std::cout << team1TotalScore << " x " << team2TotalScore << std::endl;

    } else if(team1Scores[0] == 1){
        std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o jogo! " << "Venceu a primeira mão!" << std::endl;

        placar.incrementarPlacarDupla1(2);

        std::cout << team1TotalScore << " x " << team2TotalScore  <<std::endl;
    }
    else{
        std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o jogo! " << "Venceu a primeira mão!" << std::endl;

        placar.incrementarPlacarDupla2(2);

        std::cout << team1TotalScore << " x " << team2TotalScore  <<std::endl;
    }

    placar.imprimirPlacar();

    } // Fim do loop de placar < 12
   
    
    placar.imprimirParabens();

    placar.imprimirTrofeu();
    
    return 0;
}
