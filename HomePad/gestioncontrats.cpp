#include "gestioncontrats.h"
#include <QDate>
#include <QDebug>
gestioncontrats::gestioncontrats(int numcontrat,int CIN,QString typec,QString contenu,QString imageqr,QString datec)
{
    this->numcontrat=numcontrat;
    this->CIN=CIN;
    this->typec=typec;
    this->contenu=contenu;
    this->imageqr=imageqr;
    this->datec=datec;

}

bool gestioncontrats::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(numcontrat);
    QString res1= QString::number(CIN);

    QDate da = QDate::fromString(datec,"dd/MM/yyyy");
    query.prepare("insert into contrats (numcontrat,CIN,typeC,contenu,imageqr,datec) values (:numcontrat,:CIN,:typec,:contenu,:imageqr,:datec)");

    query.bindValue(":numcontrat",res);
    query.bindValue(":CIN",res1);
    query.bindValue(":typec",typec);
    query.bindValue(":contenu",contenu);
    query.bindValue(":imageqr",imageqr);
    query.bindValue(":datec",da);

    return query.exec();
}

QSqlQueryModel * gestioncontrats::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from contrats");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numContrat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("imageqr"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN"));

    return model;
}

bool gestioncontrats::supprimer(int numcontrat)
{
    QSqlQuery query;
    QString res=QString::number(numcontrat);
    query.prepare("delete from contrats where numcontrat=:numcontrat");
    query.bindValue(":numcontrat",res);
    return query.exec();
}

bool gestioncontrats::Modifier(int numContrat,QString typec,QString contenu,QString imageqr,QString datec,int cin)
{
    QSqlQuery query;

    QDate da = QDate::fromString(datec,"dd/MM/yyyy");
    query.prepare("update contrats set CIN=:CIN,typeC=:typec,contenu=:contenu,imageqr=:imageqr,datec=:datec where numcontrat=:numcontrat");

    query.bindValue(":numcontrat",numContrat);
    query.bindValue(":CIN",cin);
    query.bindValue(":typec",typec);
    query.bindValue(":contenu",contenu);
    query.bindValue(":imageqr",imageqr);
    query.bindValue(":datec",da);

    return query.exec();

}

QSqlQueryModel * gestioncontrats::recherche(QString ch)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    model->setQuery(("select * from contrats where cast(numcontrat as varchar(20)) like('"+ch+"%') or cast(CIN as varchar(20)) like('"+ch+"%') or typec like('"+ch+"%') or cast(datec as varchar(20)) like('"+ch+"%')"));
    return model;
}

QSqlQueryModel * gestioncontrats::trier(QString type)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(type=="datec")
    {
        model->setQuery("select * from contrats order by "+type+" DESC");
    }
    else
    {
        model->setQuery("select * from contrats order by "+type);
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numContrat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("imageqr"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN"));

    return model;
}

QSqlQueryModel * gestioncontrats::comboboxcontrat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select numContrat from contrats");
    return model;
}

QSqlQueryModel * gestioncontrats::testexist(QString numcontrat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from contrats where cast(numcontrat as varchar(20))="+numcontrat);
    return model;
}


