#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<QIntValidator>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QDate>
#include<QTableWidget>
#include<QPixmap>
#include<QTextDocument>
 #include<QDesktopServices>
#include "client.h"
#include "QFile"
#include "QTextStream"
#include "historique.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);
   ui->cin->setValidator(new QIntValidator(0,999999,this));
   ui->emailcl->setValidator(new QRegExpValidator(  QRegExp("[a-z]{1,10}@[a-z]{1,4}\\.[a-z]{1,4}")  ));
   ui->nomcl->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
   ui->prenomcl->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//ajouter
{

        int cin=ui->cin->text().toInt();
        QString numtelcl=ui->numtelcl->text();

        QString nomcl=ui->nomcl->text();
        QString prenomcl=ui->prenomcl->text();

        QString emailcl(ui->emailcl->text());
        QString typecl(ui->typecl->currentText());
        qDebug() << ui->typecl->currentText();
    Historique h;
         h.save("nomcl:"+ui->nomcl->text(),"prenomcl :"+ui->prenomcl->text(),"numtelcl:"+ui->numtelcl->text());
         client c(cin,nomcl,prenomcl,emailcl,typecl,numtelcl);

    bool test=c.ajouter();
    ui->tableView->setModel(c.afficher());//MISE AJOUR
    ui->cin->clear();
    ui->nomcl->clear();
    ui->prenomcl->clear();
    ui->emailcl->clear();
    ui->numtelcl->clear();

    if(test)

            QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("Ajout avec succes\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    int cin=ui->cin->text().toInt();
    QString nomcl = ui->nomcl->text();
    QString prenomcl = ui->prenomcl->text();
    QString typecl(ui->typecl->currentText());
    QString numtelcl = ui->numtelcl->text();

    bool test=c->modifierj(ui->cin->text().toInt(),ui->nomcl->text(),ui->prenomcl->text(),ui->emailcl->text(),ui->typecl->currentText(),ui->numtelcl->text());
    ui->tableView->setModel(c->afficher());//MISE AJOUR
    ui->cin->clear();
    ui->nomcl->clear();
    ui->prenomcl->clear();
    ui->emailcl->clear();
    ui->numtelcl->clear();
        if (test)
              {


                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);}
}


void MainWindow::on_pushButton_6_clicked()
{
    client c1; c1.setcin(ui->sup->text().toInt());
    bool test=c1.supprimer(c1.getcin());
    ui->tableView->setModel(c->afficher());
    ui->sup->clear();
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("suppression avec succes.");
    }
    else
          msgBox.setText("echec d'ajout");
                msgBox.exec();
}



void MainWindow::on_pushButton_7_clicked()
{
  Historique h;
h.load();
h.load();
}

void MainWindow::on_pushButton_4_clicked()
{
    client c;
     c.genererPDF();
     QString link="C:/Users/user/Desktop/interfaceG_projet/liste.pdf";
         QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->tableView->setModel(c->affichertrie(index));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(c->recherche(arg1));

}
