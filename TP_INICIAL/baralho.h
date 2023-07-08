/**
 * @file baralho.h
 * @brief Definições e declarações relacionadas ao baralho de cartas.
 */

#ifndef BARALHO_H
#define BARALHO_H

#include <string>
#include <map>
#include <vector>

/**
 * @brief Mapa que armazena o valor das cartas.
 *
 * Este mapa associa o nome de cada carta ao seu valor correspondente.
 */
extern std::map<std::string, int> cartas;

/**
 * @brief Vetor que armazena as cartas do baralho.
 *
 * Este vetor contém todas as cartas presentes no baralho.
 */
extern std::vector<std::string> baralho;

/**
 * @brief Cria o baralho de cartas.
 *
 * Esta função preenche o mapa `cartas` com o valor das cartas e o vetor `baralho` com as cartas do baralho.
 */
void criarBaralho();

/**
 * @brief Remove uma carta aleatória do baralho.
 * @return Um par contendo a carta removida e seu valor.
 */
std::pair<std::string, int> removerCartaAleatoria();

#endif // BARALHO_H
