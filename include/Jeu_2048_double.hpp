#ifndef JEU_2048_DOUBLE_HPP
#define JEU_2048_DOUBLE_HPP

#include <Jeu_2048.hpp>

class Jeu_2048_double : public Jeu_2048
{

public:
    Jeu_2048_double(int x, int y);
    ~Jeu_2048_double();
    Case initNombre(Case);
    void fusionLeft(int, int);
    void fusionRight(int, int);
    void fusionUp(int, int);
    void fusionDown(int, int);

protected:
};

#endif // JEU_2048_DOUBLE_HPP
