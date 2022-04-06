#include "modifieragence.h"
#include "ui_modifieragence.h"
#include <QMessageBox>
#include "gestionagence.h"
#include "QtDebug"
#include <QSqlQueryModel>
#include <QSqlRecord>


modifieragence::modifieragence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifieragence)
{
    ui->setupUi(this);
}

modifieragence::~modifieragence()
{
    delete ui;
}

void modifieragence::setagence(GestionAgence G)//affichage dans dialogue modifier
{
QString numAgence=QString::number(G.getnumAgence());
ui->lineEdit_5->setDisabled(true);
ui->lineEdit_5->setText(numAgence);
QSqlQueryModel * model=G.testexist(numAgence);
ui->lineEdit_6->setText(model->record(0).value(1).toString());
ui->lineEdit_8->setText(model->record(0).value(2).toString());
ui->lineEdit_27->setText(model->record(0).value(3).toString());
ui->lineEdit_26->setText(model->record(0).value(4).toString());
qDebug() << numAgence;
}

void modifieragence::on_lineEdit_5_textEdited(const QString &str)//controle saisi num agence
{
    if(ui->lineEdit_5->text().isEmpty())
        {
            QMessageBox::warning(this,"Check","Wrong Input!");
        }
    else{


    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->lineEdit_5->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_5->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }
    }
}

void modifieragence::on_lineEdit_6_textEdited(const QString &str)//controle saisi nom agence
{
    for(int i = 0; i < str.length(); ++i)
    {
        if(    (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) || (str[i] == ' '))
          {
            ui->lineEdit_6->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_6->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }

}

void modifieragence::on_lineEdit_8_textEdited(const QString &str)//controle saisi ville
{
    for(int i = 0; i < str.length(); ++i)
    {
        if(    (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) || (str[i] == ' '))
          {
            ui->lineEdit_8->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_8->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }
}

void modifieragence::on_lineEdit_26_textEdited(const QString &str)//controle saisi adresse
{

    for(int i = 0; i < str.length(); ++i)
    {
        if((((((str[i] >= 'A') && (str[i] <= 'Z')) ||( ((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= '0') && (str[i] <= '9'))) || (str[i] == ' ')) || (str[i] == '/')) || (str[i] == '\'')) || (str[i] == '.') )
          {
            ui->lineEdit_26->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_26->setStyleSheet("QLineEdit{border: 2px solid red}");

            break;
        }
    }
}

void modifieragence::on_lineEdit_27_textEdited(const QString &str)//controle saisi tel
{
    for(int i = 0; i < str.length(); ++i)
    {
        if((((str[i] >= '0') && (str[i] <= '9')) && (str.length()==8)) )
          {
            ui->lineEdit_27->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_27->setStyleSheet("QLineEdit{border: 2px solid red}");
        }
    }
}

void modifieragence::on_pushButton_4_clicked()//button modifier
{
    QString numAgencestring=ui->lineEdit_5->text();
    int numAgence=ui->lineEdit_5->text().toInt();
    QString nomAgence=ui->lineEdit_6->text();
    QString ville=ui->lineEdit_8->text();
    QString adresseA=ui->lineEdit_26->text();
    QString numtelA=ui->lineEdit_27->text();
    GestionAgence A;
int flag1 = 0;
if(ui->lineEdit_6->text().isEmpty())
     {
         flag1=1;
     }
else{
 for(int i = 0; i < nomAgence.length(); ++i)
 {
     if(    (((nomAgence[i] >= 'A') && (nomAgence[i] <= 'Z')) || ((nomAgence[i] >= 'a') && (nomAgence[i] <= 'z'))) || (nomAgence[i] == ' '))
       {
         ui->lineEdit_6->setStyleSheet("QLineEdit{border: 2px solid green}");

       }
     else
     {
         ui->lineEdit_6->setStyleSheet("QLineEdit{border: 2px solid red}");
         flag1 = 1;

         break;
     }
 }}

int flag2 = 0;
if(ui->lineEdit_5->text().isEmpty())
     {
         flag2=1;
     }
else{
 for(int i = 0; i < numAgencestring.length(); ++i)
 {
     if((numAgencestring[i] >= '0') && (numAgencestring[i] <= '9') )
       {
         ui->lineEdit_5->setStyleSheet("QLineEdit{border: 2px solid green}");

       }
     else
     {
         ui->lineEdit_5->setStyleSheet("QLineEdit{border: 2px solid red}");
         flag2 = 1;

         break;
     }
 }


 }

int flag3 = 0;
if(ui->lineEdit_27->text().isEmpty())
{
    flag3=1;
}
else
{
for(int i = 1; i < numtelA.length(); ++i)
{
    if((((numtelA[i] >= '0') && (numtelA[i] <= '9')) && (numtelA.length()==8)) )
      {
        ui->lineEdit_27->setStyleSheet("QLineEdit{border: 2px solid green}");

      }
    else
    {
        ui->lineEdit_27->setStyleSheet("QLineEdit{border: 2px solid red}");
        flag3 = 1;
    }
}
}

int flag4 = 0;
if (ui->lineEdit_26->text().isEmpty())
{
     flag4=1;
}
else{

         for(int i = 0; i < adresseA.length(); ++i)
         {
             if((((((adresseA[i] >= 'A') && (adresseA[i] <= 'Z')) ||( ((adresseA[i] >= 'a') && (adresseA[i] <= 'z')) || ((adresseA[i] >= '0') && (adresseA[i] <= '9'))) || (adresseA[i] == ' ')) || (adresseA[i] == '/')) || (adresseA[i] == '\'')) || (adresseA[i] == '.') )
               {
                 ui->lineEdit_26->setStyleSheet("QLineEdit{border: 2px solid green}");

               }
             else
             {
                 ui->lineEdit_26->setStyleSheet("QLineEdit{border: 2px solid red}");
                 flag4 = 1;

                 break;
             }
         }

}

int  flag5=0;
if(ui->lineEdit_8->text().isEmpty())
 {
     flag5=1;
 }
else
 {
     for(int i = 0; i < ville.length(); ++i)
     {
         if(    (((ville[i] >= 'A') && (ville[i] <= 'Z')) || ((ville[i] >= 'a') && (ville[i] <= 'z'))) || (ville[i] == ' '))
           {
             ui->lineEdit_8->setStyleSheet("QLineEdit{border: 2px solid green}");

           }
         else
         {
             ui->lineEdit_8->setStyleSheet("QLineEdit{border: 2px solid red}");
             flag5 = 1;

             break;
         }
     }

 }

if(flag1==1)
QMessageBox::warning(this,"nom agence","Wrong Input!");
else if (flag2==1)
QMessageBox::warning(this,"num agence","Wrong Input!");
else if(flag3==1)
QMessageBox::warning(this,"num tel","Wrong Input!");
else if(flag4==1)
QMessageBox::warning(this,"adresse","Wrong Input!");
else if(flag5==1)
QMessageBox::warning(this,"ville","Wrong Input!");
else{
    bool test=A.Modifier(numAgence,nomAgence,ville,adresseA,numtelA);
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();
    if(test){
         QMessageBox::warning(this,"modification effectue","Click Cancel to exit.");
    }
    else{
          QMessageBox::warning(this,"modification non effectue","Click Cancel to exit.");
}
}
}
