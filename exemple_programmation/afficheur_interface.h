#ifndef AFFICHEURINTERFACE_H
#define AFFICHEURINTERFACE_H

/**
 * \file afficheur_interface.h
 * \brief Fichier de déclaration de la classe AfficheurInterface.
 * \author Sébastien Angibaud
 */

#include <QtSerialPort/QSerialPort>

class MessageClient;

/**
 * \class AfficheurInterface
 * \brief Classe permettant de faire l'interface avec un afficheur.
 * \author Sébastien Angibaud
 */
class AfficheurInterface
{
    private:
        AfficheurInterface();

    public:
        ~AfficheurInterface();

    public:
        static AfficheurInterface* instance();
        void envoyerMessage(const MessageClient& m);
        bool setCouleur( const MessageClient &m );
        bool connexionEtablie() const;

    private:
        int calculerChecksum(const char* trame) const;

    private:
        /** \brief Pointeur sur l'instance singleton AfficheurInterface. */
        static AfficheurInterface* m_instance;

        /** \brief Le port série. */
        QSerialPort m_portSerie;

        /** \brief La couleur actuelle de l'affichage. */
        char m_couleur;
};

#endif // AFFICHEURINTERFACE_H
