#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    //Le vector permetra de stocker chaque mots
    //ifstream donne le fichier à lire
    //string sera le mots a stocker

    vector<string>Liste;
    ifstream Dico("Liste de mots.txt");
    string mots;

    //vérification de la présence du fichier

    if(!Dico)
    {
        cout<<"Fichier non present"<<endl;
        system("pause");
    }

    //la boucle while lis ligne par ligne tous le fichier et ajoute


    while(getline(Dico, mots))
    {
        Liste.push_back(mots);
    }

    cout<<Liste[1];
}
