#ifndef SEQUENCIA_H
#define SEQUENCIA_H

#include <iostream>
#include <vector>

namespace trabalho
{
    class Sequencia
    {
        // VARIAVEIS:
    protected:
        int n_cores;
        long unsigned int tam;

    public:
        std::vector<std::string> cores = {"vermelho", "azul", "verde", "amarelo", "roxo", "laranja", "rosa", "ciano", "marrom", "bordo"};
        std::vector<std::string> bolas;
        // CONSTRUTORES:
        explicit Sequencia();

        // METODOS:

        int get_n_cores() const;
        long unsigned int get_tam() const;
        std::string get_bolas(long unsigned int posi) const;
        void tira_bolas();
    };
}

#endif