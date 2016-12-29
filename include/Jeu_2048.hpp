#ifndef JEU_2048_HPP
#define JEU_2048_HPP
#include "Jeu.hpp"
/** \file Jeu_2048.hpp
 * \brief Classe pour le jeu 2048 classique
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Ceci permet l'éxécution du jeu suivant des régles tant que le jeu n'est pas gagné ou qu'il n'y a plus de coup possible
 */

class Jeu_2048 : public Jeu
{

private :
    int score;
    int puissance;

    void add();
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    bool unCoupPossible();
    void moveCase(int);

public :

    /** \brief Constructeur du Jeu 2048
     * \fn Jeu_2048(int x, int y, int puissance=2)
     *
     * \param x int la taille en x
     * \param y int la taille en y
     * \param puissance=2 int, la puissace du jeu, par defaut 2
     *
     */
    Jeu_2048(int x, int y, int puissance=2);

    /** \brief Getter du score du jeu
     * \fn int getScore() const
     *
     * \return int le score
     *
     */
    int getScore() const;

    /** \brief Getter de la puissance de jeu
     * \fn int getPuissance() const
     *
     * \return int puissance
     *
     */
    int getPuissance() const;

    /** \brief Setter du score
     * \fn void setScore(int)
     *
     * \param int nouveau score
     * \return void
     *
     */
    void setScore(int);

    /** \brief Destructeur du jeu
     * \fn virtual ~Jeu_2048()
     *
     * \return virtual
     *
     */
    virtual ~Jeu_2048();

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

    /** \brief Fonction permettant d'initialiser une case avec un nombre à chaque tour
     * \fn virtual Case initNombre(Case)
     *
     * \param Case Case a modifiée
     * \return virtual Case Case modifié avec le nombre redefinie pour les options de 2048
     *
     */
    virtual Case initNombre(Case);

    /** \brief Fonction permettant de déplacer vers la gauche
     * \fn virtual void fusionLeft(int, int)
     *
     * \param int la position y de la case
     * \param int la position x de la case
     * \return virtual void redefinie pour les options de 2048
     *
     */
    virtual void fusionLeft(int, int);

    /** \brief Fonction permettant de déplacer vers la droite
     * \fn virtual void fusionRight(int, int)
     *
     * \param int la position y de la case
     * \param int la position x de la case
     * \return virtual void redefinie pour les options de 2048
     *
     */
    virtual void fusionRight(int, int);

    /** \brief Fonction permettant de déplacer vers le haut
    * \fn virtual void fusionUp(int, int)
     *
     * \param int la position y de la case
     * \param int la position x de la case
     * \return virtual void redefinie pour les options de 2048
     *
     */
    virtual void fusionUp(int, int);

    /** \brief Fonction permettant de déplacer vers le bas
     *  \fn virtual void fusionDown(int, int)
     *
     * \param int la position y de la case
     * \param int la position x de la case
     * \return virtual void redefinie pour les options de 2048
     *
     */
    virtual void fusionDown(int, int);

    /** \brief Fonction permettant de déplacer vers la droite ou gauche
     *  \fn void fusionLeftRight(int, int, int, bool)
     *
     * \param int la position y de la case
     * \param int la position x de la case
     * \param int la case en x à fusionner
     * \param bool le test pour ne pas sortir du plateau
     * \return void
     *
     */
    void fusionLeftRight(int, int, int, bool);

    /** \fn void fusionUpDown(int, int, int, bool)
     * \brief Fonction permettant de déplacer vers le haut ou bas
     *
     * \param int la position y de la case
     * \param int la position x de la case
     * \param int la case en y à fusionner
     * \param bool le test pour ne pas sortir du plateau
     * \return void
     *
     */
    void fusionUpDown(int, int, int, bool);

};

#endif // JEU_2048_HPP
