///** \file main.cpp
// * \brief Fichier principal de l'application serveur_afficheur.
// * \author Sébastien Angibaud
// */
#include <pendu.h>
#include <pendu.cpp>



int main()
{

Pendu partie;
partie.Partie();

}

//#include <QCoreApplication>

//#include <QtSerialPort/QSerialPort>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <ctype.h>
//#include <stdio.h>
//#include <windows.h>
//#include <conio.h>

//using namespace std;
//#include "afficheur_interface.h"
//#include <QThread>



//char Entre_clavier(){
//    char lettre;
//    while( !_kbhit() ) {

//    }

//    lettre = _getch();
//    cout << lettre << endl;

//    return lettre;
//}

//string initialistion()
//{
//    char lettre = Entre_clavier();
//    string init = "___________|9";
//    init[0] = lettre;
//    return init;
//}


//void Victoire(){
//    AfficheurInterface* afficheur = AfficheurInterface::instance();
//    afficheur->envoyerMessage("BRAVO !!!");

//}

//void Defaite(){
//    AfficheurInterface* afficheur = AfficheurInterface::instance();
//    afficheur->envoyerMessage("DOMMAGE :c");

//}

///** --------------------------------------------------------------------------------------
// * \brief Fonction principale de l'application serveur_afficheur.
// * \param argc Le nombre de paramètres de l'application.
// * \param argv Le tableau contenant les paramètres de l'application.
// * \return Le code de sortie de la fonction quit() de QCoreApplication.
// */
//int main(int argc, char *argv[])
//{
//    string reponse;
//    reponse = initialistion();


//    QCoreApplication a(argc, argv);

//    // création du singleton AfficheurInterface
//    AfficheurInterface* afficheur = AfficheurInterface::instance();

//    QThread::sleep(2);
//    if ( afficheur->connexionEtablie() )
//    {
//        std::cout << "Afficheur détecte." << std::endl;
//        afficheur->envoyerMessage(reponse);
//    }
//    else
//        std::cout << "Erreur : afficheur non detecte." << std::endl;


//    // on attend un événement quit
//    int result = a.exec();

//    // suppression du singleton AfficheurInterface
//    delete afficheur;

//    return result;
//}


