#ifndef MESSAGE_CLIENT_H
#define MESSAGE_CLIEN_H

/**
 * \file message_client.h
 * \brief Fichier de déclaration de la classe GestionnaireOrdre.
 * \author Sébastien Angibaud
 */

#include <QString>
#include <vector>

/**
 * \class MessageClient
 * \brief Classe décrivant un message d'un client ou un message à envoyer à un client. Le message est de type : "NUM|ORDRE" ou "NUM|ORDRE|PARAMETRE".
 * \author Sébastien Angibaud
 */
class MessageClient
{
    public:
        MessageClient();
        MessageClient(const QString & texte);
        MessageClient(int numero, QString ordre);
        MessageClient(int numero, QString ordre, const std::vector<QString>& parametre);

        QString texte() const;
        int numero() const;
        QString ordre() const;
        QString parametre( int pos = 0 ) const;
        bool valide() const;
        bool a_parametre() const;
        int nb_parametres() const;
        void setParametre( int pos, const QString & value );

    private:
        /** \brief Le numero du message. */
        int m_numero;

        /** \brief L'ordre du message. */
        QString m_ordre;

        /** \brief Les paramètres du message. */
        std::vector<QString> m_parametres;

        /** \brief Indique si le message est valide. */
        bool m_valide;
};

#endif // MESSAGE_CLIEN_H
