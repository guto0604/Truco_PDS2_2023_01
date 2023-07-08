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
    jogadores[i].setNumero(i + 1);

    std::string nome;
    bool nomeValido = false;

    while (!nomeValido) {
        std::cout << "Digite o nome do Jogador " << i + 1 << ": ";
        std::cin >> nome;

        // Verificar se o nome tem mais de dois dígitos
        if (nome.length() > 2) {
            // Verificar se o nome contém apenas caracteres (letras)
            bool apenasCaracteres = true;
            for (char c : nome) {
                if (!isalpha(c)) {
                    apenasCaracteres = false;
                    break;
                }
            }

            // Verificar se o nome não contém a contrabarra '\'
            bool semContrabarra = (nome.find('\\') == std::string::npos);

            if (apenasCaracteres && semContrabarra) {
                nomeValido = true;
            } else {
                std::cout << "Nome inválido. Digite novamente." << std::endl;
            }
        } else {
            std::cout << "Nome inválido. Digite novamente." << std::endl;
        }
    }

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
    std::vector<int> team1Scores(3, 0);  // Pontuacao time 1 (Jogador 1 e 3)
    std::vector<int> team2Scores(3, 0);  // Pontuacao time 2 (Jogador 2 e 4)
    
    int valor_da_mao;

    for (int turn = 1; turn <= 3; ++turn) {
        if(turn == 1){valor_da_mao = 2;}
        std::cout << "=== Turno " << turn << " ===" << std::endl;
        

        int numCards = (turn == 1) ? 1 : (turn == 2) ? 2 : 1;

        // Escolhe as cartas para cada jogador
        for (int i = 0; i < 4; ++i) {
             std::cout << "Jogador " << jogadores[i].getNumero() << " (" << jogadores[i].getNome() << "), escolha 1 carta:" << std::endl;

            std::cout << "  Cartas disponíveis:" << std::endl;
            for (int j = 0; j < cartasJogadores[i].size(); ++j) {
                std::cout << "    " << j+1 << ". " << cartasJogadores[i][j].first << std::endl;
            }

            int chosenCard;
            if(valor_da_mao == 2){
                std::cout << "  Escolha o número da carta (Ou 4 para trucar):  ";
            }
            
            else{std::cout << "  Escolha o número da carta:  ";}
            
            std::cin >> chosenCard;

            while (chosenCard < 1 || chosenCard > cartasJogadores[i].size() && chosenCard != 4 ) {
                std::cout << "Carta inválida. Tente novamente: ";
                std::cin.clear();               // Limpa o estado do fluxo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cin >> chosenCard;
            }


            // Truco ------------------------------------------------------------------
            int aceita_corre;
            if(chosenCard == 4){
                std::cout << "TRUCOOO. Deseja aceitar?" << std::endl;
                std::cout << "1- Aceitar" << std::endl;
                std::cout << "2- Correr" << std::endl;
                std::cout << "3- Pedir 6" << std::endl;
                std::cin >> aceita_corre;

                while (aceita_corre < 1 && aceita_corre > 3){
                    std::cout << "Valor Inválido. Tente novamente: ";
                    std::cin.clear();               // Limpa o estado do fluxo de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                    std::cin >> aceita_corre;
                }

                if(aceita_corre == 1){
                    valor_da_mao = 4;
                    std::cout << " Escolha o número da carta: ";
                    std::cin >> chosenCard;
 
                    while (chosenCard < 1 || chosenCard > cartasJogadores[i].size()) {
                std::cout << "Carta inválida. Tente novamente: ";
                std::cin.clear();               // Limpa o estado do fluxo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cin >> chosenCard;
                }
                    }

                else if(aceita_corre == 2){
                    if(jogadores[i].getNumero() == 1 || jogadores[i].getNumero() == 3){team1Scores[turn]= 10;goto correu;} // Pelo que pesquisei sair de loops aninhados é uma das
                    if(jogadores[i].getNumero() == 2 || jogadores[i].getNumero() == 4){team2Scores[turn]= 10;goto correu;} // Unicas situações que goto é algo 'aceitável'
                }

                // Pediu 6 ------------------------------------------------------------------
                else if(aceita_corre == 3){
                valor_da_mao = 4;
                std::cout << "SEIS LADRÃO. Deseja aceitar?" << std::endl;
                std::cout << "1- Aceitar" << std::endl;
                std::cout << "2- Correr" << std::endl;
                std::cout << "3- Pedir 9" << std::endl;
                std::cin >> aceita_corre;

                while (aceita_corre < 1 && aceita_corre > 3){
                    std::cout << "Valor Inválido. Tente novamente: ";
                    std::cin.clear();               // Limpa o estado do fluxo de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                    std::cin >> aceita_corre;
                }

                if(aceita_corre == 1){
                    valor_da_mao = 6;
                    std::cout << " Escolha o número da carta: ";
                    std::cin >> chosenCard;
 
                    while (chosenCard < 1 || chosenCard > cartasJogadores[i].size()) {
                std::cout << "Carta inválida. Tente novamente: ";
                std::cin.clear();               // Limpa o estado do fluxo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cin >> chosenCard;
                }
                    }

                else if(aceita_corre == 2){
                    if(jogadores[i].getNumero() == 1 || jogadores[i].getNumero() == 3){team2Scores[turn]= 10;goto correu;} // Pelo que pesquisei sair de loops aninhados é uma das
                    if(jogadores[i].getNumero() == 2 || jogadores[i].getNumero() == 4){team1Scores[turn]= 10;goto correu;} // Unicas situações que goto é algo 'aceitável'
                }
                // Pediu 9 ------------------------------------------------------------------
                else if(aceita_corre == 3){
                valor_da_mao = 6;
                std::cout << "NOVEEE. Deseja aceitar?" << std::endl;
                std::cout << "1- Aceitar" << std::endl;
                std::cout << "2- Correr" << std::endl;
                std::cout << "3- Pedir 12" << std::endl;
                std::cin >> aceita_corre;

                while (aceita_corre < 1 && aceita_corre > 3){
                    std::cout << "Valor Inválido. Tente novamente: ";
                    std::cin.clear();               // Limpa o estado do fluxo de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                    std::cin >> aceita_corre;
                }

                if(aceita_corre == 1){
                    valor_da_mao = 10;
                    std::cout << " Escolha o número da carta: ";
                    std::cin >> chosenCard;
 
                    while (chosenCard < 1 || chosenCard > cartasJogadores[i].size()) {
                std::cout << "Carta inválida. Tente novamente: ";
                std::cin.clear();               // Limpa o estado do fluxo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cin >> chosenCard;
                }
                    }

                else if(aceita_corre == 2){
                    if(jogadores[i].getNumero() == 1 || jogadores[i].getNumero() == 3){team1Scores[turn]= 10;goto correu;} // Pelo que pesquisei sair de loops aninhados é uma das
                    if(jogadores[i].getNumero() == 2 || jogadores[i].getNumero() == 4){team2Scores[turn]= 10;goto correu;} // Unicas situações que goto é algo 'aceitável'
                }
                // Pediu 12 ------------------------------------------------------------------
                else if(aceita_corre == 3){
                    valor_da_mao = 10;
                std::cout << "DOOZE. Deseja aceitar?" << std::endl;
                std::cout << "1- Aceitar" << std::endl;
                std::cout << "2- Correr" << std::endl;
                std::cin >> aceita_corre;

                while (aceita_corre < 1 && aceita_corre > 2){
                    std::cout << "Valor Inválido. Tente novamente: ";
                    std::cin.clear();               // Limpa o estado do fluxo de entrada
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                    std::cin >> aceita_corre;
                }

                if(aceita_corre == 1){
                    valor_da_mao = 12;
                    std::cout << " Escolha o número da carta: ";
                    std::cin >> chosenCard;
 
                    while (chosenCard < 1 || chosenCard > cartasJogadores[i].size()) {
                std::cout << "Carta inválida. Tente novamente: ";
                std::cin.clear();               // Limpa o estado do fluxo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada inválida
                std::cin >> chosenCard;
                }
                    }

                else if(aceita_corre == 2){
                    if(jogadores[i].getNumero() == 1 || jogadores[i].getNumero() == 3){team2Scores[turn]= 10;goto correu;} // Pelo que pesquisei sair de loops aninhados é uma das
                    if(jogadores[i].getNumero() == 2 || jogadores[i].getNumero() == 4){team1Scores[turn]= 10;goto correu;} // Unicas situações que goto é algo 'aceitável'
                }
                }
                }
                }

            }
            

            // Fim dos trucos
            chosenCard--;  
            chosenCards.push_back(chosenCard);
        }

        std::cout << std::endl;

       std::cout << "Cartas escolhidas no turno " << turn << ":" << std::endl;
        for (int i = 0; i < 4; ++i) {
            std::cout << "Jogador " << jogadores[i].getNumero() << " (" << jogadores[i].getNome() << "): " << cartasJogadores[i][chosenCards[i]].first << std::endl;
        }

        // Determina o voencedor do turno
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
                // Time 1 vence
                team1Scores[turn - 1]++;
                std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o turno!" << std::endl;
            } else {
                // Time 2 vence
                team2Scores[turn - 1]++;
                std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o turno!" << std::endl;
            }
        } else {
            // Checa empate no mesmo time
            bool sameTeam = true;
            for (int i = 0; i <= highestPlayers.size(); ++i) {
                if ((highestPlayers[i - 1] % 2) != (highestPlayers[i] % 2)) {
                    sameTeam = false;
                    break;
                }
            }
            
                
            if (sameTeam) {
                // Empate do mesmo time
                int team = (highestPlayers[0] % 2) + 1;
                if (team == 1) {
                    team1Scores[turn - 1]++;
                    std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o turno!" << std::endl;
                } else {
                    team2Scores[turn - 1]++;
                    std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o turno!" << std::endl;
                }
            } else {
                // Empate de times diferentes
                team1Scores[turn - 1]++;
                team2Scores[turn - 1]++;
                std::cout << "Empate! Ambas as duplas ganham um ponto." << std::endl;
            }
        }

        // Tira as cartas das opcoes
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

    // Resultado final
    correu:
    
    int team1TotalScore = 0;
    int team2TotalScore = 0;

    for (int i = 0; i < 3; ++i) {
        team1TotalScore += team1Scores[i];
        team2TotalScore += team2Scores[i];
    }

    if (team1TotalScore > team2TotalScore) {
        std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o jogo!" << std::endl;

        placar.incrementarPlacarDupla1(valor_da_mao);

        std::cout << team1TotalScore << " x " << team2TotalScore << std::endl;

    } else if (team2TotalScore > team1TotalScore) {
        std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o jogo!" << std::endl;

        placar.incrementarPlacarDupla2(valor_da_mao);

        std::cout << team1TotalScore << " x " << team2TotalScore << std::endl;

    } else if(team1Scores[0] == 1){
        std::cout << "Dupla 1 (Jogador 1 e Jogador 3) venceu o jogo! " << "Venceu a primeira mão!" << std::endl;

        placar.incrementarPlacarDupla1(valor_da_mao);

        std::cout << team1TotalScore << " x " << team2TotalScore  <<std::endl;
    }
    else{
        std::cout << "Dupla 2 (Jogador 2 e Jogador 4) venceu o jogo! " << "Venceu a primeira mão!" << std::endl;

        placar.incrementarPlacarDupla2(valor_da_mao);

        std::cout << team1TotalScore << " x " << team2TotalScore  <<std::endl;
    }

    placar.imprimirPlacar();

    } // Fim do loop de placar < 12
   
    
    placar.imprimirParabens();

    placar.imprimirTrofeu();
    
    return 0;
}
