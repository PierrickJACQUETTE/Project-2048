#include "Jeu_Sokoban.hpp"
using namespace std;

Jeu_Sokoban::Jeu_Sokoban(int x, int y, bool boolean) : Jeu(x,y)
{
    int taille = x*y;
    TypeCase resultat[taille];
    mur = boolean;
    initialise_plateau(resultat, taille);

    for(int i=0; i< y; i++)
    {
        for(int j=0; j<x; j++)
        {
            Plateau p = getPlateau();
            Case c = p.getCase(j,i);
            c.setTypeCase(resultat[i*p.getNbX()+j]);
            if(resultat[i*p.getNbX()+j] == TypeCase::Personnage)
            {
                pers.setX(i);
                pers.setY(j);
            }
            p.setCase(c,j,i);
            setPlateau(p);
        }
    }
    affiche_legende();
}

Jeu_Sokoban::~Jeu_Sokoban() {}

void Jeu_Sokoban::initialise_plateau(TypeCase* resultat, int taille)
{
    bool pers = false;
    int x;
    int nb = taille/10;
    if (nb == 0)
        nb = 1;
    int but = rand_a_b(nb,1);
    if(but > 5)
        but = 5;
    for(int i = 0; i < taille; i++)
    {
        x = rand_a_b(3,0);
        if(x < 2){
            resultat[i] = TypeCase::Vide;
        }else{
            if(mur)
                resultat[i] = TypeCase::Mur;
            else
                resultat[i] = TypeCase::Vide;
        }
    }
    int i = 0;
    while(i != but){
        x = rand_a_b(taille, 0);
        if(resultat[x] == TypeCase::Vide){
            resultat[x] = TypeCase::But;
            i++;
        }
    }

    i = 0;
    int test = 0;
    while(i != but && test <20){
        x = rand_a_b(taille, 0);
        if(resultat[x] == TypeCase::Vide){
            resultat[x] = TypeCase::Box;
            i++;
        }else{
            test++;
        }
    }

    while(!pers){
        x = rand_a_b(taille, 0);
        if(resultat[x] == TypeCase::Vide){
            resultat[x] = TypeCase::Personnage;
            pers = true;
        }
    }

}
bool Jeu_Sokoban::fini()
{
    return aGagne();
    return false;
}

bool Jeu_Sokoban::case_libre(Plateau p, int i, int j)
{
    return p.getCase(j, i).getTypeCase() == TypeCase::Vide
        || p.getCase(j, i).getTypeCase() == TypeCase::But;
}

void Jeu_Sokoban::setPers(Plateau p, int i, int j)
{
    pers.setX(i);
    pers.setY(j);
}

void Jeu_Sokoban::modifier_case(Plateau p, int i, int j)
{
    Case c = p.getCase(j, i);
    Case act = p.getCase(pers.getY(), pers.getX());
    if(c.getTypeCase() == TypeCase::But)
        c.setTypeCase(TypeCase::PersBut);
    else
        c.setTypeCase(TypeCase::Personnage);
    if(act.getTypeCase() == TypeCase::PersBut)
        act.setTypeCase(TypeCase::But);
    else
        act.setTypeCase(TypeCase::Vide);
    p.setCase(act, pers.getY(), pers.getX());
    setPers(p, i, j);
    p.setCase(c, j, i);
    setPlateau(p);
}
void Jeu_Sokoban::modifier_box(Plateau p, int i, int j, int iprec, int jprec)
{
    Case c = p.getCase(j, i);
    Case act = p.getCase(jprec, iprec);
    if(c.getTypeCase() == TypeCase::But)
        c.setTypeCase(TypeCase::Final);
    else
        c.setTypeCase(TypeCase::Box);
    if(act.getTypeCase() == TypeCase::Final)
        act.setTypeCase(TypeCase::But);
    else
        act.setTypeCase(TypeCase::Vide);
    p.setCase(act, jprec, iprec);
    p.setCase(c, j, i);
    setPlateau(p);
    modifier_case(p, iprec, jprec);
}

void Jeu_Sokoban::affiche_legende()
{
    cout<<" "<<endl;
    cout<<". est une case vide"<<endl;
    cout<<"G est une case de but la ou on doit ammener une case"<<endl;
    cout<<"P est le personnage "<<endl;
    cout<<"O est est une boite à pousser"<<endl;
    cout<<"X est une case but avec une boite dessus"<<endl;
    cout<<"M est un Mur"<<endl;
    cout<<"B est une case but avec le personnage dessus"<<endl;
}
void Jeu_Sokoban::unTour(int directionChoisie)
{
    affiche_legende();
    cout << "position choisie : " << (char)directionChoisie << endl;
    int i = pers.getX();
    int j = pers.getY();
    Plateau p = getPlateau();

    switch(directionChoisie)
    {
        case 'q':
        {
            if(j-1 >= 0)
            {
                if(case_libre(p, i, j-1))
                    modifier_case(p, i, j-1);
                else if(p.getCase(j-1, i).getTypeCase() == TypeCase::Box || p.getCase(j-1, i).getTypeCase() == TypeCase::Final)
                {
                    if(j-2 >= 0)
                    {
                        if(case_libre(p, i, j-2))
                            modifier_box(p, i, j-2, i, j-1);
                    }

                }
            }
            break;
        }
        case 'z':
        {
            if(i-1>=0)
            {
                if(case_libre(p, i-1, j))
                    modifier_case(p, i -1, j);
                else if(p.getCase(j, i-1).getTypeCase() == TypeCase::Box || p.getCase(j, i-1).getTypeCase() == TypeCase::Final)
                {
                    if(i-2 >= 0)
                    {
                        if(case_libre(p, i-2, j))
                            modifier_box(p, i-2, j, i-1, j);
                    }

                }
            }
            break;
        }
        case 's':
        {
            if(i+1 < getPlateau().getNbY())
            {
                if(case_libre(p, i+1, j))
                    modifier_case(p, i+1, j);
                else if(p.getCase(j, i+1).getTypeCase() == TypeCase::Box || p.getCase(j, i+1).getTypeCase() == TypeCase::Final)
                {
                    if(i+2 < getPlateau().getNbY())
                    {
                        if(case_libre(p, i+2, j))
                            modifier_box(p, i+2, j, i+1, j);
                    }

                }
            }
            break;
        }
        case 'd':
        {
            if(j+1 < getPlateau().getNbX())
            {
                if(case_libre(p, i, j+1))
                    modifier_case(p, i, j+1);
                else if(p.getCase(j+1, i).getTypeCase() == TypeCase::Box || p.getCase(j+1, i).getTypeCase() == TypeCase::Final)
                {
                    if(j+2 < getPlateau().getNbX())
                    {
                        if(case_libre(p, i, j+2))
                            modifier_box(p, i, j+2, i, j+1);
                    }

                }
            }
            break;
        }
    }
}

bool Jeu_Sokoban::aGagne()
{
    Plateau p = getPlateau();
    for(int i = 0; i < getPlateau().getNbY(); i++)
    {
        for(int j = 0; j < getPlateau().getNbX(); j++)
        {
            if(p.getCase(j, i).getTypeCase() == TypeCase::Box || p.getCase(j, i).getTypeCase() == TypeCase::But  || p.getCase(j, i).getTypeCase() == TypeCase::PersBut)
                return false;
        }
    }
    return true;
}
