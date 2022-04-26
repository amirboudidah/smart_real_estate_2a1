#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include<QString>
#include<QtSql/QSqlQuery>
#include<QTableWidget>
#include<QtSql/QSqlQueryModel>
#include <QSqlDatabase>


class client
{
public:

   client();
   client(int,QString,QString,QString,QString,QString);

   int getcin();
   QString getnumtelcl();
   QString getnomcl();
   QString getprenomcl();
   QString getemailcl();
   QString gettypecl();

   void setcin(int);
   void setnumtelcl(QString);
   void settypecl(QString);
   void setnomcl(QString);
   void setprenomcl(QString);
   void setemailcl(QString);

    bool ajouter();
    QSqlQueryModel * afficherclient();
    QSqlQueryModel * affichertrie(int index);
    QSqlQueryModel * recherche(QString xd);
 bool modifierj(int cin ,QString nomcl , QString prenomcl ,QString emailcl ,QString typecl,QString numtelcl);
  bool supprimer(int);
void genererPDF();


private :
  QString nomcl,prenomcl;
  QString emailcl;
  int cin ;
  QString numtelcl;
  QString typecl;

};

#endif // CLIENT_H

