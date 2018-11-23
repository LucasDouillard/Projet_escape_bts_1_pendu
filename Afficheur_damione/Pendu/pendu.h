#ifndef PENDU_H
#define PENDU_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>


using namespace std;

class Pendu
{
private:
    string motADeviner; // par exemple : "tortue"
    string motCache; // par exemple : "******"
    int nbreEssais; // à 9 au départ
    string listLettre; // La liste des lettre déjà proposer

public:
    void motCacher(string mot);

    void Partie();
    vector<string> lectureFichier();
    string motAlea(vector<string>);
    bool checkChance(char,string);
};

#endif // PENDU_H
