#include "mao.h"
#include <iostream>

void Mao::darCartas(){
    baralho.embaralhar();
    for(int j = 0; j < 4; j++){
        ordem[j].receberCartas(baralho, j);
    }


}



