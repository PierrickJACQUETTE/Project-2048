#include "Case.hpp"

using namespace std;

Case::Case(TypeCase typeCase) : typeCase(typeCase), nombre(0)
{
    acces = false;
}

Case::~Case() {}

int Case::getNombre() const
{
    return nombre;
}

bool Case::getAcces() const
{
    return acces;
}

TypeCase Case::getTypeCase() const
{
    return typeCase;
}


void Case::setTypeCase(TypeCase tC)
{
    typeCase = tC;
}

void Case::setNombre(int i)
{
    if(i==0)
    {
        typeCase=TypeCase::Vide;
    }
    else
    {
        typeCase=TypeCase::Contenu;
    }
    nombre = i;
}

void Case::setAcces(bool a)
{
    acces = a;
}

void Case::setX(int nb)
{
    x = nb;
}

void Case::setY(int nb)
{
    y = nb;
}

int Case::getX()
{
    return x;
}

int Case::getY()
{
    return y;
}

ostream& operator<<(ostream& out, const Case c)
{
    if (c.nombre!=0 && c.typeCase==TypeCase::Contenu)
    {
        out << c.nombre;
    }
    else
    {
        out << c.typeCase;
    }
    return out;
}

ostream& operator<<(ostream& out, const TypeCase typeCase)
{
    switch (typeCase)
    {
    case TypeCase::Contenu:
        out << "jamais";
        break;
    case TypeCase::Vide:
        out << ".";
        break;
    case TypeCase::Mult:
        out << "x2";
        break;
    case TypeCase::Destroy:
        out << "D";
        break;
    case TypeCase::Mur:
        out << "M";
        break;
    case TypeCase::But:
        out << "G";
        break;
    case TypeCase::Personnage:
        out << "P";
        break;
    case TypeCase::Box:
        out << "O";
        break;
    case TypeCase::Final:
        out << "X";
        break;
    case TypeCase::PersBut:
        out << "B";
        break;
    }
    return out;

}
