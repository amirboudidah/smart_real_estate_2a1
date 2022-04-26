#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class compte
{
protected:
    QString nomuitlisateur, mdp;
    int ide;

public:
    //constructeur
    compte(){}
    compte(QString,QString,int);

    //Getters
    QString getnomuitlisateur(){return nomuitlisateur;}
    QString getmdp(){return mdp;}
    int getIde(){return ide;}


    //setters
    void setnomuitlisateur(QString nm){nomuitlisateur=nm;}
    void setmdp(QString m){mdp=m;}
    void setIde(int ide){this->ide=ide;}

    //fonctionnalites de base relatives a l'entite employe
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(QString,QString,int);

};


#endif // LOGIN_H
