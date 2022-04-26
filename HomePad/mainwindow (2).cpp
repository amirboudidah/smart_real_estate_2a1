#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employees.h"
#include "newwindow.h"
#include "connection.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>
#include<QComboBox>
#include"compte.h"
#include "popup.h"

int test=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
popUp = new PopUp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow ::rech(QString nomuitlisateur,QString mdp )
{


    QSqlQuery query;
    query.prepare("select * from COMPTES where NOMUTILISATEUR=:NOMUTILISATEUR");
    query.bindValue(":NOMUTILISATEUR",nomuitlisateur);
    if(query.exec()){
        query.next();
        if(query.value(0)== mdp){
             saveID(query.value(2).toString());
             test = 1;
        }else {
             test = 0;
        }
    }else {
        test = 0;
    }

    return test;
}

void MainWindow::saveID(QString id)
{    QFile file ("C:/Users/amirb/Desktop/HomePad-Copie/id.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out <<id<<endl;


}

QString MainWindow::loadID()
{
QString tmp="";
    QFile file("C:/Users/amirb/Desktop/HomePad-Copie/id.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {


         QString myString = in.readLine();
         tmp=myString;


   }
   return tmp;
}

void MainWindow::on_pushButton_clicked()
{
    QString n = ui->lineEdit_ut->text();
    QString mdp = ui->lineEdit_mdp->text();
    if(MainWindow::rech(n,mdp)==1) {
        QMessageBox::information(this, "Login", "Username and password is correct");
        newWindow *myLog = new newWindow();
        //Close the welcome class

        //open the Login class
        popUp->setPopupText(" connexion !!");

        popUp->show();
        myLog->show();
        this->close();

    }
    else {
        QMessageBox::warning(this,"Login", "username and password is not correct");
    }
}





