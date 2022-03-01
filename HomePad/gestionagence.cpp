#include "gestionagence.h"
#include <QSqlQuery>

GestionAgence::GestionAgence(QString nomAgence,QString ville,QString adresseA,QString numtelA,int numAgence)
{
     this->nomAgence=nomAgence;
     this->ville=ville;
     this->adresseA=adresseA;
     this->numtelA=numtelA;
     this->numAgence=numAgence;

}
bool GestionAgence::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(numAgence);
    query.prepare("insert into agences(nomAgence,ville,adresseA,numtelA,numAgence) values (:nomAgence,:ville,:adresseA,:numtelA,:numAgence)");
    query.bindValue(":numAgence",res);
    query.bindValue(":nomAgence",nomAgence);
    query.bindValue(":ville",ville);
    query.bindValue(":adresseA",adresseA);
    query.bindValue(":numtelA",numtelA);
     return query.exec();

}
bool GestionAgence::supprimer(int numAgence)
{
    QSqlQuery query;
    QString res=QString::number(numAgence);
    query.prepare("delete from agences where NUMAGENCE=:numAgence");
    query.bindValue(":numAgence",res);
    return query.exec();
}
QSqlQueryModel * GestionAgence::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from agences");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numAgence"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomAgence"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtelA"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresseA"));




    return model;
}
bool GestionAgence::Modifier(int numAgence,QString nomAgence,QString ville,QString adresseA,QString numtelA)
{
    QSqlQuery query;
    QString res= QString::number(numAgence);
    query.prepare("update agences set nomAgence=:nomAgence,ville=:ville,numtelA=:numtelA,adresseA=:adresseA where numAgence=:numAgence");
    query.bindValue(":numAgence",numAgence);
    query.bindValue(":nomAgence",nomAgence);
    query.bindValue(":ville",ville);
    query.bindValue(":adresseA",adresseA);
    query.bindValue(":numtelA",numtelA);
     return query.exec();

}
