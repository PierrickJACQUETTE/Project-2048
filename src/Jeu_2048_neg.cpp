#include "Jeu_2048_neg.hpp"

Jeu_2048_neg::Jeu_2048_neg(int x, int y) : Jeu_2048(x,y),case_neg(1) {}

Jeu_2048_neg::~Jeu_2048_neg() {}

bool Jeu_2048_neg::getCaseNeg() const
{
    return case_neg;
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
