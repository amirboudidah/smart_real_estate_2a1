#include "employees.h"
#include <QDate>
#include <QDebug>
#include<QString>
#include<QMessageBox>

employees::employees(int ide,QString nome,QString prenome,QString adressee,QString numtel,QString emaile,QString role,int numagence)
{
    this->ide=ide;
    this->nome=nome;
    this->prenome=prenome;
    this->adressee=adressee;
    this->numtel=numtel;
    this->emaile=emaile;
    this->role=role;
    this->numagence=numagence;

}

bool employees::ajouter()
{
    QSqlQuery query;
    QString ide_string= QString::number(ide);
    QString numagence_string= QString::number(numagence);
    query.prepare("insert into employes (IDE,NOME,PRENOME,ADRESSEE,NUMTEL,EMAILE,ROLE,NUMAGENCE)" " values (:IDE,:NOME,:PRENOME,:ADRESSEE,:NUMTEL,:EMAILE,:ROLE,:NUMAGENCE)");

    query.bindValue(0, ide_string);
    query.bindValue(1, nome);
    query.bindValue(2, prenome);
    query.bindValue(3, adressee);
    query.bindValue(4, numtel);
    query.bindValue(5, emaile);
    query.bindValue(6, role);
    query.bindValue(7, numagence_string);

    return query.exec();
}

QSqlQueryModel * employees::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nome"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenome"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Adressee"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Numtel"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Emaile"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Numagence"));

    return model;
}

bool employees::supprimer(int ide)
{
    QSqlQuery query;
    QString res=QString::number(ide);
    query.prepare("delete from employes where IDE=:ide");
    query.bindValue(":ide",res);
    return query.exec();
}
bool employees::modifier(int ide,QString nome,QString prenome,QString adressee,QString numtel,QString emaile,QString role,int numagence)
{
    QSqlQuery query;

//    nom=getNom();
//    prenom=getPrenom();
    //prend la requête en paramètre pour préparer son execution
    query.prepare("update employes set ide = :ide, nome= :nome , prenome= :prenome, adressee= :adressee, numtel= :numtel, emaile= :emaile, role= :role, numagence= :numagence where IDE= :ide");

    //creation des variables liées
    query.bindValue(":ide",ide);
    query.bindValue(":nome",nome);
    query.bindValue(":prenome",prenome);
    query.bindValue(":adressee", adressee);
    query.bindValue(":numtel", numtel);
    query.bindValue(":emaile",emaile);
    query.bindValue(":role",role);
    query.bindValue(":numagence",numagence);
    return query.exec(); //envoie la requete pour l'executer
}
