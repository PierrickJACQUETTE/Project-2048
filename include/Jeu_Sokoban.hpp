#ifndef JEU_SOKOBAN_HPP
#define JEU_SOKOBAN_HPP
#include "Jeu.hpp"

// Il faudra faire des niveaux predefini en dur dans le code ou dans un fichier separé a voir selon le temps
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
    Jeu_Sokoban(int x, int y, bool boolean);
    virtual ~Jeu_Sokoban();
    bool fini();// renvoie vrai si le jeu est términé et donc gagné
    void unTour(int); //realise un tour
    bool aGagne();// test si le joueur a gagné

  protected :

};

#endif // JEU_SOKOBAN_HPP
