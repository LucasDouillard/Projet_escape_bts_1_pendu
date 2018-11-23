#include "pendu.h"



using namespace std;

void Pendu::motCacher(string mot)
{
    int a;
    this->motADeviner = mot;
    this->motCache = "";
    a = 11-mot.length();
    for(int i=0; i<mot.length(); i++)
        this->motCache += "_";
    for(int i=mot.length();i<a;i++)
        this->motCache += " ";

    this->nbreEssais = 9;
}



vector<string> Pendu::lectureFichier()
{
    //ifstream donne le fichier à lire

    ifstream a("Liste_de_mots.txt", std::ifstream::in);
    string b;
    vector<string>c;
    //Vérification de la présence du fichier

    if(!a)
    {
        cout<<"Fichier non present"<<endl;
        system("pause");
    }

    //La boucle while lis ligne par ligne tous le fichier et ajoute la chaine de caractère trouver à chaque fois.

    while(getline(a, b))
    {
        c.push_back(b);
    }
    return c;
}

string Pendu::motAlea(vector<string> a)
{
    srand(time(NULL));
    int random = rand() % a.size();

    string mot = a[random];
    return mot;
}

bool Pendu::checkChance(char a,string b)
{

    bool estPresent = false;

    for (int i = 0; i < b.size(); i++)
    {
        if(b[i] == a) estPresent = true;
    }

    return estPresent;
}

void Pendu::Partie()
{
    //Le vector permetra de stocker chaque mots
    //Le string mot sera le mot a stocker
    // chance sera le nombre d'essaie possible

    //estPresent nous permet de savoir si
    //la lettre proposé est valide


    char lettre;
    string mot;
    bool estPresent;

    vector<string>Liste = lectureFichier();


    //La méthode motAlea prend le vector en parametre
    //elle va effectuer le choix du mot aleatoire


    motCacher(mot = motAlea(Liste));

    //    vector<char>motAdeviner(mot.begin(),mot.end());
    //    vector<char>motMontrer (motAdeviner.size(),'*');

    cout<<motADeviner<<endl;


    do{
        cout<<"entrer une lettre : ";
        cin>>lettre;


        listLettre.push_back(lettre);
        cout<<listLettre<<endl<<endl;

        estPresent = checkChance(lettre,motADeviner);

        for (int i = 0; i < motADeviner.size(); i++)
        {
            if (lettre != motADeviner[i])
            {
                cout<<motCache[i];
            }
            if (lettre == motADeviner[i])
            {
                motCache[i] = motADeviner[i];
                cout<<motCache[i];
            }

        }

        if (estPresent==false)nbreEssais--;

        cout<<"\nIl vous reste "<<nbreEssais<<" chance\n";

        if (motCache == motADeviner)
        {
            cout<<"Bravo vous avez gagner\n";
            Partie();
        }

    }while (nbreEssais > 0);
    cout<<"Vous avez perdu";
    Partie();
}
