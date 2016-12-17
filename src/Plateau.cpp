#include "Plateau.hpp"

using namespace std;

Plateau::Plateau(int x, int y) : nbX(x), nbY(y)
{
    taille = x*y;
    plateau.resize(nbY, vector<Case>(nbX));
}

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
    return nbY;
}

vector<vector<Case>> Plateau::getPlateau() const
{
    return plateau;
}

Case Plateau::getCase(int x, int y)
{
    return plateau[y][x];
}

void Plateau::setCase(Case c, int x, int y)
{
    plateau[y][x] = c;
}

bool Plateau::isFull() const
{
    for(vector<Case> v: plateau)
    {
        for(Case c: v)
        {
            if(c.getTypeCase() == TypeCase::Vide)
            {
                return false;
            }
        }
    }
    return true;
}

ostream& operator <<(ostream& out, Plateau p)
{
    for(vector<Case> v: p.getPlateau())
    {
        for(Case c: v)
        {
            out << c << " ";
        }
        out << endl;
    }
    return out;
}
