#include "historique.h"
#include<QMessageBox>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString id,QString nomcl,QString numtelcl)
{    QFile file ("C:/Users/user/Desktop/interfaceG_projet/his.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id+"\n"+nomcl << "\n" +numtelcl << "\n";


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
