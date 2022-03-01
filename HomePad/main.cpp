#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //open qss file
    QFile file("C:\\Users\\amirb\\Desktop\\9raya\\brouillon atelier QT\\main\\interfaces\\HomePad\\SpyBot.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

    //setup stylesheet
    a.setStyleSheet(styleSheet);



    MainWindow w;
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

    w.show();
    return a.exec();
}
