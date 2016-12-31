#ifndef JEU_TAQUIN_HPP
#define JEU_TAQUIN_HPP
#include "Jeu.hpp"

/**
\file Jeu_Taquin.hpp
 * \brief Classe pour representer le jeu taquin
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Permet de représenter le jeu taquin
 */
class Jeu_Taquin : public Jeu
{
private :
    Case vide;
    void setVide(int i, int j); //Met a jour les paramètres de la Case vide
    void modifier_case(Plateau p, int i, int j);//Méthode pour faire le mouvement de la case vide
    void melanger(int*, int );
    void set_case_vide(Plateau p, int x, int y);

public :
    /** \brief Constructeur du jeux
     * \fn Jeu_Taquin(int x, int y )
     *
     * \param x int la taille en x
     * \param y int la taille en y
     *
     */
    Jeu_Taquin(int x, int y );

    /** \brief Destructeur du jeu
     * \fn ~Jeu_Taquin()
     *
     * \return
     *
     */
    ~Jeu_Taquin();

    /** \brief Fonction permettant de savoir si le jeu est fini
    * \fn bool fini()
    *
    * \return bool true si fini, false sinon
    *
    */
    bool fini();

    /** \brief Fonction permettant de faire un Tour dans le jeu
    * \fn void unTour(int)
    *
    * \param int direction de déplacement
    * \return void
    *
    */
    void unTour(int);

    /** \brief Fonction permettant de savoir si on a gagné
     * \fn bool aGagne()
     *
     * \return bool on a gagné ? true si oui, false sinon
     *
     */
    bool aGagne();

    /** \brief Fonction permettant de déplacer dans une direction une case
     * \fn bool moveCase(int)
     *
     * \param int la direction
     * \return bool savoir si le deplacement à eu lieu
     *
     */
    bool moveCase(int);

protected :
};

#endif // JEU_TAQUIN_HPP
