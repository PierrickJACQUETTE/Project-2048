#include "Jeu_Taquin.hpp"
using namespace std;

Jeu_Taquin::Jeu_Taquin(int x, int y ) : Jeu(x,y)
{
    int taille = getPlateau().getTaille();
    int resultat[taille];
    for(int i = 0; i< taille; i++)
    {
        resultat[i]=i+1;
    }
    melanger(resultat,taille);
    for(int i=0; i< y; i++)
    {
        for(int j=0; j<x; j++)
        {
            Plateau p = getPlateau();
            Case c = p.getCase(j,i);
            if(resultat[i*p.getNbX()+j]!=taille)
            {
                c.setNombre(resultat[i*p.getNbX()+j]);
            }
            p.setCase(c,j,i);
            setPlateau(p);
        }
    }

}

Jeu_Taquin::~Jeu_Taquin() {}

bool Jeu_Taquin::fini()
{
    return aGagne();
}

bool Jeu_Taquin::aGagne()
{
    int cpt = 1;
    for(int i=0; i< getPlateau().getNbY(); i++)
    {
        for(int j=0; j< getPlateau().getNbX(); j++)
        {
            if(cpt!=getPlateau().getTaille() && cpt!=getPlateau().getCase(j,i).getNombre())
            {
                return false;
            }
            cpt++;
        }
    }
    return (getPlateau().getCase(getPlateau().getNbX()-1, getPlateau().getNbY()-1).getTypeCase() == TypeCase::Vide)? true : false;
}

bool Jeu_Taquin::jeu_Possible()
{
    return true;   // test si le jeu est possible
}


void Jeu_Taquin::melanger(int* tableau, int taille)
{
    int nombre_tire=0;
    int temp=0;
    for(int i=0; i<taille; i++)
    {
        nombre_tire=rand_a_b(taille,1);
        temp = tableau[i];
        tableau[i] = tableau[nombre_tire];
        tableau[nombre_tire]=temp;
    }
}

void Jeu_Taquin::unTour(int directionChoisie)
{
    moveCase(directionChoisie);
}

bool Jeu_Taquin::moveCase(int directionChoisie)
{
    cout << "position choisie : " << (char)directionChoisie << endl;
    switch(directionChoisie)
    {
    case 'q':
    {
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
                {
                    if(j-1 >= 0)
                    {
                        Plateau p = getPlateau();
                        Case c= p.getCase(j-1, i);
                        p.setCase(c,j,i);
                        c = p.getCase(j-1, i);
                        c.setNombre(0);
                        p.setCase(c, j-1, i);
                        setPlateau(p);
                        return true;
                    }
                }
            }
        }
        break;
    }
    case 'z':
    {
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
                {
                    if(i-1 >= 0)
                    {
                        Plateau p = getPlateau();
                        Case c= p.getCase(j, i-1);
                        p.setCase(c,j,i);
                        c = p.getCase(j, i-1);
                        c.setNombre(0);
                        p.setCase(c, j, i-1);
                        setPlateau(p);
                        return true;
                    }
                }
            }
        }
        break;
    }
    case 's':
    {
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
                {
                    if(i+1 < getPlateau().getNbY())
                    {
                        Plateau p = getPlateau();
                        Case c= p.getCase(j, i+1);
                        p.setCase(c,j,i);
                        c = p.getCase(j, i+1);
                        c.setNombre(0);
                        p.setCase(c, j, i+1);
                        setPlateau(p);
                        return true;
                    }
                }

            }
        }

        break;
    }
    case 'd':
    {
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
                {
                    if(j+1 < getPlateau().getNbX())
                    {
                        Plateau p = getPlateau();
                        Case c= p.getCase(j+1, i);
                        p.setCase(c,j,i);
                        c = p.getCase(j+1, i);
                        c.setNombre(0);
                        p.setCase(c, j+1, i);
                        setPlateau(p);
                        return true;
                    }
                }
            }
        }
        break;
    }
    }
    return false;
}
