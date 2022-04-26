#include "historique.h"
#include<QMessageBox>
#include <QDateTime>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString id,QString nomcl,QString numtelcl)
{    QFile file ("C:/Users/user/Desktop/interfaceG_projet/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id+"\n"+nomcl << "\n" +numtelcl<< "\n un nouveau client a etat ajouter le " +sDate << "\n";
}
QString Historique::load()
{   tmp="";
    QFile file("C:/Users/user/Desktop/interfaceG_projet/his.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {


         QString myString = in.readLine();
         tmp+=myString+"\n";


   }
   return tmp;
}
void Historique::save1(QString id,QString nomcl,QString numtelcl)
{    QFile file ("C:/Users/user/Desktop/interfaceG_projet/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id+"\n"+nomcl << "\n" +numtelcl<< "\n ce client a etait modifier le " +sDate << "\n";


}
void Historique::save2(QString id)
{
    QFile file ("C:/Users/user/Desktop/interfaceG_projet/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
     out << id+"\n"<< "ce client a etait supprimer le " +sDate << "\n";


}
