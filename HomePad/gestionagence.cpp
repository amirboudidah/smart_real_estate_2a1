#include "gestionagence.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QFile>
#include <QSqlRecord>
#include <QDebug>

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
    query.prepare("update agences set nomAgence=:nomAgence,ville=:ville,numtelA=:numtelA,adresseA=:adresseA where numAgence=:numAgence");
    query.bindValue(":numAgence",numAgence);
    query.bindValue(":nomAgence",nomAgence);
    query.bindValue(":ville",ville);
    query.bindValue(":adresseA",adresseA);
    query.bindValue(":numtelA",numtelA);
    return query.exec();

}
QSqlQueryModel * GestionAgence::comboBoxAgence()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select numAgence from agences");

    return model;
}

QSqlQueryModel * GestionAgence::testexist(QString numAgence)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from agences where cast(numagence as varchar(20))="+numAgence);
    return model;
}

QSqlQueryModel * GestionAgence::recherche(QString r)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from agences where lower(cast(numagence as varchar(20))) like lower('"+r+"%') or lower(ville) like lower('"+r+"%') or lower(nomagence) like lower('"+r+"%')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numAgence"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomAgence"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtelA"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresseA"));
    return model;
}

QSqlQueryModel * GestionAgence::trier(QString r)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from agences order by "+r);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numAgence"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomAgence"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ville"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("numtelA"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresseA"));
    return model;
}

void GestionAgence::cartevisite(QString numAgence)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from agences where cast(numagence as varchar(20))="+numAgence);
    QSqlQueryModel * model1=new QSqlQueryModel();
    model1->setQuery("select * from employes where cast(numagence as varchar(20))="+numAgence+" and role='gerant'");
    QString adresse=model->record(0).value(4).toString();
    QString numtel=model->record(0).value(3).toString();
    QString nomgerant=model1->record(0).value(1).toString();
    QString prenomgerant=model1->record(0).value(2).toString();
GestionAgence c;
//***** creer le fichier pdf *****
QString filename="C:/Users/eyamo/Desktop/smart_real_estate_2a1/HomePad/cartevisite/cartevisite.pdf"; //cree un fichier dans ce path
QPdfWriter pdfwriter(filename);
pdfwriter.setPageSize(QPageSize(QPageSize::A4));
QPainter painter(&pdfwriter); //varriable necessaire pour ecrire dans pdf

//***** ecrire dans le pdf *****
QImage cartevisitetemplate("C:/Users/eyamo/Desktop/smart_real_estate_2a1/HomePad/cartevistetemplate.png");
painter.drawImage(0,0,cartevisitetemplate);//dans pdf
painter.setFont(QFont("times",11));
painter.drawText(2420,8700,adresse);
painter.drawText(2420,7700,numtel);
painter.drawText(3300,6400,nomgerant);
painter.drawText(3300,6600,prenomgerant);
painter.end();//stop ecriture dans pdf
}

QString GestionAgence::calculchiffreaffaire()
{
    int comachat=2;
    int comvente=4;
    int minbudgetmat=20;
    int maxbudgetmat=70;
    int minbudgetpub=50;
    int maxbudgetpub=200;
    int totalsalaire;
    int totalprod;
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select count(*) from employes where role='employe'");
    int salaireemp=model->record(0).value(0).toInt()*1.2*12;
    model->setQuery("select count(*) from employes where role='gerant'");
    int salaireger=model->record(0).value(0).toInt()*3*12;
    totalsalaire=salaireemp+salaireger;

    model->setQuery("select count(*) from contrats where typec='achat'");
    int prodachat=model->record(0).value(0).toInt()*comachat;
    model->setQuery("select count(*) from contrats where typec='vente'");
    int prodvente=model->record(0).value(0).toInt()*comvente;
    totalprod=prodachat+prodvente;

    int totalmin=totalprod+totalsalaire+minbudgetmat+minbudgetpub;
    int totalmax=totalprod+totalsalaire+maxbudgetmat+maxbudgetpub;
    qDebug() << totalmin;
    QString stringtotalmin=QString::number(totalmin);
    QString stringtotalmax=QString::number(totalmax);
    QString estimation="min : "+stringtotalmin+",000,000 max : "+stringtotalmax+",000,000";

    return estimation;
}

