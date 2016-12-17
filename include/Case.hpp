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
    int nombre; //valeur de la case

public :
    Case(TypeCase=TypeCase::Vide);
    virtual ~Case();
    int getNombre() const;
    TypeCase getTypeCase() const;
    void setNombre(int);
    void setTypeCase(TypeCase);
    friend std::ostream & operator<<(std::ostream&, const Case);

protected :

};


#endif // CASE_HPP

