#ifndef GESTIONCONTRATS_H
#define GESTIONCONTRATS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class gestioncontrats
{
    QString typec, contenu,imageqr,datec;
    int numcontrat,CIN;

public:
    //constructeur
    gestioncontrats(){}
    gestioncontrats(int,int,QString,QString,QString,QString);

    //Getters
    int getNumcontrat(){return numcontrat;}
    int getCIN(){return CIN;}
    QString getTypec(){return typec;}
    QString getContenu(){return contenu;}
    QString getImageqr(){return imageqr;}
    QString getDatec(){return datec;}

    //setters
    void setNumcontrat(int numcontrat){this->numcontrat=numcontrat;}
    void setCIN(int CIN){this->CIN=CIN;}
    void settypec(QString t){typec=t;}
    void setContenu(QString c){contenu=c;}
    void setImageqr(QString i){imageqr=i;}
    void setDatec(QString d){datec=d;}


    //fonctionnalites de base relatives a l'entite etudiant
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(QString ch);
};

#endif // GESTIONCONTRATS_H
