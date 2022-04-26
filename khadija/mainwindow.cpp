#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employees.h"
#include "employes.h"
#include "connection.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>
#include<QComboBox>
#include"compte.h"

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
             test = 1;
        }else {
             test = 0;
        }
    }else {
        test = 0;
    }

    return test;
}




void MainWindow::on_pushButton_clicked()
{
    employes *myLog = new employes();

    //Close the welcome class
    this->close();

    //open the Login class
    myLog->show();
}

void MainWindow::on_pushButton_2_clicked()
{

    QString n = ui->lineEdit_ut->text();
    QString mdp = ui->lineEdit_mdp->text();
    if(MainWindow::rech(n,mdp)==1) {
        QMessageBox::information(this, "Login", "Username and password is correct");
        employes *myLog = new employes();
        //Close the welcome class
        this->close();
        //open the Login class
        myLog->show();
        popUp->setPopupText(" connexion !!");

        popUp->show();
    }
    else {
        QMessageBox::warning(this,"Login", "username and password is not correct");
    }
}




