#include "historique.h"
#include<QMessageBox>
#include <QDateTime>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString nome,QString prenome)
{    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << "\n"+nome << "\n" +prenome<< "\n un nouveau employe a etat ajouter le " +sDate << "\n";


}
QString Historique::load()
{   tmp="";
    QFile file("C:/Users/amirb/Desktop/HomePad-Copie/his.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {


         QString myString = in.readLine();
         tmp+=myString+"\n";


   }
   return tmp;
}

QString Historique::load2()
{   tmp="";
    QFile file("C:/Users/amirb/Desktop/HomePad-Copie/hisclient.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {


         QString myString = in.readLine();
         tmp+=myString+"\n";


   }
   return tmp;
}
void Historique::save1(QString nome,QString prenome)
{    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << "\n"+nome << "\n" +prenome<< "\n cet employe a etait modifier le " +sDate << "\n";


}
void Historique::save2(QString id)
{
    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id << "\n cet employe a etait supprimer le " +sDate << "\n";


}

void Historique::save3(QString id,QString nomcl,QString numtelcl)
{    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/hisclient.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id+"\n"+nomcl << "\n" +numtelcl<< "\n ce client a etait modifier le " +sDate << "\n";


}

void Historique::save4(QString id,QString nomcl,QString numtelcl)
{    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/hisclient.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id+"\n"+nomcl << "\n" +numtelcl<< "\n un nouveau client a etat ajouter le " +sDate << "\n";
}

void Historique::save5(QString id)
{
    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/hisclient.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id+"\n"<< "ce client a etait supprimer le " +sDate << "\n";


}
