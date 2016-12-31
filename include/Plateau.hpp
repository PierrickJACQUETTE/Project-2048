#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include <vector>
#include "Case.hpp"

/** \file Plateau.hpp
 * \brief Classe pour representer une case
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Plateau de case
 */

class Plateau
{
private :
    int taille;
    int nbX;
    int nbY;
    std::vector<std::vector<Case>> plateau;

public :
    /** \brief Constructeur d'un plateau
     * \fn Plateau(int x, int y)
     *
     * \param x int la taille en x
     * \param y int la taille en y
     *
     */
    Plateau(int x, int y);

    /** \brief Destructeur d'un plateau
     * \fn virtual ~Plateau()
     *
     * \return virtual
     *
     */
    virtual ~Plateau();

    /** \brief Getter de la taille
     * \fn int getTaille() const
     *
     * \return int : la taille x*y
     *
     */
    int getTaille() const;

    /** \brief Getter de la taille en Y
     * \fn int getNbX() const
     *
     * \return int taille en X
     *
     */
    int getNbX() const;

    /** \brief Getter de la taille en Y
     * \fn int getNbY() const
     *
     * \return int taille en Y
     *
     */
    int getNbY() const;

    /** \brief Getter du plateau
     * \fn std::vector<std::vector<Case>> getPlateau() const
     *
     * \return std::vector<std::vector<Case>> : le plateau
     *
     */
    std::vector<std::vector<Case>> getPlateau() const;

    /** \brief Getter d'une case
     * \fn Case getCase(int, int)
     *
     * \param int la position en x
     * \param int la position en y
     * \return Case la case
     *
     */
    Case getCase(int, int);

    /** \brief Setter d'une case sur le plateau en x et y
     * \fn  void setCase(Case, int, int)
     *
     * \param Case la case
     * \param int la position en x
     * \param int la position en y
     * \return void
     *
     */
    void setCase(Case, int, int);

    /** \brief Fonction permettant de savoir si le plein est rempli
     * \fn bool isFull() const
     *
     * \return bool true si full , false sinon
     *
     */
    bool isFull() const;


    /** \brief Fonction de surdefinition de l'opérateur d'affichage
     * \fn friend std::ostream &operator <<(std::ostream &, const Plateau)
     *
     * \param std::ostream& flux de sortie
     * \param Plateau const Objet à afficher
     * \return friend std::ostream &operator
     *
     */
    friend std::ostream &operator <<(std::ostream &, const Plateau) ;

};

#endif // PLATEAU_HPP
