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
}

void Jeu_2048_destroy::fusionRight(int j, int i)
{
    Jeu_2048::fusionRight(j,i);
}

void Jeu_2048_destroy::fusionUp(int j, int i)
{
    Jeu_2048::fusionUp(j,i);
}

void Jeu_2048_destroy::fusionDown(int j, int i)
{
    Jeu_2048::fusionDown(j,i);
}

