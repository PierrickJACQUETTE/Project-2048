#include "Jeu_2048_destroy.hpp"

using namespace std;

Jeu_2048_destroy::Jeu_2048_destroy(int x, int y) : Jeu_2048(x,y) {}

Jeu_2048_destroy::~Jeu_2048_destroy() {}

Case Jeu_2048_destroy::initNombre(Case c)
{
    int a = rand_a_b(3,0);
    a = (a<=1)? ((a==0)? 2:4) : -1;
    c.setNombre(a);
    if(a==-1)
    {
        c.setTypeCase(TypeCase::Destroy);
    }
    return c;
}
void Jeu_2048_destroy::fusionLeft(int j, int i)
{
    Jeu_2048::fusionLeft(j,i);
    int suivantX = j+1;
    if(suivantX < getPlateau().getNbX() && getPlateau().getCase(suivantX,i).getAcces()==false &&
            getPlateau().getCase(j,i).getAcces()==false  &&
            ((getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Destroy)  ||
             (getPlateau().getCase(j,i).getTypeCase() == TypeCase::Destroy && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Contenu)
            ))
    {
        Plateau p = getPlateau();
        Case c = p.getCase(suivantX,i);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,suivantX,i);
        c = p.getCase(j,i);
        c.setNombre(0);
        p.setCase(c,j,i);
        setPlateau(p);
    }
}

void Jeu_2048_destroy::fusionRight(int j, int i)
{
    Jeu_2048::fusionRight(j,i);
    int suivantX = j-1;
    if(suivantX>=0 && getPlateau().getCase(suivantX,i).getAcces()==false &&
            getPlateau().getCase(j,i).getAcces()==false  &&
            ((getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Destroy)  ||
             (getPlateau().getCase(j,i).getTypeCase() == TypeCase::Destroy && getPlateau().getCase(suivantX,i).getTypeCase() == TypeCase::Contenu)
            ))
    {
        Plateau p = getPlateau();
        Case c = p.getCase(suivantX,i);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,suivantX,i);
        c = p.getCase(j,i);
        c.setNombre(0);
        p.setCase(c,j,i);
        setPlateau(p);
    }
}

void Jeu_2048_destroy::fusionUp(int j, int i)
{
    Jeu_2048::fusionUp(j,i);
    int suivantY = i+1;
    if(suivantY< getPlateau().getNbY() && getPlateau().getCase(j, suivantY).getAcces()==false &&
            getPlateau().getCase(j,i).getAcces()==false  &&
            ((getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu && getPlateau().getCase(j, suivantY).getTypeCase() == TypeCase::Destroy)  ||
             (getPlateau().getCase(j,i).getTypeCase() == TypeCase::Destroy && getPlateau().getCase(j, suivantY).getTypeCase() == TypeCase::Contenu)
            ))
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,suivantY);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,j, suivantY);
        c = p.getCase(j,i);
        c.setNombre(0);
        p.setCase(c,j,i);
        setPlateau(p);
    }
}

void Jeu_2048_destroy::fusionDown(int j, int i)
{
    Jeu_2048::fusionDown(j,i);
    int suivantY = i-1;
    if(suivantY>=0 && getPlateau().getCase(j, suivantY).getAcces()==false &&
            getPlateau().getCase(j,i).getAcces()==false  &&
            ((getPlateau().getCase(j,i).getTypeCase() == TypeCase::Contenu && getPlateau().getCase(j, suivantY).getTypeCase() == TypeCase::Destroy)  ||
             (getPlateau().getCase(j,i).getTypeCase() == TypeCase::Destroy && getPlateau().getCase(j, suivantY).getTypeCase() == TypeCase::Contenu)
            ))
    {
        Plateau p = getPlateau();
        Case c = p.getCase(j,suivantY);
        c.setNombre(0);
        c.setAcces(true);
        p.setCase(c,j, suivantY);
        c = p.getCase(j,i);
        c.setNombre(0);
        p.setCase(c,j,i);
        setPlateau(p);
    }
}
