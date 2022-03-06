#include "modifiercontrat.h"
#include "ui_modifiercontrat.h"
#include "gestioncontrats.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QtDebug>
#include <QModelIndex>

modifiercontrat::modifiercontrat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiercontrat)
{
    ui->setupUi(this);
}

modifiercontrat::~modifiercontrat()
{
    delete ui;
}

void modifiercontrat::setconrat(gestioncontrats c)
{
    QString s = QString::number(c.getNumcontrat());
    ui->lineEdit_11->setDisabled(true);
    ui->lineEdit_11->setText(s);
    QSqlQueryModel *model=c.testexist(s);
    ui->tableView->setModel(model);
    ui->lineEdit_12->setText(ui->tableView->model()->data(ui->tableView->model()->index(0,5)).toString());
    if(ui->tableView->model()->data(ui->tableView->model()->index(0,1)).toString()=="vendre")
    {
        ui->radioButton_6->setChecked(true);
    }
    else if (ui->tableView->model()->data(ui->tableView->model()->index(0,1)).toString()=="achat")
    {
        ui->radioButton_5->setChecked(true);
    }

    ui->textEdit_4->setText(ui->tableView->model()->data(ui->tableView->model()->index(0,2)).toString());
    ui->dateEdit_3->setDate(ui->tableView->model()->data(ui->tableView->model()->index(0,4)).toDate());
    ui->tableView->hide();
}

void modifiercontrat::on_pushButton_27_clicked()
{

    bool test=false;
    gestioncontrats c;
    int numcontrat=ui->lineEdit_11->text().toInt();
    QString typec;
    QString numcontratstring=ui->lineEdit_11->text();
    QString cinstring=ui->lineEdit_12->text();

    int cin=ui->lineEdit_12->text().toInt();
    QString contenu=ui->textEdit_4->toPlainText();
    if(ui->radioButton_5->isChecked())
        typec="achat";
    else
        typec="vendre";
    QString imageqr="..\\HomePad";
    QString datec=ui->dateEdit_3->date().toString("dd/MM/yyyy");
    int flag0=0;

    if(ui->radioButton_5->isChecked() || ui->radioButton_6->isChecked())
    {
        flag0=0;

    }
    else flag0=1;

    int flag1 = 0;

    if (numcontratstring.isEmpty())
    {
        flag1=1;
    }
    else
    {
        for(int i = 0; i < numcontratstring.length(); ++i)
        {
            if((numcontratstring[i] >= '0') && (numcontratstring[i] <= '9') )
              {
                ui->lineEdit_11->setStyleSheet("QLineEdit{border: 2px solid green}");
              }
            else
            {
                ui->lineEdit_11->setStyleSheet("QLineEdit{border: 2px solid red}");
                flag1 = 1;

                break;
            }
        }
    }

    int flag2 = 0;

    if(cinstring.isEmpty())
    {
        flag2=1;
    }
    else
    {
    for(int i = 0; i < cinstring.length(); ++i)
    {
        if((cinstring[i] >= '0') && (cinstring[i] <= '9') )
          {
            ui->lineEdit_12->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_12->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag2 = 1;

            break;
        }
    }
    }

    int flag3=0;

    if(ui->textEdit_4->document()->isEmpty())
    {
        flag3=1;
    }

    if(flag0==1)
        QMessageBox::warning(this,"type/contenu","Wrong Input!");
    else if (flag1==1)
        QMessageBox::warning(this,"numcontrat","Wrong Input!");
    else if (flag2==1)
        QMessageBox::warning(this,"idclient","Wrong Input!");
    else if (flag3==1)
        QMessageBox::warning(this,"contenu","Wrong Input!");
    else {

        test=c.Modifier(numcontrat,typec,contenu,imageqr,datec,cin);
    if(test){
            QMessageBox::warning(this,"modification effectue","click cancel to exit.");

        }
        else
            QMessageBox::warning(this,"modification NON effectue","click cancel to exit.");}

}

void modifiercontrat::on_lineEdit_11_textEdited(const QString &str)
{
    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->lineEdit_11->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_11->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }
}

void modifiercontrat::on_lineEdit_12_textEdited(const QString &str)
{
    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->lineEdit_12->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_12->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }
}
