#ifndef UTILISATEUR_HPP
#define UTILISATEUR_HPP

#include "Jeu_2048_destroy.hpp"
#include "Jeu_2048_double.hpp"
#include "Jeu_2048_neg.hpp"
#include "Jeu_2048.hpp"
#include "Jeu_Sokoban.hpp"
#include "Jeu_Taquin.hpp"
#include "Case.hpp"

class Utilisateur
{
public:
    static void start();

protected:
private:

    static int choixTaille(std::string);
    static int choixJeu();
    static int choix2048();
    static int choixJoueur();
    static Jeu* fonction2048(int, int, int);
    static bool bool_mur();
};

#endif // UTILISATEUR_HPP
