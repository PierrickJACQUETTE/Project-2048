#include "Utilisateur.hpp"

using namespace std;

void Utilisateur::start()
{
    int jeu = choixJeu();
    int x = choixTaille("x");
    int y = choixTaille("y");
    //0 : 2048, 1 : taquin et 2 : sokoban
    switch(jeu)
    {
    case 0:
    {
        int lequel2048 = choix2048();
        fonction2048(lequel2048, x, y);
        break;
    }
    case 2:
    {
        Jeu_Taquin jeu(x,y);
        break;
    }
    case 3:
    {
        Jeu_Sokoban jeu(x,y);
        break;
    }
    }

}

void Utilisateur::fonction2048(int lequel, int x, int y)
{
    {
        //0 : 2048, 1 : destroy, 2 : double et 3 : negatif
        switch(lequel)
        {
        case 0:
        {
            Jeu_2048(x,y);
            break;
        }
        case 2:
        {
            Jeu_2048_destroy(x,y);
            break;
        }
        case 3:
        {
            Jeu_2048_double(x,y);
            break;
        }
        case 4:
        {
            Jeu_2048_neg(x,y);
            break;
        }
        }

    }
}

int Utilisateur::choixTaille(string s)
{
    int res = -1;
    bool test = true;
    do
    {
        cout << "Entrer le " << s << " de la position : " << endl;;
        cin >> res;
        try
        {
            test = !lancerException(res<0 , "Taille negatif, requis POSITIF");
        }
        catch(string const& chaine)
        {
            cerr << chaine << endl << endl;
        }
    }
    while(test);
    return res;
}

int Utilisateur::choixJeu()
{
    int res = -1;
    bool test = true;
    do
    {
        cout << "0 : 2048, 1 : taquin et 2 : sokoban" << endl;
        cout << "Entrer l'entier du jeu choisi : " << endl;
        cin >> res;
        try
        {
            test = !lancerException((res<0 || res>2) , "Jeu inconnu : 0, 1 ou 2");
        }
        catch(string const& chaine)
        {
            cerr << chaine << endl << endl;
        }
    }
    while(test);
    return res;
}

int Utilisateur::choix2048()
{
    int res = -1;
    bool test = true;
    do
    {
        cout << "0 : 2048, 1 : destroy, 2 : double et 3 : negatif" << endl;
        cout << "Entrer l'entier du jeu choisi : " << endl;
        cin >> res;
        try
        {
            test = !lancerException((res<0 || res>3), "Version du jeu inconnue : 0, 1, 2 ou 3");
        }
        catch(string const& chaine)
        {
            cerr << chaine << endl << endl;
        }
    }
    while(test);
    return res;
}

bool Utilisateur::lancerException(bool b, string s)
{
    if (b)
    {
        throw string(s);
        return false;
    }
    return true;
}
