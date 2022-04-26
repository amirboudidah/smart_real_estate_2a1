#include "employees.h"
#include <QDate>
#include <QDebug>
#include<QString>
#include<QMessageBox>
#include <QSqlQuery>

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
bool employees::ajouter_note()
{
    QSqlQuery query;
    query.prepare("insert into evaluation (NOTE)" " values (:NOTE)");

    query.bindValue(0, "non satisfait");


    return query.exec();
}
bool employees::ajouter_note2()
{
    QSqlQuery query;
    query.prepare("insert into evaluation (NOTE)" " values (:NOTE)");

    query.bindValue(0, "satisfait");


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
QSqlQueryModel * employees::afficher2()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from evaluation");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOTE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DATEN"));

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
QSqlQueryModel * employees::comboBoxemployes()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select ide  from employes");

    return model;
}
QSqlQueryModel * employees::comboBox_2_employes()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select ide  from employes");

    return model;
}
QSqlQueryModel * employees::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employes order by nome");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("ide"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nome"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenome"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adressee"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("emaile"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("numagence"));
    return model;
}

QSqlQueryModel * employees::tri_ide()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employes order by ide");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("ide"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nome"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenome"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adressee"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("emaile"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("numagence"));
    return model;
}

QSqlQueryModel * employees::recherche(QString  ch)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    model->setQuery("select * from employes where lower(cast(ide as varchar(20))) like lower(('"+ch+"%')) or lower(cast(numagence as varchar(20))) like lower(('"+ch+"%')) ");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ide"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nome"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenome"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adressee"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("emaile"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("role"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numagence"));
    return model;
}
QSqlQueryModel * employees::rechercheemploye(QString  ch)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    model->setQuery("select * from employes where cast(ide as varchar(20))='"+ch+"'");
    return model;
}



