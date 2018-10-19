#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>


using namespace std;

std::vector<std::string> lectureFichier()
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


int main()
{
    //Le vector permetra de stocker chaque mots
    //Le string mot sera le mot a stocker


    char lettre;
    string mot;

    vector<string>Liste = lectureFichier();
    ;

    //La méthode motAlea prend le vector en parametre
    //elle va effectuer le choix du mot aleatoire

    mot = motAlea(Liste);
    vector<char>motAdeviner(mot.begin(),mot.end());
    vector<char>motMontrer;

    cout<<mot<<"\n";

    cout<<"entrer une lettre\n";
    cin>>lettre;


    for (int i = 0; i < motAdeviner.size(); i++)
    {
        if ()
        if (lettre == motAdeviner[i])
        {

            cout<<motAdeviner[i]<<"\n";
        }
    }

}
