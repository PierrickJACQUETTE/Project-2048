#include "Jeu_2048.hpp"

using namespace std;

Jeu_2048::Jeu_2048(int x, int y, int puissance) : Jeu(x,y), score(0), puissance(puissance)
{
    int nombre = getPlateau().getTaille()*15/100;
    for(int i=0; i<nombre; i++)
    {
        Plateau p = getPlateau();
        int r1 = rand_a_b(p.getNbX(),0);
        int r2 = rand_a_b(p.getNbY(),0);
        Case c = p.getCase(r1,r2);
        c = initNombre(c);
        p.setCase(c,r1,r2);
        setPlateau(p);
    }
}

Jeu_2048:: ~Jeu_2048() {}

Case Jeu_2048::initNombre(Case c)
{
    int a = rand_a_b(2,0);
    a = (a==0)?  2: 4;
    c.setNombre(a);
    return c;
}

int Jeu_2048::getScore() const
{
    return score;
}

int Jeu_2048::getPuissance() const
{
    return puissance;
}

void Jeu_2048::setScore(int i)
{
    score = i;
}

bool Jeu_2048::fini()
{
    return ((getPlateau().isFull() && !unCoupPossible()) || aGagne());
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

bool Jeu_2048::unCoupPossible()
{
    for(int i = 0; i < getPlateau().getNbY(); i++)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            int cpt = 0;
            if(i-1 >=0)
            {
                if(getPlateau().getCase(j,i).getNombre() == getPlateau().getCase(j,i-1).getNombre())
                {
                    cpt++;

                }
            }
            if(i+1 < getPlateau().getNbY())
            {
                if( getPlateau().getCase(j,i).getNombre() == getPlateau().getCase(j,i+1).getNombre())
                {
                    cpt++;
                }
            }
            if(j-1>=0)
            {
                if(getPlateau().getCase(j,i).getNombre() == getPlateau().getCase(j-1,i).getNombre())
                {
                    cpt++;
                }
            }
            if(j+1 < getPlateau().getNbX())
            {
                if( getPlateau().getCase(j,i).getNombre() == getPlateau().getCase(j+1,i).getNombre())
                {
                    cpt++ ;
                }
            }
            if(cpt !=0)
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
    add();
    for(int i = 0; i <getPlateau().getNbY(); i++)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            Plateau p = getPlateau();
            Case c = p.getCase(j,i);
            c.setAcces(false);
            p.setCase(c,j,i);
            setPlateau(p);
        }
    }
    cout << "Votre score : " << score <<endl;
}

void Jeu_2048::moveCase(int directionChoisie)
{
    cout << "position choisie : " << (char)directionChoisie << endl;
    switch(directionChoisie)
    {
    case 'q':
    {
        moveLeft();
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() != TypeCase::Vide)
                {
                    fusionLeft(j,i);
                }
            }
        }
        moveLeft();
        break;
    }
    case 'z':
    {
        moveUp();
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() != TypeCase::Vide)
                {
                    fusionUp(j,i);
                }
            }
        }
        moveUp();

        break;
    }
    case 's':
    {
        moveDown();
        for(int i = getPlateau().getNbY()-1; i>=0; i--)
        {
            for(int j = 0; j < getPlateau().getNbX(); j++)
            {
                if(getPlateau().getCase(j,i).getTypeCase() != TypeCase::Vide)
                {
                    fusionDown(j,i);
                }
            }
        }
        moveDown();
        break;

    }
    case 'd':
    {
        moveRight();
        for(int i = 0; i < getPlateau().getNbY(); i++)
        {
            for(int j = getPlateau().getNbX()-1; j>=0; j--)
            {
                if(getPlateau().getCase(j,i).getTypeCase() != TypeCase::Vide)
                {
                    fusionRight(j,i);
                }
            }
        }
        moveRight();
        break;
    }
    }
}

void Jeu_2048::add()
{
    if(getPlateau().isFull())
    {
        return;
    }
    int x=-1;
    int y=-1;
    do
    {
        x = rand_a_b(getPlateau().getNbX(),0);
        y = rand_a_b(getPlateau().getNbY(),0);
    }
    while(getPlateau().getCase(x,y).getTypeCase() != TypeCase::Vide);
    Plateau p = getPlateau();
    Case c = p.getCase(x,y);
    c = initNombre(c);
    p.setCase(c,x,y);
    setPlateau(p);
}

void Jeu_2048::moveDown()
{
    for(int i = getPlateau().getNbY()-1; i>=0; i--)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
            {
                int suivantY = i-1;
                while(suivantY >=0 && getPlateau().getCase(j,suivantY).getTypeCase() ==TypeCase::Vide)
                {
                    suivantY--;
                }
                if(suivantY>=0)
                {
                    Plateau p = getPlateau();
                    Case c = p.getCase(j,suivantY);
                    p.setCase(c,j,i);
                    c = p.getCase(j,suivantY);
                    c.setNombre(0);
                    p.setCase(c,j,suivantY);
                    setPlateau(p);
                }
            }
        }
    }
}


void Jeu_2048::moveUp()
{
    for(int i = 0; i < getPlateau().getNbY(); i++)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
            {
                int suivantY = i+1;
                while(suivantY < getPlateau().getNbY() &&
                        getPlateau().getCase(j,suivantY).getTypeCase() ==TypeCase::Vide)
                {
                    suivantY++;
                }
                if(suivantY < getPlateau().getNbY())
                {
                    Plateau p = getPlateau();
                    Case c = p.getCase(j,suivantY);
                    p.setCase(c,j,i);
                    c = p.getCase(j,suivantY);
                    c.setNombre(0);
                    p.setCase(c,j,suivantY);
                    setPlateau(p);
                }
            }
        }
    }
}

void Jeu_2048::moveLeft()
{
    for(int i = 0; i < getPlateau().getNbY(); i++)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
            {
                int suivantX = j+1;
                while(suivantX < getPlateau().getNbX() &&
                        getPlateau().getCase(suivantX,i).getTypeCase() ==TypeCase::Vide)
                {
                    suivantX++;
                }
                if(suivantX < getPlateau().getNbX())
                {
                    Plateau p = getPlateau();
                    Case c = p.getCase(suivantX,i);
                    p.setCase(c,j,i);
                    c = p.getCase(suivantX,i);
                    c.setNombre(0);
                    p.setCase(c,suivantX,i);
                    setPlateau(p);
                }
            }
        }
    }
}

void Jeu_2048::moveRight()
{
    for(int i = 0; i < getPlateau().getNbY(); i++)
    {
        for(int j = getPlateau().getNbX()-1; j>=0; j--)
        {
            if(getPlateau().getCase(j,i).getTypeCase() == TypeCase::Vide)
            {
                int suivantX = j-1;
                while(suivantX >=0 &&
                        getPlateau().getCase(suivantX,i).getTypeCase() ==TypeCase::Vide)
                {
                    suivantX--;
                }
                if(suivantX >=0)
                {
                    Plateau p = getPlateau();
                    Case c = p.getCase(suivantX,i);
                    p.setCase(c,j,i);
                    c = p.getCase(suivantX,i);
                    c.setNombre(0);
                    p.setCase(c,suivantX,i);
                    setPlateau(p);
                }
            }
        }
    }
}

void Jeu_2048::fusionLeft(int j,int i)
{
    int suivantX = j+1;
    fusionLeftRight(j,i,suivantX,suivantX < getPlateau().getNbX());
}

void Jeu_2048::fusionRight(int j, int i)
{
    int suivantX = j-1;
    fusionLeftRight(j,i,suivantX,suivantX>=0);
}

void Jeu_2048::fusionUp(int j, int i)
{
    int suivantY = i+1;
    fusionUpDown(j,i,suivantY,suivantY< getPlateau().getNbY());
}

void Jeu_2048::fusionDown(int j, int i)
{
    int suivantY = i-1;
    fusionUpDown(j,i,suivantY,suivantY>=0);
}

void Jeu_2048::fusionUpDown(int j, int i, int suivantY, bool test)
{
    if( test && getPlateau().getCase(j,suivantY).getNombre() == getPlateau().getCase(j,i).getNombre() &&
            getPlateau().getCase(j,suivantY).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false &&
            getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu && getPlateau().getCase(j,suivantY).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,suivantY);
        c.setNombre(c.getNombre()*puissance);
        c.setAcces(true);
        score += c.getNombre();
        p.setCase(c,j,i);
        c = p.getCase(j,suivantY);
        c.setNombre(0);
        p.setCase(c,j,suivantY);
        setPlateau(p);
    }
}

void Jeu_2048::fusionLeftRight(int j, int i, int suivantX, bool test)
{
    if( test && getPlateau().getCase(suivantX,i).getNombre() == getPlateau().getCase(j,i).getNombre() &&
            getPlateau().getCase(suivantX,i).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(suivantX,i);
        c.setNombre(c.getNombre()*puissance);
        c.setAcces(true);
        score += c.getNombre();
        p.setCase(c,j,i);
        c = p.getCase(suivantX,i);
        c.setNombre(0);
        p.setCase(c,suivantX,i);
        setPlateau(p);
    }
}
