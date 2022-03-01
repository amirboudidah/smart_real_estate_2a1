
#include "newwindow.h"
#include "ui_newwindow.h"
#include "gestionagence.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>
#include <QFormLayout>
#include <QIntValidator>
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
    ui->tableView->setModel(G.afficher());
    ui->lineEdit_6->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();

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



void newWindow::on_pushButton_4_clicked()
{
        int numAgence=ui->lineEdit_5->text().toInt();
        QString nomAgence=ui->lineEdit_6->text();
        QString ville=ui->lineEdit_8->text();
        QString adresseA=ui->lineEdit_26->text();
        QString numtelA=ui->lineEdit_27->text();
     GestionAgence A(nomAgence,ville,adresseA,numtelA,numAgence);
        bool test=A.ajouter();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_26->clear();
        ui->lineEdit_27->clear();
            ui->tableView->setModel(G.afficher());
        if(test){
//            QMessageBox::information(nullptr, QObject::tr("OK"),
//                       QObject::tr("ajout effectuer.\n"
//                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr("ajout non effectuer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


}

void newWindow::on_pushButton_6_clicked()
{
    int numAgence=ui->lineEdit_5->text().toInt();
    bool test=G.supprimer(numAgence);
        ui->tableView->setModel(G.afficher());
        ui->lineEdit_5->clear();
    if(test){
//        QMessageBox::information(nullptr, QObject::tr("OK"),
//                   QObject::tr("suppression effectuer.\n"
//                               "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("suppression non effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void newWindow::on_pushButton_5_clicked()
{
    int numAgence=ui->lineEdit_5->text().toInt();
    QString nomAgence=ui->lineEdit_6->text();
    QString ville=ui->lineEdit_8->text();
    QString adresseA=ui->lineEdit_26->text();
    QString numtelA=ui->lineEdit_27->text();
 GestionAgence A;
    bool test=A.Modifier(numAgence,nomAgence,ville,numtelA,adresseA);
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();
        ui->tableView->setModel(G.afficher());
    if(test){
//        QMessageBox::information(nullptr, QObject::tr("OK"),
//                   QObject::tr("ajout effectuer.\n"
//                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("ajout non effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void newWindow::on_lineEdit_5_textEdited(const QString &str)
{
    int flag = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->lineEdit_5->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_5->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag = 1;

            break;
        }
    }

    if(flag == 1)
        QMessageBox::warning(this,"Check","Wrong Input!");
}

void newWindow::on_lineEdit_6_textEdited(const QString &str)
{
            int flag = 0;

            for(int i = 0; i < str.length(); ++i)
            {
                if(    ((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))
)
                  {
                    ui->lineEdit_6->setStyleSheet("QLineEdit{border: 2px solid green}");

                  }
                else
                {
                    ui->lineEdit_6->setStyleSheet("QLineEdit{border: 2px solid red}");
                    flag = 1;

                    break;
                }
            }


//            if(flag == 1)
//                QMessageBox::warning(this,"Check","Wrong Input!");
}

void newWindow::on_lineEdit_27_textEdited(const QString &str)
{
    int flag = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if(    (((str[i] >= '0') && (str[i] <= '9') || (str[0]=='+')) && (str.length()==7 || str.length()==11))
)
          {
            ui->lineEdit_27->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_27->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag = 1;
        }
    }

}

void newWindow::on_lineEdit_26_textEdited(const QString &str)
{
    int flag = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if(    ((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z') || ((str[i] >= '0') && (str[i] <= '9')))
)
          {
            ui->lineEdit_26->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_26->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag = 1;

            break;
        }
    }
}
