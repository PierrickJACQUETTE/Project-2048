#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include <vector>
#include "Case.hpp"

class Plateau
{
private :
    int taille;
    int nbX;
    int nbY;
    std::vector <Case> plateau;

public :
    Plateau(int x, int y);
    virtual ~Plateau();
    int getTaille() const;
    int getNbX() const;
    int getNbY() const;
    std::vector<Case> getPlateau() const;
    void setCase(Case, int, int);
    bool isFull() const;
    friend std::ostream &operator <<(std::ostream &, const Plateau) ;

protected :

};

#endif // PLATEAU_HPP
