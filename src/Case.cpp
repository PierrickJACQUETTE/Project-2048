#include "Case.hpp"

using namespace std;

Case::Case(TypeCase typeCase, int x, int y) : typeCase(typeCase), x(x), y(y), nombre(0){}

Case::~Case(){}

int Case::getNombre() const
{
    return 0;
}

int Case::getX() const
{
    return 0;
}

int Case::getY() const
{
    return 0;
}

TypeCase Case::getTypeCase() const{
    return typeCase;
}

void Case::setX(int) {}

void Case::setY(int) {}

void Case::setTypeCase(TypeCase typeCase) {}

void Case::setCase(TypeCase typeCase, int, int) {}

void Case::setNombre(int) {}

ostream& operator<<(ostream& out, const Case c)
{
    return (c.nombre!=0)? out<<c.nombre: out<<c.typeCase;
}

ostream& operator<<(ostream& out, const TypeCase typeCase){
    switch (typeCase)
    {
    case TypeCase::Contenu:
        out << "jamais";
        break;
    case TypeCase::Vide:
        out << "";
        break;
    case TypeCase::Mur:
        out << "M";
        break;
    case TypeCase::But:
        out << "B";
        break;
    case TypeCase::Personnage:
        out << "P";
        break;
    }
        return out;

}

