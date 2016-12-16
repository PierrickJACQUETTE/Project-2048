#include "Jeu_2048.hpp"

Jeu_2048::Jeu_2048(int x, int y) : Jeu(x,y), score(0) {}

Jeu_2048:: ~Jeu_2048() {}

int Jeu_2048::getScore() const
{
    return score;
}

void Jeu_2048::setScore(int i)
{
    score = i;
}

bool Jeu_2048::fini()
{
    return true;
}

void Jeu_2048::affiche() {}

void Jeu_2048::unTour() {}

void Jeu_2048::aGagne() {}

void Jeu_2048::lancerPartie() {}

void Jeu_2048::simulerPartie() {}
