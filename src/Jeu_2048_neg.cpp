#include "Jeu_2048_neg.hpp"

Jeu_2048_neg::Jeu_2048_neg(int x, int y) : Jeu_2048(x,y),case_neg(1) {}

Jeu_2048_neg::~Jeu_2048_neg() {}

bool Jeu_2048_neg::getCaseNeg() const
{
    return case_neg;
}

void Jeu_2048_neg::unTour(int) {}
