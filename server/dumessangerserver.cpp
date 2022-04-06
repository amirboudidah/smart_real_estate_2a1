#include "dumessangerserver.h"
#include <QDebug>
#include <dumessangersocket.h>
#include <QTextStream>

DuMessangerServer::DuMessangerServer(QObject *parent):QTcpServer(parent)
{

}
 bool DuMessangerServer::startServer(quint16 port)
 {
 return listen(QHostAddress::Any,port);
 }
void DuMessangerServer::incomingConnection(qintptr handle)
{ qDebug ()<<"client connected with handle:"<<handle;
auto socket=new DuMessangerSocket (handle ,this);
mSockets <<socket;
for(auto i:mSockets)
{
   QTextStream T(i) ;
   T<<" Server:s'est connecté:"<<handle;
   i->flush();
}
connect(socket ,&DuMessangerSocket::DuReadyRead,[&](DuMessangerSocket *S)
{ qDebug ()<<"DuReadyRead";
    QTextStream T(S);

    auto text=T.readAll();

    for(auto i:mSockets)
    {


        QTextStream k(i);

        k<<text;

        i ->flush();


   }
});


connect (socket,&DuMessangerSocket::DuStatechanged,[&](DuMessangerSocket *S,int ST)
{ qDebug ()<<"DuStateChanged with handle"
          <<S->socketDescriptor();;
    if (ST==QTcpSocket::UnconnectedState)
     qDebug ()<<"Unconnected state with handle:"
             <<S->socketDescriptor();
    { mSockets.removeOne(S);
        for(auto i :mSockets)
        {
            QTextStream k(i);
            k<< "Server:LE CLIENT"
             <<S->socketDescriptor()
              <<"deconnecter";
            i->flush();
        }
}

});
}


