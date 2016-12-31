#ifndef JEU_HPP
#define JEU_HPP

#include <unistd.h>
#include <random>
#include <ctime>
#include "Plateau.hpp"

/** \file Jeu.hpp
 * \brief Classe pour representer un jeu
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Jeu abstrait
 */
class Jeu
{
private :
    Plateau plateau;

public :
    /** \brief Constructeur d'un jeu
     * \fn Jeu(int x, int y)
     *
     * \param x int
     * \param y int
     *
     */
    Jeu(int x, int y);

    /** \brief Destructeur virtuel d'un jeu
     * \fn virtual ~Jeu()
     *
     * \return virtual
     *
     */
    virtual ~Jeu();

    /** \brief Getter du plateau du jeu
     * \fn Plateau getPlateau() const
     *
     * \return Plateau
     *
     */
    Plateau getPlateau() const;

    /** \brief Setter du Plateau du jeu
     * \fn void setPlateau(Plateau)
     *
     * \param Plateau le nouveau plateau
     * \return void
     *
     */
    void setPlateau(Plateau);

    /** \brief Fonction permettant de tirer un nombre aleatoire
      * \fn int rand_a_b(int, int)
     *
     * \param int la borne max (exclu)
     * \param int la borne min (inclus)
     * \return int l'entier aléatoire
     *
     */
    int rand_a_b(int, int);
    /** \brief Fonction de choisir la direction
     * \fn int choixDirection()
     *
     * \return int : la direction choisie
     *
     */
    int choixDirection();

    /** \brief Fonction permettant de savoir si le jeu est fini redefinie dans chaque jeu
     * \fn virtual bool fini()
     *
     * \return virtual bool true si fini, false sinon
     *
     */
    virtual bool fini()=0; // test si le jeu est fini

    /** \brief Fonction permettant de faire un Tour dans le jeu redefinie dans chaque jeu
     * \fn virtual void unTour(int)
     *
     * \param int direction de déplacement
     * \return virtual
     *
     */
    virtual void unTour(int)=0;

    /** \brief Fonction permettant de savoir si on a gagné redefinie dans chaque jeu
     * \fn virtual bool aGagne()=0
     *
     * \return virtual bool
     *
     */
    virtual bool aGagne()=0; // Test si on a gagné

    /** \brief Fonction permettant de lancer une partie pour un humain
     * \fn void lancerPartie()
     *
     * \return void
     *
     */
    void lancerPartie();

    /** \brief Fonction permettant de lancer une partie pour le robot
     * \fn void simulerPartie()
     *
     * \return void
     *
     */
    void simulerPartie();

    /** \brief Fonction permettant de lancer une exception si la valeur saisie est mauvaise
     * \fn static bool lancerException(bool, std::string)
     *
     * \param bool savoir le test pour lancer une exception
     * \param std::string texte de l'exception
     * \return bool savoir si on est lancer une exception ou pas
     *
     */
    static bool lancerException(bool, std::string);

};

#endif // JEU_HPP
