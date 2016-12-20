#ifndef JEU_SOKOBAN_HPP
#define JEU_SOKOBAN_HPP
#include "Jeu.hpp"

// Il faudra faire des niveaux predefini en dur dans le code ou dans un fichier separé a voir selon le temps
class Jeu_Sokoban : public Jeu
{

  private :

  public :
  Jeu_Sokoban(int x, int y);
  virtual ~Jeu_Sokoban();
  bool fini();
  void unTour(int);
  bool aGagne();

  protected :

};

#endif // JEU_SOKOBAN_HPP
