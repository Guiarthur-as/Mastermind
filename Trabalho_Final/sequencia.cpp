#include "sequencia.h"

namespace trabalho
{
    // CONSTRUTORES:
    // METODOS:
    void Sequencia::imprime_cores(int n_cores_)
    {
        for (long unsigned i = 0; i < static_cast<long unsigned>(n_cores_); i++)
            std::cout << i << ". " << cores[i] << "\n";
    }

    long unsigned Sequencia::get_posi_cor(std::string cor)
    {
        for (long unsigned i = 0; i < cores.size(); i++)
            if(cores[i] == cor)
                return i;
        return 20000;
    }
    std::string Sequencia::get_cor(long unsigned posi) const
    {
        return cores[posi];
    }

    std::string Sequencia::get_bolas(long unsigned int posi) const
    {
        return bolas[posi];
    }

    void Sequencia::insere_bolas(std::string cor)
    {
        bolas.push_back(cor);
    }

    void Sequencia::tira_bolas()
    {
        for (long unsigned int i = 0; i < bolas.size(); i++)
        {
            bolas.pop_back();
        }
    }
}