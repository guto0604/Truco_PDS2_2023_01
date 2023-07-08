#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

class Jogador {
private:
    int numero;
    std::string nome;

public:
    Jogador();
    void setNumero(int numero);
    void setNome(const std::string& nome);
    int getNumero() const;
    std::string getNome() const;
};

#endif
