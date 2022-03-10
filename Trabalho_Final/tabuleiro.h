/* O jogo deve possibilitar:

Escolher o número de cores utilizados no jogo (4-10);
Escolher o tamanho do código (4 - 6);
Escolher o número máximo de palpites (4-10);
Escolher se pode haver cores repetidas;
Ter a opção de duas pessoas possam jogar uma partida;
Poder jogar contra o computador com diferentes níveis de dificuldade.
A implementação deve conter:

Classe(s), atributos e métodos;
Encapsulamento respeitados por todas as classes;
Uso de associação (agregação, composição ou dependência);
Alocação dinâmica de memória (aplicação do uso de ponteiros inteligentes);
Sobrecarga de operação;
Herança;
Use C++17;
Deve executar em Linux;
Polimorfismo*; e
Padrões de projeto*.
(*) -> Opcional */
#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "resposta.h"
#include <random>
#include <memory>

namespace trabalho
{
    
    class Tabuleiro
    {
        // VARIÁVEIS PRIVADAS:
        Sequencia mestre;
        std::vector<Sequencia> chutes;
        std::vector<Resposta> resultados;
        int n_cores;
        long unsigned int tam;
        int palpites;
        int turno;
        bool cores_rep;
        int dificuldade;
        //MÉTODOS PRIVADOS:
        long unsigned numero_rand(int ncores);
        void inicia_dif(int n_cores_, long unsigned tam_, int palpites_, bool cores_rep_);

    public:
        // CONSTRUTORES:
        Tabuleiro();

        // MÉTODOS PÚBLICOS:
        int get_palpite() const;
        bool get_cores_rep() const;
        int get_dificuldade() const;
        void start_game_multiplayer();
        void start_game_solo(int dif);
    };
}

#endif  