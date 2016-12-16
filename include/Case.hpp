#ifndef CASE_HPP
#define CASE_HPP
#include <iostream>
#include <string>

enum class TypeCase
{
    Contenu, Vide, Mur, But, Personnage
};
// Contenu = 0, Vide =1, Mur=2, But=3, Personnage=4

std::ostream& operator<<(std::ostream&, const TypeCase);

class Case
{
private :
    TypeCase typeCase;
    int x;
    int y;
    int nombre; //valeur de la case

public :
    Case(TypeCase, int, int);
    virtual ~Case();
    int getX() const;
    int getY() const;
    int getNombre() const;
    TypeCase getTypeCase() const;
    void setX(int);
    void setY(int);
    void setNombre(int);
    void setTypeCase(TypeCase);
    void setCase(TypeCase, int, int);
    friend std::ostream & operator<<(std::ostream&, const Case);

protected :

};


#endif // CASE_HPP

