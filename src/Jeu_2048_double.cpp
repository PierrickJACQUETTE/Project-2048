#include "Jeu_2048_double.hpp"

Jeu_2048_double::Jeu_2048_double(int x, int y) : Jeu_2048(x,y) {}

Jeu_2048_double::~Jeu_2048_double() {}

Case Jeu_2048_double::initNombre(Case c)
{
    int a = rand_a_b(3,0);
    a = (a<=1)? ((a==0)? 2:4) : -1;
    c.setNombre(a);
    if(a==-1)
    {
        c.setTypeCase(TypeCase::Mult);
    }
    return c;
}

void Jeu_2048_double::fusionLeft(int j, int i)
{
    Jeu_2048::fusionLeft(j,i);
    int suivantX = j+1;
    if(suivantX < getPlateau().getNbX() && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(suivantX,i).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,i);
        setScore(getScore()+c.getNombre());
        c.setNombre(c.getNombre()*getPuissance());
        p.setCase(c,suivantX,i);
        c = p.getCase(suivantX,i);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,j,i);
        setPlateau(p);
    }
    else if(suivantX < getPlateau().getNbX() && getPlateau().getCase(j,i).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(suivantX,i).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(suivantX,i);
        c.setNombre(c.getNombre()*getPuissance());
        setScore(getScore()+c.getNombre());
        p.setCase(c,j,i);
        c = p.getCase(suivantX,i);
        c.setNombre(0);
        p.setCase(c,suivantX,i);
        setPlateau(p);
    }
}

void Jeu_2048_double::fusionRight(int j, int i)
{
    Jeu_2048::fusionRight(j,i);
    int suivantX = j-1;
    if(suivantX>=0 && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(suivantX,i).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,i);
        setScore(getScore()+c.getNombre());
        c.setNombre(c.getNombre()*getPuissance());
        p.setCase(c,suivantX,i);
        c = p.getCase(suivantX,i);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,j,i);
        setPlateau(p);
    }
    else if(suivantX>=0 && getPlateau().getCase(j,i).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(suivantX,i).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(suivantX,i);
        c.setNombre(c.getNombre()*getPuissance());
        setScore(getScore()+c.getNombre());
        p.setCase(c,j,i);
        c = p.getCase(suivantX,i);
        c.setNombre(0);
        p.setCase(c,suivantX,i);
        setPlateau(p);
    }
}

void Jeu_2048_double::fusionUp(int j, int i)
{
    Jeu_2048::fusionUp(j,i);
    int suivantY = i+1;
    if(suivantY< getPlateau().getNbY() && getPlateau().getCase(j,suivantY).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(j,suivantY).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,i);
        setScore(getScore()+c.getNombre());
        c.setNombre(c.getNombre()*getPuissance());
        p.setCase(c,j,suivantY);
        c = p.getCase(j,suivantY);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,j,i);
        setPlateau(p);
    }
    else if(suivantY< getPlateau().getNbY() && getPlateau().getCase(j,i).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(j,suivantY).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,suivantY).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j, suivantY);
        c.setNombre(c.getNombre()*getPuissance());
        setScore(getScore()+c.getNombre());
        p.setCase(c,j,i);
        c = p.getCase(j,suivantY);
        c.setNombre(0);
        p.setCase(c,j,suivantY);
        setPlateau(p);
    }
}

void Jeu_2048_double::fusionDown(int j, int i)
{
    Jeu_2048::fusionDown(j,i);
    int suivantY = i-1;
    if(suivantY>=0 && getPlateau().getCase(j,suivantY).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(j,suivantY).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,i);
        setScore(getScore()+c.getNombre());
        c.setNombre(c.getNombre()*getPuissance());
        p.setCase(c,j,suivantY);
        c = p.getCase(j,suivantY);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,j,i);
        setPlateau(p);
    }
    else if(suivantY>=0 && getPlateau().getCase(j,i).getTypeCase() == TypeCase::Mult &&
            getPlateau().getCase(j,suivantY).getAcces()==false && getPlateau().getCase(j,i).getAcces()==false  &&
            getPlateau().getCase(j,suivantY).getTypeCase() == TypeCase::Contenu)
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j, suivantY);
        c.setNombre(c.getNombre()*getPuissance());
        setScore(getScore()+c.getNombre());
        p.setCase(c,j,i);
        c = p.getCase(j,suivantY);
        c.setNombre(0);
        p.setCase(c,j,suivantY);
        setPlateau(p);
    }
}
