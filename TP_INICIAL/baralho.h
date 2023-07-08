#ifndef BARALHO_H
#define BARALHO_H

#include <string>
#include <map>
#include <vector>

extern std::map<std::string, int> cartas;
extern std::vector<std::string> baralho;

void criarBaralho();
std::pair<std::string, int> removerCartaAleatoria();

#endif
