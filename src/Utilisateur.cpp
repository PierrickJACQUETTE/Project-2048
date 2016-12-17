#include "Utilisateur.hpp"

using namespace std;

void Utilisateur::start()
{
    int jeu = choixJeu();
    int x = choixTaille("x");
    int y = choixTaille("y");
    int joueur = choixJoueur();
    Jeu* jeux;
    //0 : 2048, 1 : taquin et 2 : sokoban
    switch(jeu)
    {
    case 0:
    {
        int lequel2048 = choix2048();
        jeux = fonction2048(lequel2048, x, y);
        break;
    }
    case 1:
    {
        jeux =  new Jeu_Taquin(x,y);
        break;
    }
    case 2:
    {
        jeux = new Jeu_Sokoban(x,y);
        break;
    }
    }
    //0 : humain et 1 : robot
    switch(joueur)
    {
    case 0:
    {
        jeux->lancerPartie();
        break;
    }
    case 1:
    {
        jeux->simulerPartie();
        break;
    }

    }
    delete jeux;

}

Jeu* Utilisateur::fonction2048(int lequel, int x, int y)
{
    Jeu* jeux;
    //0 : 2048, 1 : destroy, 2 : double et 3 : negatif
    switch(lequel)
    {
    case 0:
    {
        jeux = new Jeu_2048(x,y);
        break;
    }
    case 1:
    {
        jeux = new Jeu_2048_destroy(x,y);
        break;
    }
    case 2:
    {
        jeux = new Jeu_2048_double(x,y);
        break;
    }
    case 3:
    {
        jeux = new Jeu_2048_neg(x,y);
        break;
    }
    }
    return jeux;

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
            test = !Jeu::lancerException(res<0 , "Taille negatif, requis POSITIF");
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
            test = !Jeu::lancerException((res<0 || res>2) , "Jeu inconnu : 0, 1 ou 2");
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
            test = !Jeu::lancerException((res<0 || res>3), "Version du jeu inconnue : 0, 1, 2 ou 3");
        }
        catch(string const& chaine)
        {
            cerr << chaine << endl << endl;
        }
    }
    while(test);
    return res;
}

int Utilisateur::choixJoueur()
{
    int res = -1;
    bool test = true;
    do
    {
        cout << "0 : humain et 1 : robot" << endl;
        cout << "Entrer l'entier du joueur choisi : " << endl;
        cin >> res;
        try
        {
            test = !Jeu::lancerException((res<0 || res>1) , "Joueur inconnu : 0 ou 1");
        }
        catch(string const& chaine)
        {
            cerr << chaine << endl << endl;
        }
    }
    while(test);
    return res;
}
