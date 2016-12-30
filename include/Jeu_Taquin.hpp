#ifndef JEU_TAQUIN_HPP
#define JEU_TAQUIN_HPP
#include "Jeu.hpp"

class Jeu_Taquin : public Jeu
{
private :
    Case vide;
    void setVide(int i, int j); //Met a jour les paramètres de la Case vide
    void modifier_case(Plateau p, int i, int j);//Méthode pour faire le mouvement de la case vide
    void melanger(int*, int );
    void set_case_vide(Plateau p, int x, int y);

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
