#ifndef UTILISATEUR_HPP
#define UTILISATEUR_HPP

#include "Jeu_2048_destroy.hpp"
#include "Jeu_2048_double.hpp"
#include "Jeu_2048_neg.hpp"
#include "Jeu_2048.hpp"
#include "Jeu_Sokoban.hpp"
#include "Jeu_Taquin.hpp"
#include "Case.hpp"

/**
\file Utilisateur.hpp
 * \brief Classe pour representer l'intéraction avec l'utilisateur
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Permet de demander à l'utilisateur de rentrer tous les paramétres
 */
class Utilisateur
{
public:
    /** \brief Fonction qui choisie le jeu auquel on veux jouer et initialise l'objet correspondant
     *
     * \return void
     *
     */
    static void start();

private:

    static int choixTaille(std::string);
    static int choixJeu();
    static int choix2048();
    static int choixJoueur();
    static Jeu* fonction2048(int, int, int);
    static bool bool_mur();
};

#endif // UTILISATEUR_HPP
