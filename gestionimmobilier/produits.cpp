#include "produits.h"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"QDebug"
#include"QObject"
#include<QDate>
#include<iostream>
using namespace std;
Produits::Produits()
{
ID_PRODUIT=0;TYPE_PRODUIT="";ADRESSE="";DESCRIPTION="";IMAGE="";
}
Produits::Produits(int ID_PRODUIT,QString TYPE_PRODUIT,QString ADRESSE,QString DESCRIPTION,QString IMAGE)
{
    this->ID_PRODUIT=ID_PRODUIT;
    this->TYPE_PRODUIT=TYPE_PRODUIT;
    this->ADRESSE=ADRESSE;
    this->DESCRIPTION=DESCRIPTION;
    this->IMAGE=IMAGE;

}
int Produits::getID_PRODUIT(){return ID_PRODUIT;}
QString Produits::getTYPE_PRODUIT(){return TYPE_PRODUIT;}
QString Produits::getADRESSE(){return ADRESSE;}
QString Produits::getDESCRIPTION(){return DESCRIPTION;}
QString Produits::getIMAGE(){return IMAGE;}

void Produits::setID_PRODUIT(int ID_PRODUIT){this->ID_PRODUIT=ID_PRODUIT;}
void Produits::setTYPE_PRODUIT(QString TYPE_PRODUIT){this->TYPE_PRODUIT=TYPE_PRODUIT;}
void Produits::setADRESSE(QString ADRESSE){this->ADRESSE=ADRESSE;}
void Produits::setDESCRIPTION(QString DESCRIPTION){this->DESCRIPTION=DESCRIPTION;}
void Produits::setIMAGE(QString IMAGE){this->IMAGE=IMAGE;}
bool Produits::ajout_pr(){
    bool test=false;
    QSqlQuery query;
     QString IDd_String=QString::number(ID_PRODUIT);
    query.prepare("INSERT INTO PRODUITS (ID_PRODUIT,TYPE_PRODUIT,ADRESSE,DESCRIPTION,IMAGE)"
                  "VALUES (:ID_PRODUIT,:TYPE_PRODUIT,:ADRESSE,:DESCRIPTION,:IMAGE)");
    query.bindValue(":ID_PRODUIT", IDd_String);
    query.bindValue(":TYPE_PRODUIT",TYPE_PRODUIT);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":DESCRIPTION",DESCRIPTION);
    query.bindValue(":IMAGE",IMAGE);
    query.exec();

return test;
}
QSqlQueryModel* Produits::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("IMAGE"));

    return model;
}
bool Produits::Supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from Produits where ID_Produit=:ID_Produit");
          query.bindValue(0, ID_PRODUIT);

         return query.exec();

}
bool Produits::modifier(int ID_Produit)
{

    QSqlQuery query;
    query.prepare("UPDATE Produits set TYPE_PRODUIT=:TYPE_PRODUIT,DESCRIPTION=:DESCRIPTION,ADRESSE=:ADRESSE,IMAGE=:IMAGE where ID_PRODUIT=:ID_PRODUIT ");
    query.bindValue(":ID_PRODUIT",ID_Produit);
    query.bindValue(":TYPE_PRODUIT",TYPE_PRODUIT);
    query.bindValue(":DESCRIPTION",DESCRIPTION);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":IMAGE",IMAGE);
    return query.exec();

}

QSqlQueryModel* Produits::recherche_produits(QString prod){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS where lower(cast(ID_PRODUIT as varchar2(20))) like (lower('"+prod+"%')) or lower(TYPE_PRODUIT) like (lower('"+prod+"%')) or lower(ADRESSE) like (lower('"+prod+"%'))");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel* Produits::trier_produits(QString prod){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS order by "+prod);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel* Produits::statistiqueprod(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT count(*),TYPE_PRODUIT FROM PRODUITS group by TYPE_PRODUIT ");

    return model;
}
