#include "modifier.h"
#include "ui_modifier.h"
#include"produits.h"
#include"QMessageBox"

Modifier::Modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
    ui->Type->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->Description->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));

}

Modifier::~Modifier()
{
    delete ui;
}
void Modifier::setID_PRODUIT(int ID_PRODUIT){
QString IDd_String=QString::number(ID_PRODUIT);

   ui->ID_Produit->setText(IDd_String);
}
void Modifier::setTYPE_PRODUIT(QString TYPE_PRODUIT){

   ui->Type->setText(TYPE_PRODUIT);
}
void Modifier::setDESCRIPTION(QString DESCRIPTION){

   ui->Description->setText(DESCRIPTION);
}
void Modifier::setADRESSE(QString ADRESSE){


   ui->Adresse->setText(ADRESSE);
}
void Modifier::setIMAGE(QString IMAGE){


   ui->Image->setText(IMAGE);
}

void Modifier::on_pushButton_clicked()
{
    int ID_Produit=ui->ID_Produit->text().toInt();
    QString ID_AB_STRING= QString::number(ID_Produit);
    QString TYPE_PRODUIT=ui->Type->text();
    QString DESCRIPTION=ui->Description->text();
    QString ADRESSE=ui->Adresse->text();
    QString IMAGE=ui->Image->text();
    Produits a(ID_Produit,TYPE_PRODUIT,DESCRIPTION,ADRESSE,IMAGE);
    bool test=a.modifier(ID_Produit);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
