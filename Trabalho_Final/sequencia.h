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
        std::vector<std::string> cores = {"vermelho", "azul", "verde", "amarelo", "roxo", "laranja", "rosa", "ciano", "marrom", "bordo"};
        std::vector<std::string> bolas;

    public:
        // CONSTRUTORES:

        // METODOS:
        void imprime_cores(int n_cores);
        long unsigned get_posi_cor(std::string cor);
        std::string get_cor(long unsigned posi) const;
        std::string get_bolas(long unsigned int posi) const;
        void insere_bolas(std::string cor);
        void tira_bolas();
    };
}

#endif