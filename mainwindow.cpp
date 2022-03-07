#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employees.h"
#include "connection.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked()
{
    int ide=ui->lineEdit_ide->text().toInt();
    QString nome=ui->lineEdit_nome->text();
    QString prenome=ui->lineEdit_prenome->text();
    QString adressee=ui->lineEdit_adressee->text();
    QString numtel=ui->lineEdit_numtel->text();
    QString emaile=ui->lineEdit_emaile->text();
    QString role=ui->lineEdit_role->text();
     int numagence=ui->lineEdit_numagence->text().toInt();
    employees E(ide,nome,prenome,adressee,numtel,emaile,role,numagence);

    bool test=E.ajouter();
    if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("ajout effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("ajout non effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);





}
void MainWindow::on_pushButton_supprimer_clicked()
{
    int ide=ui->lineEdit_supp->text().toInt();
    bool test=Etmp.supprimer(ide);

    if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("suppression non effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_pushButton_modifier_clicked()
{
    //récupération des informations saisies
    int ide=ui->lineEdit->text().toInt();
//    int id=ui->update_id->text().toInt();
//    e.setId(ui->update_id->text().toInt())
       QString nome=ui->lineEdit_2->text();
       QString prenome=ui->lineEdit_3->text();
       QString adressee=ui->lineEdit_4->text();
       QString numtel=ui->lineEdit_5->text();
        QString emaile=ui->lineEdit_6->text();
         QString role=ui->lineEdit_7->text();
         int numagence=ui->lineEdit_8->text().toInt();
//    e.setNom(ui->new_nom->text());
//    e.setPrenom(ui->new_prenom->text());
//    etudiant e(id,nom,prenom);
    bool test=Etmp.modifier(ide,nome,prenome,adressee,numtel,emaile,role,numagence);
    if(test)
    {
        //REFRESH
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

