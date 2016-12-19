#ifndef JEU_TAQUIN_HPP
#define JEU_TAQUIN_HPP
#include "Jeu.hpp"

class Jeu_Taquin : public Jeu
{
private :
    void melanger(int*, int );

public :
    Jeu_Taquin(int x, int y );
    ~Jeu_Taquin();
    bool fini();
    void unTour(int);
    bool aGagne();
    bool jeu_Possible(); // test si le jeu est possible
    bool moveCase(int);

protected :
};

#endif // JEU_TAQUIN_HPP
