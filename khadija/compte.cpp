#include "compte.h"
#include <QDate>
#include <QDebug>
#include<QString>
#include<QMessageBox>
#include <QSqlQuery>

compte::compte(QString nomuitlisateur,QString mdp,int ide)
{

    this->nomuitlisateur=nomuitlisateur;
    this->mdp=mdp;
    this->ide=ide;

}
bool compte::ajouter(){
    QSqlQuery query;


        query.prepare("insert into COMPTES (MDP,NOMUTILISATEUR,IDE)""values(:MDP,:NOMUTILISATEUR,:IDE)");


        query.bindValue(0,mdp);
        query.bindValue(1,nomuitlisateur);
        query.bindValue(2,ide);




        return  query.exec();
}
bool compte::modifier(QString mdp,QString nomuitlisateur,int ide)
{
    QSqlQuery query;


    //prend la requête en paramètre pour préparer son execution
    query.prepare("update comptes set ide = :ide, NOMUTILISATEUR= :NOMUTILISATEUR , mdp= :mdp where IDE= :ide");

    //creation des variables liées
    query.bindValue(":mdp",mdp);
    query.bindValue(":nomuitlisateur",nomuitlisateur);
    query.bindValue(":ide",ide);



    return query.exec(); //envoie la requete pour l'executer
}
bool compte::supprimer(int ide)
{
    QSqlQuery query;
    QString res=QString::number(ide);
    query.prepare("delete from comptes where IDE=:ide");
    query.bindValue(":ide",res);
    return query.exec();
}
