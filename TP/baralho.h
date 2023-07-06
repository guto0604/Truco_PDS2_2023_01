#ifndef BARALHO_H
#define BARALHO_H

#include <string>
#include <map>
#include <vector>

#include "carta.h"

class Baralho{
public:
    void embaralhar();
    void darCarta();


private:

    Baralho();
    std::vector<Carta> baralho;

};

#endif
