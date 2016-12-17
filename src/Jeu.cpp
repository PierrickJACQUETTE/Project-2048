#include "Jeu.hpp"

using namespace std;

Jeu::Jeu(int x, int y): plateau(Plateau(x,y)) {}

Jeu::~Jeu() {}

Plateau Jeu::getPlateau() const
{
    return plateau;
}

void Jeu::setPlateau(Plateau p)
{
    plateau=p;
}

bool Jeu::lancerException(bool b, string s)
{
    if (b)
    {
        throw string(s);
        return false;
    }
    return true;
}

void Jeu::affiche() {}
