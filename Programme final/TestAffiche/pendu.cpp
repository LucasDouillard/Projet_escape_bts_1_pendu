#include "pendu.h"
#include "conio.h"


using namespace std;

/** \brief Méthode prenant en paramètre mot et permettant de définir la longueur du motCacher
 * \author BERNIER Damione
 */

void Pendu::motCacher(string mot)
{
    this->motADeviner = mot;
    this->motCache = "";

    for(int i=0; i<mot.length(); i++) this->motCache += "_";

    this->nbreEssais = 9;
}


/** \brief Méthode qui lit le fichier donner et vérifie sa présence
 * \author BERNIER Damione
 */

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


/** \brief Méthode qui choisi un mot aléatoirement uneune liste
 * \author BERNIER Damione
 */

string Pendu::motAlea(vector<string> a)
{
    srand(time(NULL));
    int random = rand() % a.size();

    string mot = a[random];
    cout<<random+1<<"\n";
    return mot;
}

/** \brief Méthode qui choisi un mot aléatoirement uneune liste
 * \author BERNIER Damione
 */

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

    string mDefaite("defaite");
    string mVictoire("BRAVO !!!");
    string mot;
    bool estPresent;

    vector<string>Liste = lectureFichier();


    //La méthode motAlea prend le vector en parametre
    //elle va effectuer le choix du mot aleatoire


    motCacher(mot = motAlea(Liste));

    int nombre_espace;
    string motespace;
    string motAffiche;


    cout<<mot<<"\n";

    nombre_espace=12-motCache.length();

    for(int i=0;nombre_espace>i;i++)
    {
        motespace += " ";
    }

    motAffiche = motCache + motespace + "9";

    AfficheurInterface* afficheur = AfficheurInterface::instance();

    afficheur->envoyerMessage(motAffiche);


    do{
        cout<<"entrer une lettre : ";
        char lettre = _getch(); /** La fonction getch() permet de ne pas avoir à sur entrer */

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


        motAffiche = motCache + motespace + to_string(nbreEssais);
        if (nbreEssais == 0){
            afficheur->envoyerMessage(mDefaite);
            break;
        }
        else if (motCache == motADeviner){
            afficheur->envoyerMessage(mVictoire);
            break;

        }


        else{afficheur->envoyerMessage(motAffiche);

            cout<<"\nIl vous reste "<<nbreEssais<<" chance\n";
        }



    }while (nbreEssais > 0);

    Sleep(8000);


    Partie();
}
