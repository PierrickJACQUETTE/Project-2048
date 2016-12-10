#ifndef JEU_TAQUIN_HPP
#define JEU_TAQUIN_HPP
#include "Jeu.hpp"

class Jeu_Taquin : public Jeu
{
private :

public :
    Jeu_Taquin(int x, int y );
    virtual ~Jeu_Taquin();
    virtual bool fini();
    virtual void affiche();
    virtual void unTour();
    virtual void aGagne();
    virtual void lancerPartie();
    virtual void simulerPartie();
    virtual bool jeu_Possible(); // test si le jeu est possible

protected :
};

#endif // JEU_TAQUIN_HPP



