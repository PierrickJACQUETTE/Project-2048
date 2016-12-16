#include "Case.hpp"

using namespace std;

Case::Case(TypeCase typeCase, int x, int y) : typeCase(typeCase), x(x), y(y), nombre(0) {}

Case::~Case() {}

int Case::getNombre() const
{
    return nombre;
}

int Case::getX() const
{
    return x;
}

int Case::getY() const
{
    return y;
}

TypeCase Case::getTypeCase() const
{
    return typeCase;
}

void Case::setX(int i)
{
    x = i;
}

void Case::setY(int i )
{
    y = i;
}

void Case::setTypeCase(TypeCase tC)
{
    typeCase = tC;
}

void Case::setCase(TypeCase tC, int ix, int iy)
{
    typeCase = tC;
    x = ix;
    y = iy;
}

void Case::setNombre(int i)
{
    nombre = i;
}

ostream& operator<<(ostream& out, const Case c)
{
    return (c.nombre!=0)? out<<c.nombre: out<<c.typeCase;
}

ostream& operator<<(ostream& out, const TypeCase typeCase)
{
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

