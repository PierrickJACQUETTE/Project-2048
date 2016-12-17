#ifndef JEU_TAQUIN_HPP
#define JEU_TAQUIN_HPP
#include "Jeu.hpp"

class Jeu_Taquin : public Jeu
{
private :
    void melanger(int*, int );
    int rand_a_b(int, int);
    int choixDirection();

public :
    Jeu_Taquin(int x, int y );
    ~Jeu_Taquin();
    bool fini();
    void unTour(int);
    bool aGagne();
    void lancerPartie();
    void simulerPartie();
    bool jeu_Possible(); // test si le jeu est possible
    bool moveCase(int);

protected :
};

#endif // JEU_TAQUIN_HPP
