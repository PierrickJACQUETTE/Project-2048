#ifndef JEU_2048_NEG_HPP
#define JEU_2048_NEG_HPP

#include <Jeu_2048.hpp>

/** \file Jeu_2048_neg.hpp
 * \brief Classe pour le jeu 2048 option negatif
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Ceci permet l'éxécution du jeu suivant des régles tant que le jeu n'est pas gagné ou qu'il n'y a plus de coup possible
 *  Option negatif : S’il y a des nombres negatifs, ceux-ci auront la possibilite de d́etruire un nombre opposé.
 */
class Jeu_2048_neg : public Jeu_2048
{

public:
    /** \brief Constructeur du jeu 2048 neg
    *
    * \param x int la taille en x
    * \param y int la taille en y
    *
    */
    Jeu_2048_neg(int x, int y);

    /** \brief Destructeurs du jeu 2048 neg
    * \fn ~Jeu_2048_destroy()
    *
    */
    ~Jeu_2048_neg();

    /** \brief Fonction permettant d'initialiser une case avec un nombre à chaque tour
      * \fn Case initNombre(Case)
      *
      * \param Case Case a modifiée
      * \return virtual Case Case modifié avec le nombre
      *
      */
    Case initNombre(Case);

    /** \brief Fonction permettant de déplacer vers la gauche
    *  \fn void fusionLeft(int, int)
    *
    * \param int la position y de la case
    * \param int la position x de la case
    * \return void
    *
    */
    void fusionLeft(int, int);

    /** \brief Fonction permettant de déplacer vers la droite
    *  \fn void fusionRight(int, int)
    *
    * \param int la position y de la case
    * \param int la position x de la case
    * \return void
    *
    */
    void fusionRight(int, int);

    /** \brief Fonction permettant de déplacer vers le haut
    *  \fn void fusionUp(int, int)
    *
    * \param int la position y de la case
    * \param int la position x de la case
    * \return void
    *
    */
    void fusionUp(int, int);

    /** \brief Fonction permettant de déplacer vers le bas
    *  \fn void fusionDown(int, int)
    *
    * \param int la position y de la case
    * \param int la position x de la case
    * \return void
    *
    */
    void fusionDown(int, int);
};

#endif // JEU_2048_NEG_HPP
