#include "sequencia.h"

namespace trabalho
{
    // CONSTRUTORES:
    Sequencia::Sequencia()
    {
        n_cores = 4;
        tam = 4;
        for (long unsigned int i = 0; i < tam; i++)
        {
            bolas.push_back(cores[i]);
        }
    }
    // METODOS:
    int Sequencia::get_n_cores() const
    {
        return n_cores;
    }

    long unsigned int Sequencia::get_tam() const
    {
        return tam;
    }

    std::string Sequencia::get_bolas(long unsigned int posi) const
    {
        return bolas[posi];
    }
    
    void Sequencia::tira_bolas()
    {
        for (long unsigned int i = 0; i < tam; i++)
        {
            bolas.pop_back();
        }
        tam = 0;
    }
}