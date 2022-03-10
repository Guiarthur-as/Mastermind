#ifndef RESPOSTA_H
#define RESPOSTA_H

#include "sequencia.h"

namespace trabalho{
    class Resposta : public Sequencia 
    {
        std::vector<std::string> cores_resposta = {"preto", "cinza", "branco"};

    public:
        explicit Resposta();
        // METODO:
        std::string get_bolas_r(long unsigned int posi) const;
    };
}
#endif