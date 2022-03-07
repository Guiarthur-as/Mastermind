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

#include <iostream>
#include <vector>

/* enum class Cores_sequencia
{
    vermelho,
    azul,
    verde,
    amarelo,
    roxo,
    laranja,
    rosa,
    ciano,
    marrom,
    bordo
}; */

enum class Cores_resposta
{
    preto,
    cinza,
    branco
};

class Sequencia
{
    std::vector<std::string> Cores = {"vermelho", "azul", "verde", "amarelo", "roxo", "laranja", "rosa", "ciano", "marrom", "bordo"};
    int n_cores;
    long unsigned int tam;
    int palpites;
    bool cores_rep;
    int dificuldade;

public:
    std::vector<std::string> Bolas;
    Sequencia()
    {
        n_cores = 4;
        tam = 4;
        palpites = 4;
        cores_rep = false;
        dificuldade = 1;
        for (long unsigned int i = 0; i < tam; i++)
        {
            Bolas.push_back(Cores[i]);
        }
    }
};