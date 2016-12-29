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
}

void Jeu_2048_double::fusionRight(int j, int i)
{
    Jeu_2048::fusionRight(j,i);
}

void Jeu_2048_double::fusionUp(int j, int i)
{
    Jeu_2048::fusionUp(j,i);
}

void Jeu_2048_double::fusionDown(int j, int i)
{
    Jeu_2048::fusionDown(j,i);
}
