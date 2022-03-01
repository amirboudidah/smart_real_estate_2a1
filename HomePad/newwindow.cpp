
#include "newwindow.h"
#include "ui_newwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QString>

newWindow::newWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item =new QListWidgetItem(QIcon(""),"gestion des Clients");
    ui->listWidget->addItem(item);
    QListWidgetItem *item2 =new QListWidgetItem(QIcon(""),"gestion des Employes");
    ui->listWidget->addItem(item2);
    QListWidgetItem *item3 =new QListWidgetItem(QIcon(""),"gestion des Agences");
    ui->listWidget->addItem(item3);
    QListWidgetItem *item4 =new QListWidgetItem(QIcon(""),"gestion des Produits");
    ui->listWidget->addItem(item4);
    QListWidgetItem *item5 =new QListWidgetItem(QIcon(""),"gestion des Contrats");
    ui->listWidget->addItem(item5);
    ui->listWidget->setCurrentItem(item);
//    QObject position;
//    int a=0;
//    while(ui->lineEdit_10->hasFocus()==true)
//    {
//        ui->tableView->setModel(cont.recherche(ui->lineEdit_10->text()));
//        a+=1;
//        qDebug() << ui->lineEdit_10->text() << this->focusWidget()->objectName() << a ;
//    }
//    if(ui->lineEdit_10->hasFocus()==false){
        ui->tableView->setModel(cont.afficher());
//    }


}

newWindow::~newWindow()
{
    delete ui;
}

//void newWindow::on_pushButton_2_clicked()
//{
//    newwindow1=new newWindow1(this);
//        newwindow1->show();
//        newWindow::hide();
//}

void newWindow::on_pushButton_2_clicked()
{

}



void newWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString s = ui->listWidget->currentItem()->text();
    if (s=="gestion des Clients"){
        ui->page->show();
        ui->page_3->hide();
        ui->page_4->hide();
        ui->page_2->hide();
        ui->page_5->hide();
    }
    else if(s=="gestion des Employes")
    {
            ui->page->hide();
            ui->page_3->hide();
            ui->page_4->hide();
            ui->page_2->show();
            ui->page_5->hide();
        }
    else if (s=="gestion des Agences")
    {
            ui->page->hide();
            ui->page_3->show();
            ui->page_4->hide();
            ui->page_2->hide();
            ui->page_5->hide();
        }
    else if (s=="gestion des Produits")
    {
            ui->page->hide();
            ui->page_3->hide();
            ui->page_4->show();
            ui->page_2->hide();
            ui->page_5->hide();
        }
    else if (s=="gestion des Contrats")
    {
            ui->page->hide();
            ui->page_3->hide();
            ui->page_4->hide();
            ui->page_2->hide();
            ui->page_5->show();
        }
}



void newWindow::on_pushButton_27_clicked()
{
    QString typec;
    int numcontrat=ui->lineEdit_11->text().toInt();
    int cin=ui->lineEdit_12->text().toInt();
    QString contenu=ui->textEdit_4->toPlainText();
    if(ui->radioButton_5->isChecked())
        typec="achat";
    else
        typec="vendre";
    QString imageqr="..\\HomePad";
    QString datec=ui->dateEdit_3->date().toString("dd/MM/yyyy");
    gestioncontrats c(numcontrat,cin,typec,contenu,imageqr,datec);
    bool test=c.ajouter();
    ui->tableView->setModel(cont.afficher());//MISE AJOUR
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->textEdit_4->clear();
    ui->radioButton_5->setAutoExclusive(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_5->setAutoExclusive(true);
    ui->dateEdit_3->clear();
    if(test){
    //        QMessageBox::information(nullptr, QObject::tr("OK"),
    //                    QObject::tr("AJOUT effectuer.\n"
    //                                "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("AJOUT non effectuer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void newWindow::on_pushButton_30_clicked()
{
    int numcontrat=ui->lineEdit_11->text().toInt();
    bool test=cont.supprimer(numcontrat);
    ui->tableView->setModel(cont.afficher());
    ui->lineEdit_11->clear();
    if(test){
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("suppression effectuer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("suppression non effectuer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void newWindow::on_lineEdit_10_cursorPositionChanged(int arg1, int arg2)
{
            ui->tableView->setModel(cont.recherche(ui->lineEdit_10->text()));
}
