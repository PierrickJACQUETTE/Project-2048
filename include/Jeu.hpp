#ifndef JEU_HPP
#define JEU_HPP

#include <unistd.h>
#include <random>
#include "Plateau.hpp"

class Jeu
{
private :
    Plateau plateau;

public :
    Jeu(int x, int y);
    virtual ~Jeu();
    Plateau getPlateau() const;
    void setPlateau(Plateau);
    int rand_a_b(int, int);
    int choixDirection();
    void affiche(); // affiche en mode texte le jeu
    virtual bool fini()=0; // test si le jeu est fini
    virtual void unTour(int)=0; // fait un tour, ici seront lancé les action bougé a droite, gauche... Puis les test sur la possibilité du coup § Peut être a diviser en 2 fonction
    virtual bool aGagne()=0; // Test si on a gagné
    void lancerPartie(); // lance une partie pour un humain
    void simulerPartie(); // lance une partie pour le robot
    //virtual void newPartie(); Pour faire la difference entre un joueur et un robot
    //virtual void annuleUnTour();

    static bool lancerException(bool, std::string);

protected :
};

#endif // JEU_HPP
