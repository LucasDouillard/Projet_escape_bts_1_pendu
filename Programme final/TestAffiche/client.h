
#ifndef CLIENT_H
#define CLIENT_H

#include <QtcpSocket>
#include <QObject>

class QTcpSocket;
class QNetworkSession;

class Client : public QObject
{
    Q_OBJECT

public:
    Client();

private slots:
    void afficherErreur(QAbstractSocket::SocketError socketError);

public slots:
    void envoyer_gagne();
    void se_connecter();

    private:
        void envoiTexte( const std::string& s);

private:
    QTcpSocket *m_tcpSocket;
    QNetworkSession *m_networkSession;
};

#endif
