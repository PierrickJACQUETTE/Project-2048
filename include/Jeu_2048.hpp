#ifndef JEU_2048_HPP
#define JEU_2048_HPP
#include "Jeu.hpp"

class Jeu_2048 : public Jeu
{
private :
    int score;

public :
    Jeu_2048(int x, int y);
    int getScore() const;
    void setScore(int);
    virtual ~Jeu_2048();
    virtual bool fini();
    virtual void unTour(int);
    virtual bool aGagne();
    virtual bool moveCase(int);

protected :

};

#endif // JEU_2048_HPP

