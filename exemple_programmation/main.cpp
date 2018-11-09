/** \file main.cpp
 * \brief Fichier principal de l'application serveur_afficheur.
 * \author Sébastien Angibaud
 */

#include <QCoreApplication>

#include <QtSerialPort/QSerialPort>
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <windows.h>


#include "afficheur_interface.h"
#include <QThread>

using namespace std;

/** --------------------------------------------------------------------------------------
 * \brief Fonction principale de l'application serveur_afficheur.
 * \param argc Le nombre de paramètres de l'application.
 * \param argv Le tableau contenant les paramètres de l'application.
 * \return Le code de sortie de la fonction quit() de QCoreApplication.
 */
int main(int argc, char *argv[])
{
    
    QCoreApplication a(argc, argv);

    // création du singleton AfficheurInterface
    AfficheurInterface* afficheur = AfficheurInterface::instance();

    QThread::sleep(2);
    if ( afficheur->connexionEtablie() )
    {
        std::cout << "Afficheur détecte." << std::endl;
        afficheur->envoyerMessage(reponse);
    }
    else
        std::cout << "Erreur : afficheur non detecte." << std::endl;


    // on attend un événement quit
    int result = a.exec();

    // suppression du singleton AfficheurInterface
    delete afficheur;

    return result;
}

