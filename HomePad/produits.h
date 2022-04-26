#ifndef PRODUITS_H
#define PRODUITS_H
#include"QSqlQueryModel"
#include"QString"

class Produits
{
public:
    Produits();
    Produits(int ID_PRODUIT ,QString TYPE_PRODUIT,QString ADRESSE,QString DESCRIPTION ,QString IMAGE );

    int getID_PRODUIT() ;
    QString getTYPE_PRODUIT() ;
    QString getADRESSE() ;
    QString getDESCRIPTION() ;
    QString getIMAGE() ;

    void setID_PRODUIT(int);
    void setTYPE_PRODUIT( QString);
    void setADRESSE( QString);
    void setDESCRIPTION( QString);
    void setIMAGE( QString);
    bool ajout_pr();
    QSqlQueryModel* afficher();
   bool Supprimer(int);
   bool modifier (int);
   QSqlQueryModel* recherche_produits(QString prod);
    QSqlQueryModel* trier_produits(QString prod);
    QSqlQueryModel* statistiqueprod();

private:
    int ID_PRODUIT;
    QString TYPE_PRODUIT,ADRESSE,DESCRIPTION,IMAGE;

};

#endif // PRODUITS_H
