#include "tabuleiro.h"

int main()
{
    using namespace trabalho;
    using namespace std;
    /* Sequencia s1;
    Resposta r1;

    for(long unsigned int i=0; i<4;i++){
        std::cout << s1.get_bolas(i) << "\n";
    }
    for(long unsigned int i=0; i<8;i++){
        std::cout << r1.get_bolas_r(i) << "\n";
    } */
    Tabuleiro tabu;
    int n_jog;
    cout << "Bem Vindo ao MaterMind, escolha o numero de jogadores (1 ou 2):";
    cin >> n_jog;
    while (n_jog > 2 || n_jog < 1)
    {
        cout << "Numero de Jogadores inválido (1 ou 2):" << endl;
        cout << "Escolha o numero de jogadores de novo(1 ou 2):";
        cin >> n_jog;
    }
    if (n_jog == 1)
    {
        int dif = 0;
        while (dif < 1 || dif > 5)
        {
            cout << "Agora insira o nivel de dificuldade desejado: \n"
                 << "1 - Facil\n"
                 << "2 - Medio\n"
                 << "3 - Dificil\n"
                 << "4 - Impossivel\n"
                 << "5 - Personalizado\n";
            cin >> dif;
            if (dif < 1 || dif > 5)
                cout << "Dificuldade nao aceita! \n";
        }
        tabu.start_game_solo(dif);
    }
    if (n_jog == 2)
    {
        tabu.start_game_multiplayer();
    }
    tabu.rodada();
}