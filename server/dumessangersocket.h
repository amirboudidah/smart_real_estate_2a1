#ifndef DUMESSANGERSOCKET_H
#define DUMESSANGERSOCKET_H
#include <QTcpSocket>
#include <QObject>

class DuMessangerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    DuMessangerSocket(qintptr handle,QObject* parent=nullptr);

signals :
    void DuReadyRead(DuMessangerSocket *);
    void DuStatechanged(DuMessangerSocket *,int);
};


#endif // DUMESSANGERSOCKET_H
