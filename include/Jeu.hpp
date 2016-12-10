#ifndef JEU_HPP
#define JEU_HPP
#include "Plateau.hpp"

class Jeu
{
private :
    Plateau plateau;

public :
    Jeu(int x, int y);
    virtual ~Jeu();
    Plateau getPlateau() const;
    virtual bool fini()=0; // test si le jeu est fini
    virtual void affiche()=0; // affiche en mode texte le jeu
    virtual void unTour()=0; // fait un tour, ici seront lancé les action bougé a droite, gauche... Puis les test sur la possibilité du coup § Peut être a diviser en 2 fonction
    virtual void aGagne()=0; // Test si on a gagné
    virtual void lancerPartie()=0; // lance une partie pour un humain
    virtual void simulerPartie()=0; // lance une partie pour le robot
    //virtual void newPartie(); Pour faire la difference entre un joueur et un robot
    //virtual void annuleUnTour();

protected :
};

#endif // JEU_HPP

