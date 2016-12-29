#ifndef JEU_2048_DESTROY_HPP
#define JEU_2048_DESTROY_HPP

#include <Jeu_2048.hpp>

class Jeu_2048_destroy : public Jeu_2048
{

public:
    Jeu_2048_destroy(int x, int y);
    ~Jeu_2048_destroy();
    Case initNombre(Case);
    bool getCaseDestroy() const;
    void fusionLeft(int, int);
    void fusionRight(int, int);
    void fusionUp(int, int);
    void fusionDown(int, int);

};

#endif // JEU_2048_DESTROY_HPP
