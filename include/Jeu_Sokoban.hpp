#ifndef JEU_SOKOBAN_HPP
#define JEU_SOKOBAN_HPP
#include "Jeu.hpp"

/**
\file Jeu_Sokoban.hpp
 * \brief Classe pour le jeu sokoban
 * \author Bessa Alexandre & Jacquette Pierrick
 *
 *  Ceci permet l'éxécution du jeu suivant des régles tant que le jeu n'est pas gagné ou qu'il n'y a plus de coup possible
 */
class Jeu_Sokoban : public Jeu
{

  private :
      Case pers;
      bool mur;
      void initialise_plateau(TypeCase* , int);// Permet de remplir le plateau avec des cases vides des murs les box les "buts" et le personnage
      bool case_libre(Plateau p, int i, int j); //renvoie vrai si la case est libre ou un "but"
      void setPers(Plateau p, int i, int j); //Met a jour les paramètres de la Case pers
      void modifier_case(Plateau p, int i, int j);//Méthode pour faire le mouvement du joueur
      void modifier_box(Plateau p, int i, int j, int iprec, int jprec);//Méthode pour faire le mouvement de la caisse
      bool bool_mur(); //Pour savoir si on veut des murs
      void affiche_legende();//Afficher la legende

  public :
    /** \brief Constructeur du jeu Sokoban
     * \fn Jeu_Sokoban(int x, int y, bool boolean)
     *
     * \param x int la taille en x
     * \param y int la taille en y
     * \param boolean bool : savoir si l'on met des murs
     *
     */
    Jeu_Sokoban(int x, int y, bool boolean);

    /** \brief Destructeur du jeu Sokoban
     * \fn virtual ~Jeu_Sokoban()
     *
     * \return virtual
     *
     */
    virtual ~Jeu_Sokoban();

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

  protected :

};

#endif // JEU_SOKOBAN_HPP
