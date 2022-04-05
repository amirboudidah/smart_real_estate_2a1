#include "dumessangersocket.h"
#include <QTextStream>

//connexion entre ui

DuMessangerSocket::DuMessangerSocket(qintptr handle,QObject *parent):QTcpSocket(parent)
{
setSocketDescriptor(handle);
connect(this,&DuMessangerSocket::readyRead,[&](){ emit DuReadyRead (this);});
connect (this ,&DuMessangerSocket ::stateChanged, [&](int S){emit DuStatechanged(this,S);});
}
