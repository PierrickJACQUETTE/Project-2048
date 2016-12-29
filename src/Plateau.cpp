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
    for(int i = 0; i < p.getNbY(); i++)
    {
        if(i==0)
        {
            for(int j = 0; j < p.getNbX(); j++)
            {
                out << " ------";
            }
            out << endl << "|";
        }
        for(int j = 0; j < p.getNbX(); j++)
        {
            string nbrEspaceDebut = " ";
            string nbrEspaceFin = " ";
            Case c = p.getCase(j,i);
            if((c.getNombre() >=0 && c.getNombre() <10) || c.getTypeCase()==TypeCase::Destroy)
            {
                nbrEspaceDebut += "  ";
                nbrEspaceFin += " ";
            }
            else if((c.getNombre() >=10 && c.getNombre() <100) ||
                    (c.getNombre()<0 && c.getNombre()>=-9))
            {
                nbrEspaceDebut +=" ";
                nbrEspaceFin +=" ";
            }
            else if((c.getNombre() >=100 && c.getNombre() <1000) ||
                    (c.getNombre()<-9 && c.getNombre()>=-99))
            {
                nbrEspaceDebut += " ";
            }
            else if(c.getNombre()<-999 && c.getNombre()>=-9999)
            {
                nbrEspaceFin = "";
            }
            out << nbrEspaceDebut << c << nbrEspaceFin << "|";
        }
        out << endl;
        for(int j = 0; j < p.getNbX(); j++)
        {
            out << " ------";
        }
        out << endl;
        if(i!=p.getNbY()-1)
        {
            out << "|";
        }
    }
    return out;
}
