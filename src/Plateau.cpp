#include "Plateau.hpp"
using namespace std;

Plateau::Plateau(int x, int y) {}

Plateau::~Plateau() {}

int Plateau::getTaille() const
{
    return taille;
}

int Plateau::getNbX() const
{
    return nbX;
}

int Plateau::getNbY() const
{
    return nbX;
}

std::vector<Case> Plateau::getPlateau() const
{
    return plateau;
}

void Plateau::setCase(Case c, int x, int y)
{

    plateau[nbX*y+x] = c;

}

bool Plateau::isFull() const
{
    return true;
}

ostream& operator <<(ostream& out, Plateau p)
{
    return out;
}
