#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "pendu.h"

Pendu::Pendu(string mot)
{
    this->motADeviner = mot;
    this->motCache = "";

    for(int i=0; i<mot.length(); i++) this->motCache += "*";

    this->nbreEssais = 0;
}

using namespace std;

vector<string> lectureFichier()
{
    //ifstream donne le fichier à lire

    ifstream a("Liste de mots.txt");
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

string motAlea(vector<string> a)
{
    srand(time(NULL));
    int random = rand() % a.size();

    string mot = a[random];
    cout<<random+1<<"\n";
    return mot;
}

bool checkChance(char a,string b)
{

    bool estPresent = false;

    for (int i = 0; i < b.size(); i++)
    {
        if(b[i] == a) estPresent = true;
    }

    return estPresent;
}

Pendu::Partie()
{
    //Le vector permetra de stocker chaque mots
    //Le string mot sera le mot a stocker
    // chance sera le nombre d'essaie possible

    //estPresent nous permet de savoir si
    //la lettre proposé est valide


    char lettre;
    string mot;
    int chance = 9;
    bool estPresent;

    vector<string>Liste = lectureFichier();


    //La méthode motAlea prend le vector en parametre
    //elle va effectuer le choix du mot aleatoire


    Pendu P(mot = motAlea(Liste));

    //    vector<char>motAdeviner(mot.begin(),mot.end());
    //    vector<char>motMontrer (motAdeviner.size(),'*');

    cout<<mot<<"\n";

    do{
        cout<<"entrer une lettre : ";
        cin>>lettre;

        estPresent = checkChance(lettre,P.motADeviner);

        for (int i = 0; i < P.motADeviner.size(); i++)
        {
            if (lettre != P.motADeviner[i])
            {
                cout<<P.motCache[i];
            }
            if (lettre == P.motADeviner[i])
            {
                P.motCache[i] = P.motADeviner[i];
                cout<<P.motCache[i];
            }

        }

        if (estPresent==false)chance--;

        cout<<"\nIl vous reste "<<chance<<" chance\n";

        //if (motMontrer == motAdeviner)

    }while (chance >= 0);
}
