#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>


using namespace std;

std::vector<std::string> lectureFichier()
{
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
    cout<<random<<"\n";
    return mot;
}

//void Affichage()
//{
//    for
//}

int main()
{
    //Le vector permetra de stocker chaque mots
    //ifstream donne le fichier à lire
    //Le string mot sera le mot a stocker


    string motMystere;

    vector<string>Liste = lectureFichier();




    //La méthode motAlea prend le vector en parametre
    //elle va effectuer le choix du mot aleatoire

    motMystere = motAlea(Liste);
    cout<<motMystere<<"\n";


}
