#ifndef PENDU_H
#define PENDU_H

#include <string>
#include <pendu.cpp>

using namespace std;

class Pendu
{
private:
    string motADeviner; // par exemple : "tortue"
    string motCache; // par exemple : "******"
    int nbreEssais; // à 0 au départ

public:
    Pendu(string mot);
    Partie();
    vector<string> lectureFichier();
    string motAlea(vector<string>);
    bool checkChance(char a,string b);
};

#endif // PENDU_H
