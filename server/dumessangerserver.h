#ifndef DUMESSANGERSERVER_H
#define DUMESSANGERSERVER_H
#include <QTcpServer>



class DuMessangerSocket;

class DuMessangerServer : public QTcpServer
{
public:
    DuMessangerServer(QObject *parent =nullptr);
    bool startServer(quint16 port);
protected :
    void incomingConnection (qintptr handle);
private:
    QList<DuMessangerSocket *> mSockets;
};

#endif // DUMESSANGERSERVER_H
