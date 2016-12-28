#include "Jeu_2048_destroy.hpp"

using namespace std;

Jeu_2048_destroy::Jeu_2048_destroy(int x, int y) : Jeu_2048(x,y), case_destroy(1) {}

Jeu_2048_destroy::~Jeu_2048_destroy() {}

bool Jeu_2048_destroy::getCaseDestroy() const
{
    return case_destroy;
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

