#include "client.h"
#include<QString>
#include<QtSql/QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QtSql/QSqlQueryModel>
#include<QPdfWriter>
#include<QPainter>
#include<QMessageBox>
#include<QSystemTrayIcon>

//constructeur sans parametre
client::client()
{

    cin=0;
    nomcl=" ";
    prenomcl=" ";
    numtelcl="";
    typecl=" ";
    emailcl="";


}
//constructeur avec parametre
client::client(int cin,QString nomcl,QString prenomcl,QString emailcl,QString typecl,QString numtelcl)
{
    this->nomcl=nomcl;
    this->prenomcl=prenomcl;
    this->cin=cin;
    this->typecl=typecl;
    this->emailcl=emailcl;
    this->numtelcl=numtelcl;



}

//les getters
int client::getcin(){return cin;}
QString client::getnumtelcl(){return numtelcl;}
QString client::getemailcl(){return emailcl;}
QString client::gettypecl(){return typecl;}
QString client::getnomcl(){return nomcl;}
QString client::getprenomcl(){return prenomcl;}


//les setters

void client::setcin(int cin){this->cin=cin ;}
void client::setnumtelcl(QString numtelcl){this->numtelcl=numtelcl ;}
void client::settypecl(QString typecl){this->typecl=typecl ;}
void client::setemailcl(QString emailcl){this->emailcl=emailcl  ;}
void client::setnomcl(QString nomcl){this->nomcl=nomcl   ;}
void client::setprenomcl(QString prenomcl){this->prenomcl=prenomcl   ;}

bool client::ajouter()
{
    bool test=false;
    QSqlQuery query;

        QString CIN_string=QString::number(cin);

          query.prepare("INSERT INTO CLIENTS (cin,nomcl,prenomcl,emailcl,typecl,numtelcl) VALUES (:cin, :nomcl, :prenomcl , :emailcl  , :typecl , :numtelcl )");
          query.bindValue(":cin" , CIN_string);
          query.bindValue(":nomcl" , nomcl);
          query.bindValue(":prenomcl", prenomcl);
          query.bindValue(":emailcl" ,emailcl);
          query.bindValue(":type",typecl );
          query.bindValue(":numtelcl", numtelcl);

          query.exec();
    return test;
}


QSqlQueryModel * client ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomcl "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomcl "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("emailcl "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("typecl"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("numtelcl "));

        return model;
}

bool client::modifierj(int cin ,QString nomcl , QString prenomcl  ,QString emailcl,QString typecl ,QString numtelcl)
{
    QSqlQuery query;

    query.prepare("UPDATE CLIENTS SET NOMCL= :nomcl,PRENOMCL= :prenomcl, EMAILCL= :emailcl, TYPECL= :typecl , NUMTELCL= :numtelcl  where CIN= :cin ");
    query.bindValue(":cin", cin);
    query.bindValue(":nomcl",nomcl);
    query.bindValue(":prenomcl", prenomcl);
    query.bindValue(":emailcl",emailcl);
    query.bindValue(":typecl",typecl);
    query.bindValue(":numtelcl",numtelcl);

            return    query.exec();
}

bool client :: supprimer(int id)
{

    QSqlQuery query;
    query.prepare("DELETE from CLIENTS where cin = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
QSqlQueryModel * trie(){

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENTS ORDER BY NOMCL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomcl "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomcl "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("emailcl "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("typecl"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("numtelcl "));

        return model;
}

