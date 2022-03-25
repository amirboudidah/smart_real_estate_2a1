#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QTextStream>
#include "newwindow.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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

QTextStream T(mSocket);
T<< "eya"<<":"<<ui->message->text();
mSocket->flush();
ui->message->clear();
}

void Widget::on_connecter_clicked()
{


}

void Widget::on_fermerchat_clicked()
{
 this->close();
}
