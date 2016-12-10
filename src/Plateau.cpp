#include "Plateau.hpp"
using namespace std;

Plateau::Plateau(int x, int y) {}

Plateau::~Plateau() {}

int Plateau::getSize() const
{
    return 0;   // retourne x*y
}

int Plateau::getNbX() const
{
    return 0;
}

int Plateau::getNbY() const
{
    return 0;
}

std::vector<Case> Plateau::getPlateau() const
{
    return plateau;
}

void Plateau::setCase(Case c) {}

bool Plateau::isFull() const
{
    return true;
}

ostream& operator <<(ostream& out, Plateau p)
{
    return out;
}
