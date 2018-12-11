
#include <QtNetwork>
#include <QObject>
#include <QThread>
#include <iostream>
#include <sstream>
#include "client.h"
#include <windows.h>
#include "pendu.h"

Client::Client()
:   m_networkSession(0)
{
    std::cout << "Application Client" << std::endl;
    m_tcpSocket = new QTcpSocket(this);

    // La méthode afficherErreur sera appelée sur le signal error
    connect(m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(afficherErreur(QAbstractSocket::SocketError)));

    QNetworkConfigurationManager manager;
    QNetworkConfiguration config;

    std::cout << "Ouverture session" << std::endl;
    m_networkSession = new QNetworkSession(config, this);

    m_networkSession->open();

    m_tcpSocket->abort();

    // La méthode sessionOuverte sera appelée sur le signal opened
    //connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(se_connecter()));
    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(envoyer_gagne()));

    // connexion au serveur sur le port 53000
    se_connecter();
}

void Client::envoyer_gagne()
{
    std::cout << "ENVOI AU SERVEUR" << std::endl;
    std::string nb("1");


    envoiTexte("GAGNE:"+nb);
    m_tcpSocket->close();

}

void Client::se_connecter()
{
    std::cout << "\tse_connecter" << std::endl;
    m_tcpSocket->connectToHost( QHostAddress("10.16.3.214").toString(),53000 );
}

//###############################################################################################################
// Méthode appelée lors d'un déclenchement d'une excepetion sur un socket
void Client::afficherErreur(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        std::cout << "Le serveur n'a pas ete trouve. Verifiez le parametrage du serveur et du port." << std::endl;
        break;
    case QAbstractSocket::ConnectionRefusedError:
        std::cout << "La communication a ete refusee. Verifiez que le serveur est pret, ainsi que le parametrage du serveur et du port." << std::endl;
        break;
    default:
        std::cout << "L'erreur suivante s'est produite : " << m_tcpSocket->errorString().toStdString() << std::endl;
    }
}


//###############################################################################################################
// Méthode envoyant un texte au client
void Client::envoiTexte( const std::string& s )
{
    std::cout << "Envoi de : " << s << std::endl;
    QString texte = tr(s.c_str());
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << texte;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    m_tcpSocket->write(block);
}






