///** \file main.cpp
// * \brief Fichier principal de l'application serveur_afficheur.
// * \author Sébastien Angibaud
// */
#include "pendu.h"
#include "client.h"
#include <QCoreApplication>
#include <QObject>
#include <iostream>
#include <QThread>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Pendu partie;

    while ( true )
    {
        partie.Partie();
        QThread::sleep(4);
        QCoreApplication::processEvents();
        QCoreApplication::processEvents();
    }

    //return a.epixexec();

}







