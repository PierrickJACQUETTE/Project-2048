#include "Jeu_Taquin.hpp"
using namespace std;

Jeu_Taquin::Jeu_Taquin(int x, int y ) : Jeu(x,y) {}

Jeu_Taquin::~Jeu_Taquin() {}

bool Jeu_Taquin::fini()
{
    return true;
}

void Jeu_Taquin::affiche() {}

void Jeu_Taquin::unTour() {}

void Jeu_Taquin::aGagne() {}

void Jeu_Taquin::lancerPartie() {}

void Jeu_Taquin::simulerPartie() {}

bool Jeu_Taquin::jeu_Possible()
{
    return true;   // test si le jeu est possible
}
