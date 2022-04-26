#include "chatbox.h"
#include "ui_chatbox.h"
#include <QTcpSocket>
#include <QTextStream>
#include "newwindow.h"
#include "mainwindow.h"
#include "gestionagence.h"
#include <QSqlRecord>
#include "newwindow.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connexion avec serveur
    mSocket= new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(mSocket);
       auto text =T.readAll();
       ui->textEdit->append(text);
    });
    newWindow D(this);
    mSocket->connectToHost(D.hostname(), D.port());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_envoyer_clicked()
{
MainWindow m;
GestionAgence g;
QString test;
QSqlQueryModel* model=g.rechercheemployea(idemploye);
QTextStream T(mSocket);
T<< model->record(0).value(2).toString() <<":"<<ui->message->text(); //utilisateur
mSocket->flush(); //envoyer le msg au serveur
ui->message->clear();
}


void Widget::on_fermerchat_clicked()
{
 this->close();
}
