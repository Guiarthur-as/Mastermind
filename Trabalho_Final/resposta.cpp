#include "resposta.h"

namespace trabalho
{
    // CONSTRUTORES:
    /* Resposta::Resposta(){
        bolas_r.push_back(cores_resposta[0]);
    } */

    // MÉTODOS:
    void Resposta::preenche_cinza(long unsigned tam_)
    {
        //bolas.assign(tam_,cores_resposta[0]);
        for (long unsigned i = 0; i < tam_; i++)
            bolas.push_back(cores_resposta[0]);
    }

    void Resposta::troca_bola(long unsigned posi_, long unsigned posi_cores_resp)
    {
        std::vector<std::string>::iterator it = bolas.begin()+static_cast<long>(posi_);
        bolas.erase(it);
        bolas.insert(it,cores_resposta[posi_cores_resp]);
    }

    std::string Resposta::get_bolas_r(long unsigned int posi) const
    {
        return bolas[posi];
    }
}