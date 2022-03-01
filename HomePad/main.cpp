#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //open qss file
    QFile file("..\\HomePad\\SpyBot.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

    //setup stylesheet
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();

    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
//        QMessageBox::critical(nullptr, QObject::tr("database is open"),
//                    QObject::tr("connection successful.\n"
//                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
