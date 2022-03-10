#include "resposta.h"

namespace trabalho
{
    //CONSTRUTORES:
    Resposta::Resposta()
    {
        tira_bolas();
        tam = 4;
        for (long unsigned int i = 0; i < tam; i++)
        {
            bolas.push_back(cores_resposta[1]);
        }
    }
    //MÉTODOS:
    std::string Resposta::get_bolas_r(long unsigned int posi) const
        {
            return bolas[posi];
        }
}