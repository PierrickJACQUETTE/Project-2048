#ifndef JEU_2048_HPP
#define JEU_2048_HPP
#include "Jeu.hpp"

class Jeu_2048 : public Jeu
{

private :
    int score;
    int puissance;

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
    int getPuissance() const;
    void setScore(int);
    virtual ~Jeu_2048();
    bool fini();
    void unTour(int);
    bool aGagne();
    virtual Case initNombre(Case);
    virtual void fusionLeft(int, int);
    virtual void fusionRight(int, int);
    virtual void fusionUp(int, int);
    virtual void fusionDown(int, int);
    void fusionLeftRight(int, int, int, bool);
    void fusionUpDown(int, int, int, bool);

};

#endif // JEU_2048_HPP
