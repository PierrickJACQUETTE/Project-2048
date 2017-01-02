#include "Jeu_Taquin.hpp"
using namespace std;

Jeu_Taquin::Jeu_Taquin(int x, int y ) : Jeu(x,y)
{
    int taille = x*y;
    int resultat[taille];
    for(int i = 0; i< taille; i++)
    {
        resultat[i]=i+1;
    }
    melanger(resultat,taille);
    Plateau p = getPlateau();
    for(int i=0; i< y; i++)
    {
        for(int j=0; j<x; j++)
        {

            Case c = p.getCase(j,i);
            if(resultat[i*p.getNbX()+j]!=taille)
            {
                c.setNombre(resultat[i*p.getNbX()+j]);
            }
            p.setCase(c,j,i);
            setPlateau(p);
        }
    }
    set_case_vide(p, x, y);

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

void Jeu_Taquin::setVide(int i, int j)
{
    vide.setX(i);
    vide.setY(j);
}

void Jeu_Taquin::set_case_vide(Plateau p, int x, int y)
{
    for(int i=0; i< y; i++)
    {
        for(int j=0; j<x; j++)
        {
            Case c = p.getCase(j,i);
            if(c.getTypeCase() == TypeCase::Vide)
            {
                setVide(i, j);
            }
        }
    }
}

void Jeu_Taquin::unTour(int directionChoisie)
{
    moveCase(directionChoisie);
}

void Jeu_Taquin::modifier_case(Plateau p, int i, int j)
{
    Case c = p.getCase(j, i);
    Case act = p.getCase(vide.getY(), vide.getX());
    int tmp = c.getNombre();
    c.setNombre(act.getNombre());
    act.setNombre(tmp);
    p.setCase(act, vide.getY(), vide.getX());
    p.setCase(c, j, i);
    setVide(i, j);
    setPlateau(p);
}

bool Jeu_Taquin::moveCase(int directionChoisie)
{
    cout << "position choisie : " << (char)directionChoisie << endl;
    int i = vide.getX();
    int j = vide.getY();
    cout<<"i = "<<i<<" j = "<<j<<endl;
    Plateau p = getPlateau();
    switch(directionChoisie)
    {
    case 'q':
    {
        if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
        {
            if(j-1 >= 0)
            {
                modifier_case(p, i, j-1);
                return true;
            }
        }
        break;
    }
    case 'z':
    {
        if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
        {
            if(i-1 >= 0)
            {
                modifier_case(p, i-1, j);
                return true;
            }
        }
        break;
    }
    case 's':
    {
        if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
        {
            if(i+1 < getPlateau().getNbY())
            {
                modifier_case(p, i+1, j);
                return true;
            }
        }
        break;
    }
    case 'd':
    {
        if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
        {
            if(j+1 < getPlateau().getNbX())
            {
                modifier_case(p, i, j+1);
                return true;
            }
        }
        break;
    }
    }
    return false;
}
