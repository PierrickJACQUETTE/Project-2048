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
        out << ".";
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
