#include "immobilier.h"
#include "ui_immobilier.h"
#include"produits.h"
#include"QMessageBox"
#include"QSqlQuery"
#include"QSqlRecord"
#include"QDebug"
#include"modifier.h"
immobilier::immobilier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::immobilier)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestion immobiliers");
    Produits p;
    ui->ID_Produit->setValidator( new QIntValidator(0, 9999, this));

    ui->Type->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->Description->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->typemod->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->decmod->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));

    ui->tableView->setModel(p.afficher());
QSqlQuery queryt;
    queryt.prepare("SELECT id_produit FROM produits");
          queryt.exec();
          queryt.first();
          int groupid_equipement = queryt.record().indexOf("id_produit");
   ui->comboBox_3->addItem(queryt.value(0).toString());
qDebug()<<queryt.value(0);
          while (queryt.next()) {

                ui->comboBox_3->addItem(queryt.value(groupid_equipement).toString());
}
qDebug()<<queryt.value(groupid_equipement);

}

immobilier::~immobilier()
{
    delete ui;
}

void immobilier::on_pushButton_clicked()
{
    int ID_PRODUIT=ui->ID_Produit->text().toInt();
    QString TYPE_Produit=ui->Type->text();
    QString ADRESSE=ui->Adresse->text();
    QString DESCRIPTION=ui->Description->text();
    QString IMAGE=ui->Image->text();
    if(ui->Type->text().isEmpty() and ui->Adresse->text().isEmpty() and ui->Description->text().isEmpty()){
        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("Il faut au moin un champ remplit \n"), QMessageBox::Cancel);

    }
    else{
    Produits p(ID_PRODUIT,TYPE_Produit,ADRESSE,DESCRIPTION,IMAGE);
    QMessageBox msg;
    bool test=p.ajout_pr();


    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                    QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

}
    else if(ui->ID_Produit->text().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }

}}

void immobilier::on_pushButton_8_clicked()
{
    Produits p1;
    p1.setID_PRODUIT(ui->comboBox_3->currentText().toInt());
    bool test=p1.Supprimer(p1.getID_PRODUIT());
    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
    else if(ui->comboBox_3->currentText().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


}

void immobilier::on_pushButton_6_clicked()
{
    Modifier m;

      m.setID_PRODUIT(ui->comboBox_3->currentText().toInt());
      QSqlQuery qry;
      int ID_PRODUIT=ui->comboBox_3->currentText().toInt();
        QString ID_AB_STRING= QString::number(ID_PRODUIT);
        qry.prepare("SELECT * from Produits where ID_PRODUIT='"+ID_AB_STRING+"'");
         if (qry.exec())
            {
             while (qry.next()) {
                QString TYPE_PRODUIT=qry.value(1).toString();
              m.setTYPE_PRODUIT(TYPE_PRODUIT);
              QString DESCRIPTION=qry.value(2).toString();
           m.setDESCRIPTION(DESCRIPTION);
           QString ADRESSE=qry.value(3).toString();
            m.setADRESSE(ADRESSE);
            QString IMAGE=qry.value(4).toString();
             m.setIMAGE(IMAGE);
              m.exec();
   }
   }
}
