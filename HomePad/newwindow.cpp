
#include "newwindow.h"
#include "ui_newwindow.h"
#include "gestionagence.h"
#include "modifieragence.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>
#include <QFormLayout>
#include <QIntValidator>
#include <QComboBox>
#include <QTcpSocket>
#include <QTextStream>

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
    ui->comboBox->setModel(G.comboBoxAgence());
    ui->label_12->setText(G.calculchiffreaffaire()); //chiffre d'affaire
    ui->lineEdit_6->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_26->clear();
    ui->lineEdit_27->clear();

}

newWindow::~newWindow()
{
    delete ui;
}

void newWindow::on_pushButton_2_clicked()//boutton recherche NON FONCTIONEL
{

}

void newWindow::on_listWidget_itemClicked(QListWidgetItem *item)//side bar
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

void newWindow::on_pushButton_4_clicked()//boutton ajouter avec controle saisi
{
        QString numAgencestring=ui->lineEdit_5->text();
        int numAgence=ui->lineEdit_5->text().toInt();
        QString nomAgence=ui->lineEdit_6->text();
        QString ville=ui->lineEdit_8->text();
        QString adresseA=ui->lineEdit_26->text();
        QString numtelA=ui->lineEdit_27->text();
     GestionAgence A(nomAgence,ville,adresseA,numtelA,numAgence);
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
    if(A.testexist(numAgencestring)->rowCount()==1)
    { QMessageBox::warning(this," il existe deja","Click Cancel to exit."); }
    else{
        bool test=A.ajouter();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_26->clear();
        ui->lineEdit_27->clear();
        ui->tableView->setModel(G.afficher());
        ui->comboBox->setModel(G.comboBoxAgence());
        ui->label_12->setText(G.calculchiffreaffaire());
        if(test){
             QMessageBox::warning(this,"ajout effectue","Click Cancel to exit.");
        }
        else{
              QMessageBox::warning(this,"ajout non effectue","Click Cancel to exit.");
}
}

}
}

void newWindow::on_pushButton_6_clicked()// boutton supprimer
{
    int numAgence=ui->comboBox->currentText().toInt();

    bool test=G.supprimer(numAgence);
        ui->tableView->setModel(G.afficher());
        ui->comboBox->setModel(G.comboBoxAgence());

    if(test){

       QMessageBox::warning(this,"suppression effectue","Click Cancel to exit.");
    }


    else

 QMessageBox::warning(this,"suppression non effectue","Click Cancel to exit.");

}

void newWindow::on_pushButton_5_clicked()// ouvrir la modification (page ajouter)
{
ui->tabWidget_2->setCurrentIndex(0);
ui->pushButton_7->setEnabled(true);
ui->lineEdit_5->setText(ui->comboBox->currentText());
ui->lineEdit_5->setEnabled(false);
GestionAgence g;
QSqlQueryModel * model=g.testexist(ui->lineEdit_5->text());
ui->lineEdit_6->setText(model->record(0).value(1).toString());
ui->lineEdit_8->setText(model->record(0).value(2).toString());
ui->lineEdit_27->setText(model->record(0).value(3).toString());
ui->lineEdit_26->setText(model->record(0).value(4).toString());
ui->label_12->setText(G.calculchiffreaffaire());
}

void newWindow::on_lineEdit_5_textEdited(const QString &str) //numagence
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

void newWindow::on_lineEdit_6_textEdited(const QString &str) //nomagence
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

void newWindow::on_lineEdit_27_textEdited(const QString &str) //tel
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

void newWindow::on_lineEdit_26_textEdited(const QString &str) //adresse
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

void newWindow::on_lineEdit_8_textEdited(const QString &str) //ville
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

void newWindow::on_pushButton_3_clicked()//refresh
{
    ui->tableView->setModel(G.afficher());
    ui->comboBox->setModel(G.comboBoxAgence());//numagence
    ui->comboBox->setCurrentIndex(0); //numagence
    ui->comboBox_2->setCurrentIndex(0); //tri
    ui->label_12->setText(G.calculchiffreaffaire());//calcul chiffreaffaire


    ui->lineEdit->clear();
}

void newWindow::on_lineEdit_textEdited(const QString &str)//recherche
{
    ui->tableView->setModel(G.recherche(str));
}

void newWindow::on_comboBox_2_currentIndexChanged(int index)//tri
{
    QString t;
    if (index==0)
    {
        ui->tableView->setModel(G.afficher());
    }
    else if(index==1)
    {
        t="numagence";
        ui->tableView->setModel(G.trier(t));
    }
    else if(index==2)
    {
        t="nomagence";
        ui->tableView->setModel(G.trier(t));
    }
    else if(index==3)
    {
        t="ville";
        ui->tableView->setModel(G.trier(t));
    }
}

void newWindow::on_pushButton_7_clicked() //button modifier (page ajouter)
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

    if(test){
         QMessageBox::warning(this,"modification effectue","Click Cancel to exit.");
         ui->lineEdit_5->clear();
         ui->lineEdit_6->clear();
         ui->lineEdit_8->clear();
         ui->lineEdit_26->clear();
         ui->lineEdit_27->clear();
         ui->lineEdit_5->setEnabled(true);
         ui->pushButton_7->setEnabled(false);
         ui->tableView->setModel(G.afficher()); //si ilya une modification il va afficher
         ui->comboBox->setModel(G.comboBoxAgence());//refresh combobox
         ui->label_12->setText(G.calculchiffreaffaire());
    }
    else{
          QMessageBox::warning(this,"modification non effectue","Click Cancel to exit.");
}
}
}

void newWindow::on_pushButton_8_clicked() //button chat
{
    widget = new Widget(this);
    widget->show();
}

void newWindow::on_carteviste_clicked() //button pdf
{
    QString numagence="1";
    G.cartevisite(numagence);
}
