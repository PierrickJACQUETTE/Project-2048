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
    void setScore();
    virtual ~Jeu_2048();
    virtual bool fini();
    virtual void affiche();
    virtual void unTour();
    virtual void aGagne();
    virtual void lancerPartie();
    virtual void simulerPartie();

protected :

};

#endif // JEU_2048_HPP

