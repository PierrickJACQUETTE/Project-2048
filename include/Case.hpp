#ifndef CASE_HPP
#define CASE_HPP
#include <iostream>
#include <string>

/** \file Case.hpp
 * \brief Classe enum pour representer une les différents types possibles pour une case
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Type d'une case
 */
enum class TypeCase
{
    Contenu, Vide, Mult, Destroy, Mur, But, Personnage, Box, Final, PersBut
};
// Contenu = 0, Vide =1, Mult=2, Destroy=3, Mur=4, But=5, Personnage=6, Box=7

std::ostream& operator<<(std::ostream&, const TypeCase);


/** \file Case.hpp
 * \brief Classe pour representer une case
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Valeur d'une case
 */

class Case
{
private :
    TypeCase typeCase;
    int nombre; //valeur de la case
    int x;
    int y;
    bool acces; //pour le 2048 permet de savoir si la case est deja modifie à chaque tour

public :
    /** \brief Constructeur d'une case
     * \fn Case(TypeCase=TypeCase::Vide)
     *
     * \param TypeCase=TypeCase::Vide, Type de la case
     *
     */
    Case(TypeCase=TypeCase::Vide);

    /** \brief Destructeur d'une case
     * \fn virtual ~Case()
     *
     * \return virtual
     *
     */
    virtual ~Case();

    /** \brief Getter du nombre de la case
     * \fn int getNombre() const
     *
     * \return int la valeur
     *
     */
    int getNombre() const;

    /** \brief Getter de l'accés à la case
     * \fn bool getAcces() const
     *
     * \return bool valeur de l'accés
     *
     */
    bool getAcces() const;

    /** \brief Getter du type de la case
     * \fn TypeCase getTypeCase() const
     *
     * \return TypeCase le type de la case
     *
     */
    TypeCase getTypeCase() const;

    /** \brief Setter du nombre contenu dans la case
     * \fn void setNombre(int)
     *
     * \param int nouvelle valeur
     * \return void
     *
     */
    void setNombre(int);

    /** \brief Setter sur l'accés d'une case
     * \fn  void setAcces(bool)
     *
     * \param bool nouvelle valeur
     * \return void
     *
     */
    void setAcces(bool);

    /** \brief Setter du type de la case
     * \fn void setTypeCase(TypeCase)
     *
     * \param TypeCase nouvelle valeur
     * \return void
     *
     */
    void setTypeCase(TypeCase);

    /** \brief Setter de X
     * \fn void setX(int x)
     *
     * \param x int la nouvelle valeur
     * \return void
     *
     */
    void setX(int x);

    /** \brief Setter de Y
     * \fn void setY(int y)
     *
     * \param y int la nouvelle valeur
     * \return void
     *
     */
    void setY(int y);

    /** \brief Getter de X
     * \fn int getX()
     *
     *
     * \return int une position en X
     *
     */
    int getX();

    /** \brief Getters de Y
     * \fn int getY()
     *
     * \return int une position en Y
     *
     */
    int getY();

    /** \brief Fonction de surdéfinition de l'affichage pour une case
     * \fn friend std::ostream & operator<<(std::ostream&, const Case)
     *
     * \param std::ostream& flux de sortie
     * \param Case const Objet à afficher
     * \return friend std::ostream& flux de sortie avec le contenu dedans
     *
     */
    friend std::ostream & operator<<(std::ostream&, const Case);

};


#endif // CASE_HPP
