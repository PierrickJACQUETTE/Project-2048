#ifndef CASE_HPP
#define CASE_HPP
#include <iostream>
#include <string>

enum class TypeCase
{
    Contenu, Vide, Mult, Destroy, Mur, But, Personnage, Box, Final, PersBut
};
// Contenu = 0, Vide =1, Mult=2, Destroy=3, Mur=4, But=5, Personnage=6, Box=7

std::ostream& operator<<(std::ostream&, const TypeCase);

class Case
{
private :
    TypeCase typeCase;
    int nombre; //valeur de la case
    int x;
    int y;
    bool acces; //pour le 2048 permet de savoir si la case est deja modifie à chaque tour

public :
    Case(TypeCase=TypeCase::Vide);
    virtual ~Case();
    int getNombre() const;
    bool getAcces() const;
    TypeCase getTypeCase() const;
    void setNombre(int);
    void setAcces(bool);
    void setTypeCase(TypeCase);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    friend std::ostream & operator<<(std::ostream&, const Case);

protected :

};


#endif // CASE_HPP
