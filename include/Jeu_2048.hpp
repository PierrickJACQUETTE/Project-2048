#ifndef JEU_2048_HPP
#define JEU_2048_HPP
#include "Jeu.hpp"

class Jeu_2048 : public Jeu
{
private :
    int score;
    int puissance;

    int initNombre();
    void add();
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    bool unCoupPossible();
    void moveCase(int);

public :
    Jeu_2048(int x, int y, int puissance=2);
    int getScore() const;
    void setScore(int);
    virtual ~Jeu_2048();
    bool fini();
    void unTour(int);
    bool aGagne();
    virtual void fusionLeft(int, int);
    virtual void fusionRight(int, int);
    virtual void fusionUp(int, int);
    virtual void fusionDown(int, int);


protected :

};

#endif // JEU_2048_HPP
