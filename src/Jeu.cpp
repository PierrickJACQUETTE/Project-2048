#include "Jeu.hpp"

using namespace std;

Jeu::Jeu(int x, int y): plateau(Plateau(x,y)) {}

Jeu::~Jeu() {}

Plateau Jeu::getPlateau() const
{
    return plateau;
}

void Jeu::setPlateau(Plateau p)
{
    plateau=p;
}

bool Jeu::lancerException(bool b, string s)
{
    if (b)
    {
        throw string(s);
        return false;
    }
    return true;
}

void Jeu::affiche() {}

int Jeu::rand_a_b(int valeurMax, int valeurMin)
{
    int x;
    x = rand()%(valeurMax-valeurMin) + valeurMin;
    return x;
}

void Jeu::lancerPartie()
{
    do
    {
        cout << endl << getPlateau() << endl;
        unTour(choixDirection());
    }
    while(!fini());
    cout << endl << getPlateau() << endl;
}

void Jeu::simulerPartie()
{

    do
    {
        cout << endl << getPlateau() << endl;
        int random = rand_a_b(5,1);
        if(random==1)
        {
            random='z';
        }
        else if(random==2)
        {
            random='q';
        }
        else if(random==3)
        {
            random='s';
        }
        else
        {
            random='d';
        }
        unTour(random);
        usleep(300000); //3sec
    }
    while(!fini());
    cout << endl << getPlateau() << endl;

}

int Jeu::choixDirection()
{
    char res='a';
    bool test = true;
    do
    {
        cout << "z: haut, q: gauche, s: bas et d: droite p pour quitter" <<endl;
        cout << "Veuillez choisir une direction "<< endl;
        cin >> res;
        try
        {
            test = !Jeu::lancerException((res!='z' && res!='q' && res!='s' && res!='d' && res!='p') , "Direction inconnue : z, q, s ou d ou p pour quitter");
        }
        catch(string const& chaine)
        {
            cerr << chaine << endl << endl;
        }
    }
    while(test);
    if(res == 'p')
        exit(0);
    return res;
}