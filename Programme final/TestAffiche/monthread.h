#ifndef MONTHREAD_H
#define MONTHREAD_H

#include <QThread>
#include "client.h"


class monThread: public QThread
{
    Q_OBJECT

    protected:
        void run();

    private:
        Client * m_client;

};

#endif // MONTHREAD_H
