#include "Jeu_2048_destroy.hpp"

Jeu_2048_destroy::Jeu_2048_destroy(int x, int y) : Jeu_2048(x,y), case_destroy(1) {}

Jeu_2048_destroy::~Jeu_2048_destroy() {}

bool Jeu_2048_destroy::getCaseDestroy() const
{
    return case_destroy;
}

void Jeu_2048_destroy::unTour(int) {}
