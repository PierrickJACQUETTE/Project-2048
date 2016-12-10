#include "Jeu_2048_destroy.hpp"
#include "Jeu_2048_double.hpp"
#include "Jeu_2048_neg.hpp"
#include "Jeu_2048.hpp"
#include "Jeu_Sokoban.hpp"
#include "Jeu_Taquin.hpp"
#include "Case.hpp"

using namespace std;

int main()
{
    TypeCase c = TypeCase::Mur;
    Case case1(c, 1,1);
    cout << case1 << endl;
    return 0;
}
