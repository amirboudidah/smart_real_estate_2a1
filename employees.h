#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class employees
{
protected:
    QString nome, prenome, adressee ,numtel, emaile, role;
    int ide,numagence;

public:
    //constructeur
    employees(){}
    employees(int,QString,QString,QString,QString,QString,QString,int);

    //Getters
    QString getNome(){return nome;}
    QString getPrenome(){return prenome;}
    QString getAdressee(){return adressee;}
    QString getNumtel(){return numtel;}
    QString getEmaile(){return emaile;}
    QString getRole(){return role;}
    int getNumagence(){return numagence;}
    int getIde(){return ide;}


    //setters
    void setNome(QString n){nome=n;}
    void setPrenome(QString p){prenome=p;}
    void setAdressee(QString a){adressee=a;}
    void setNumtel(QString t){numtel=t;}
    void setEmaile(QString e){emaile=e;}
    void setRole(QString r){role=r;}
    void setNumagence(int numagence){this->numagence=numagence;}
    void setIde(int ide){this->ide=ide;}

    //fonctionnalites de base relatives a l'entite employe
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int,QString,QString,QString,QString,QString,QString,int);
};

#endif // EMPLOYEES_H
