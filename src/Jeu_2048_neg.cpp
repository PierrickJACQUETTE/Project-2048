#include "Jeu_2048_neg.hpp"

Jeu_2048_neg::Jeu_2048_neg(int x, int y) : Jeu_2048(x,y) {}

Jeu_2048_neg::~Jeu_2048_neg() {}

Case Jeu_2048_neg::initNombre(Case c)
{
    int a = rand_a_b(4,0);
    a = (a<=1)? ((a==0)? 2 : -2) : ((a==2)? 4 :-4);
    c.setNombre(a);
    return c;
}

void Jeu_2048_neg::fusionLeft(int j, int i)
{
    Jeu_2048::fusionLeft(j,i);
}

void Jeu_2048_neg::fusionRight(int j, int i)
{
    Jeu_2048::fusionRight(j,i);
}

void Jeu_2048_neg::fusionUp(int j, int i)
{
    Jeu_2048::fusionUp(j,i);
}

void Jeu_2048_neg::fusionDown(int j, int i)
{
    Jeu_2048::fusionDown(j,i);
}
