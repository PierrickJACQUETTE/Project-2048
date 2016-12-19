#include "Jeu_Sokoban.hpp"
using namespace std;

Jeu_Sokoban::Jeu_Sokoban(int x, int y) : Jeu(x,y) {}

Jeu_Sokoban::~Jeu_Sokoban() {}

bool Jeu_Sokoban::fini()
{
    return true;
}

void Jeu_Sokoban::unTour(int) {}

bool Jeu_Sokoban::aGagne()
{
    return false;
}
