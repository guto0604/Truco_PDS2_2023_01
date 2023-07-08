#ifndef PLACAR_H
#define PLACAR_H

#include <string>

class Placar {
private:
    std::string nomeDupla1;
    std::string nomeDupla2;
    int placarDupla1;
    int placarDupla2;

public:
    Placar();
    Placar(const std::string& nomeDupla1, const std::string& nomeDupla2);
    void incrementarPlacarDupla1(int pontos);
    void incrementarPlacarDupla2(int pontos);
    bool verificarVencedor() const;
    void imprimirParabens() const;
    void imprimirTrofeu() const;
    void imprimirPlacar() const;
};

#endif
