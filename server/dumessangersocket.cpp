#include "dumessangersocket.h"
#include <QTextStream>



DuMessangerSocket::DuMessangerSocket(qintptr handle,QObject *parent):QTcpSocket(parent)
{
setSocketDescriptor(handle);
connect(this,&DuMessangerSocket::readyRead,[&](){ emit DuReadyRead (this);});
connect (this ,&DuMessangerSocket ::stateChanged, [&](int S){emit DuStatechanged(this,S);});
}
