#include "Jeu_2048.hpp"

using namespace std;

Jeu_2048::Jeu_2048(int x, int y) : Jeu(x,y), score(0)
{
    int nombre = getPlateau().getTaille()*15/100;
    for(int i=0; i<nombre; i++)
    {
        Plateau p = getPlateau();
        int r1 = rand_a_b(p.getNbX(),0);
        int r2 = rand_a_b(p.getNbY(),0);
        Case c = p.getCase(r1,r2);
        if(rand_a_b(2,0)==0)
        {
            c.setNombre(2);
        }
        else
        {
            c.setNombre(4);
        }
        p.setCase(c,r1,r2);
        setPlateau(p);
    }
}

Jeu_2048:: ~Jeu_2048() {}

int Jeu_2048::getScore() const
{
    return score;
}

void Jeu_2048::setScore(int i)
{
    score = i;
}

bool Jeu_2048::fini()
{
    return (getPlateau().isFull() || aGagne());
}

bool Jeu_2048::aGagne()
{
    for(int i = 0; i < getPlateau().getNbY(); i++)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            if(getPlateau().getCase(j,i).getNombre() == 2048)
            {
                return true;
            }
        }
    }
    return false;
}

void Jeu_2048::unTour(int directionChoisie)
{
    moveCase(directionChoisie);
    //add une case
}

bool Jeu_2048::moveCase(int directionChoisie)
{
    cout << "position choisie : " << (char)directionChoisie << endl;
    switch(directionChoisie)
    {
    case 'q':
    {

        break;
    }
    case 'z':
    {

        break;
    }
    case 's':
    {


        break;
    }
    case 'd':
    {

        break;
    }
    }
    return false;
}
