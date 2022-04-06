#include <QCoreApplication>
#include "dumessangerserver.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DuMessangerServer server;
    if(!server.startServer(3333))
    {
        qDebug()<<"Error:"<<server.errorString();
        return 1;
    }
    qDebug()<<"Server started...";
    return a.exec();
}
