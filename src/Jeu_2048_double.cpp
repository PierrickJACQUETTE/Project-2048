#include "Jeu_2048_double.hpp"

Jeu_2048_double::Jeu_2048_double(int x, int y) : Jeu_2048(x,y), case_double(1) {}

Jeu_2048_double::~Jeu_2048_double() {}

bool Jeu_2048_double::getCaseDouble() const
{
    return case_double;
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
