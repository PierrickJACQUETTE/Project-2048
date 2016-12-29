#ifndef JEU_SOKOBAN_HPP
#define JEU_SOKOBAN_HPP
#include "Jeu.hpp"

// Il faudra faire des niveaux predefini en dur dans le code ou dans un fichier separé a voir selon le temps
class Jeu_Sokoban : public Jeu
{

  private :
      Case pers;
      void initialise_plateau(TypeCase* , int);
      bool case_libre(Plateau p, int i, int j);
      void setPers(Plateau p, int i, int j);
      void modifier_case(Plateau p, int i, int j);
      void modifier_box(Plateau p, int i, int j, int iprec, int jprec);

  public :
    Jeu_Sokoban(int x, int y);
    virtual ~Jeu_Sokoban();
    bool fini();
    void unTour(int);
    bool aGagne();

  protected :

};

#endif // JEU_SOKOBAN_HPP
