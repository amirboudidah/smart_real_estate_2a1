#ifndef GESTIONAGENCE_H
#define GESTIONAGENCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class GestionAgence
{ QString nomAgence,ville,adresseA ,numtelA;
    int numAgence;
public: //constructeur
    GestionAgence(){};
    GestionAgence(QString,QString,QString,QString,int);

    //Getters
        QString getnomAgence(){return nomAgence;}
        QString getville(){return ville;}
        QString getadresseA(){return adresseA;}
        QString getnumtelA(){return numtelA;}
        int getnumAgence(){return numAgence;}

        //setters
        void setnomAgence(QString n){nomAgence=n;}
        void setville(QString v){ville=v;}
        void setadresseA(QString d){adresseA=d;}
        void setnumtelA(QString t){numtelA=t;}
        void setnumAgence(int numAgence){this->numAgence=numAgence;}
       //fonctionnalites de base relatives a l'entite etudiant
            bool ajouter();
            bool supprimer(int);
            QSqlQueryModel * afficher();
             bool Modifier(int,QString,QString,QString,QString);
             QSqlQueryModel * comboBoxAgence();
             QSqlQueryModel * testexist(QString);
             QSqlQueryModel * recherche(QString r);
             QSqlQueryModel * trier(QString r);
             void cartevisite(QString numAgence);
             QString calculchiffreaffaire();
};



#endif // GESTIONAGENCE_H
