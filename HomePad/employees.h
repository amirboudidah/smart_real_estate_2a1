#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class employees
{
protected:
    QString nome, prenome, adressee ,numtel, emaile, role,nomutilisateur,mdp;
    int ide,numagence;

public:
    //constructeur
    employees(){}
    employees(int,QString,QString,QString,QString,QString,QString,int);
    employees(QString,QString);

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
     QSqlQueryModel * afficher2();
    bool supprimer(int);
     bool modifier(int,QString,QString,QString,QString,QString,QString,int);
     bool ajouter_note();
     bool ajouter_note2();
      QSqlQueryModel *  comboBoxemployes();
      QSqlQueryModel* tri_nom();
      QSqlQueryModel* tri_ide();
      QSqlQueryModel * recherche(QString ch);
       QSqlQueryModel *  comboBox_2_employes();
      QSqlQueryModel * rechercheemploye(QString  ch);
};

#endif // EMPLOYEES_H
