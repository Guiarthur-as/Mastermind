#include "tabuleiro.h"

namespace trabalho
{
    // CONSTRUTORES:
    Tabuleiro::Tabuleiro()
    {
        palpites = 4;
        dificuldade = 1;
        cores_rep = false;
    }
    // MÉTODOS PRIVADOS:
    long unsigned Tabuleiro::numero_rand(int ncores)
    {
        std::random_device r;
        std::uniform_int_distribution<int> uniform_dist(0, ncores - 1);
        return static_cast<long unsigned>(uniform_dist(r));
    }
    void Tabuleiro::inicia_dif(int n_cores_, long unsigned tam_, int palpites_, bool cores_rep_)
    {
        palpites = palpites_;
        cores_rep = cores_rep_;
        n_cores = n_cores_;
        tam = tam_;

        long unsigned posi_cores[tam_], i = 0;

        if (!cores_rep_)
        {
            int count = 0;
            while (i < tam_)
            {
                posi_cores[i] = numero_rand(n_cores_);
                for (long unsigned int j = 0; j < i; j++)
                    if (posi_cores[i] == posi_cores[j])
                        count++;
                if (!count)
                {
                    std::cout << posi_cores[i] << "\n"; // PRINTS
                    i++;
                }
                count = 0;
            }
        }
        else
        {
            while (i < tam_)
            {
                posi_cores[i] = numero_rand(n_cores_);
                i++;
            }
        }
        mestre.tira_bolas();
        for (long unsigned j = 0; j < tam_; j++)
        {
            mestre.insere_bolas(mestre.get_cor(posi_cores[j]));
            std::cout << mestre.get_bolas(j) << "\n"; // PRINTS
        }
    }
    void Tabuleiro::inicia_rod()
    {
        turno++;
        std::cout << "Turno: " << turno << "\n";
        mestre.imprime_cores(n_cores);

        long unsigned posi_cores[tam];
        Sequencia chute_atual;
        std::cout << "Escolha " << tam << " cores do chute na sequencia desejada:\n";
        for (long unsigned i = 0; i < tam; i++)
        {
            std::cin >> posi_cores[i];
            chute_atual.insere_bolas(chute_atual.get_cor(posi_cores[i]));
            std::cout << chute_atual.get_bolas(i) << "\n"; // PRINTS
        }
        chutes.push_back(chute_atual);
    }
    void Tabuleiro::compara()
    {
        long unsigned rep[static_cast<long unsigned>(n_cores)];
        for (long unsigned i = 0; i < static_cast<long unsigned>(n_cores); i++)
        {
            rep[i] = 0;
            for (long unsigned j = 0; j < tam; j++)
                if (mestre.get_cor(i) == mestre.get_bolas(j))
                    rep[i]++;
        }
        for (long unsigned i = 0; i < static_cast<long unsigned>(n_cores); i++) //PRINTS
            std::cout << rep[i] << " "; //PRINTS
        std::cout << "\n"; //PRINTS
        Resposta resposta_atual;
        resultados.push_back(resposta_atual);
        //preenche de cinza//
        resultados[turno - 1].preenche_cinza(tam);
        for (long unsigned i = 0; i < static_cast<long unsigned>(n_cores); i++) //PRINTS
            std::cout << rep[i] << " "; //PRINTS
        std::cout << "\n"; //PRINTS
        //coloca as pretas//
        for (long unsigned i = 0; i < tam; i++)
        {
            if (chutes[turno - 1].get_bolas(i) == mestre.get_bolas(i)){
                resultados[turno - 1].troca_bola(i, 2);
                rep[mestre.get_posi_cor(mestre.get_bolas(i))]--;
            }
        }
        for (long unsigned i = 0; i < static_cast<long unsigned>(n_cores); i++) //PRINTS
            std::cout << rep[i] << " "; //PRINTS
        std::cout << "\n"; //PRINTS
        // coloca as brancas//
        for (long unsigned i = 0; i < tam; i++)
        {
            for (long unsigned j = 0; j < tam; j++)
            {
                if (chutes[turno - 1].get_bolas(i) == mestre.get_bolas(j) && chutes[turno - 1].get_bolas(i) != mestre.get_bolas(i)){
                    if(rep[chutes[turno-1].get_posi_cor(chutes[turno-1].get_bolas(i))] > 0)
                        resultados[turno - 1].troca_bola(i, 1);
                }
            }
        }
    }
    // MÉTODOS PÚBLICOS:
    int Tabuleiro::get_palpite() const
    {
        return palpites;
    }
    bool Tabuleiro::get_cores_rep() const
    {
        return cores_rep;
    }
    int Tabuleiro::get_dificuldade() const
    {
        return dificuldade;
    }
    void Tabuleiro::start_game_solo(int dif)
    {
        using namespace std;
        turno = 0;
        dificuldade = dif;
        switch (dif)
        {
        case 1:
            inicia_dif(4, 4, 10, false);
            break;
        case 2:
            inicia_dif(6, 5, 8, false);
            break;
        case 3:
            inicia_dif(8, 6, 6, true);
            break;
        case 4:
            inicia_dif(10, 6, 4, true);
            break;
        case 5:
        {
            int a = -1;
            for (;;)
            {

                cout << "Personalize seu nivel de dificuldade: \n"
                     << "Numero de Palpites Maximo (4-10):";
                cin >> palpites;
                cout << "É permitido cores repetidas? (1 para sim - 0 para nao):"; // colocar Y/N e implementar condições
                cin >> a;
                cout << "Numero de cores maxima para a sequencia (4-10):";
                cin >> n_cores;
                cout << "Tamanho da Sequencia (4-6):";
                cin >> tam;
                if (palpites < 4 || palpites > 10 || a > 1 || a < 0 || n_cores < 4 || n_cores > 10 || tam < 4 || tam > 6)
                    cout << "\nAte isso voce erra! Faça de novo: \n";
                else
                {
                    cores_rep = a;
                    break;
                }
            }
            inicia_dif(n_cores, tam, palpites, cores_rep);
            break;
        }
        default:
            cout << "escolheu errado seu burro";
            break;
        }
    }
    void Tabuleiro::start_game_multiplayer()
    {
    }
    void Tabuleiro::rodada()
    {
        inicia_rod();
        compara();
        for (long unsigned i = 0; i < tam; i++) //PRINTS
            std::cout << resultados[turno - 1].get_bolas(i) << "\n"; //PRINTS
    }
}
