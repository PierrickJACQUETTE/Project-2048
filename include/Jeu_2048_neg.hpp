#ifndef JEU_2048_NEG_HPP
#define JEU_2048_NEG_HPP

#include <Jeu_2048.hpp>

// mode case négatif
class Jeu_2048_neg : public Jeu_2048
{
public:
    Jeu_2048_neg(int x, int y);
    ~Jeu_2048_neg();
    Case initNombre(Case);
    void fusionLeft(int, int);
    void fusionRight(int, int);
    void fusionUp(int, int);
    void fusionDown(int, int);

protected:
};

#endif // JEU_2048_NEG_HPP
