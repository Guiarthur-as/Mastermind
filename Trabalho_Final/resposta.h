#ifndef RESPOSTA_H
#define RESPOSTA_H

#include "sequencia.h"

namespace trabalho{
    class Resposta : public Sequencia 
    {
        std::vector<std::string> cores_resposta = {"cinza","branco","preto"};

    public:
        //CONSTRUTORES:
        //explicit Resposta();
        // METODO:
        void preenche_cinza(long unsigned tam_);
        void troca_bola(long unsigned posi_, long unsigned posi_cores_resp);
        std::string get_bolas_r(long unsigned posi) const;
    };
}
#endif