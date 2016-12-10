#include "Jeu_2048_double.hpp"

Jeu_2048_double::Jeu_2048_double(int x, int y) : Jeu_2048(x,y), case_double(1) {}

Jeu_2048_double::~Jeu_2048_double() {}

bool Jeu_2048_double::getCaseDouble() const
{
    return true;
}

void Jeu_2048_double::unTour() {}
