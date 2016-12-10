#include "Jeu.hpp"

Jeu::Jeu(int x, int y): plateau(Plateau(x,y)) {}

Jeu::~Jeu() {}

Plateau Jeu::getPlateau() const
{
    return plateau;
}
