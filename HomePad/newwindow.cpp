
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
    ui->tableagence->setModel(G.afficher());
    ui->comboBoxidagence->setModel(G.comboBoxAgence());
    ui->estimationchiffre->setText(G.calculchiffreaffaire()); //chiffre d'affaire
    ui->nomagence->clear();
    ui->ville->clear();
    ui->adresseagence->clear();
    ui->numtelagence->clear();

}

newWindow::~newWindow()
{
    delete ui;
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

void newWindow::on_ajouterA_clicked()//boutton ajouter avec controle saisi
{
        QString numAgencestring=ui->numagence->text();
        int numAgence=ui->numagence->text().toInt();
        QString nomAgence=ui->nomagence->text();
        QString ville=ui->ville->text();
        QString adresseA=ui->adresseagence->text();
        QString numtelA=ui->numtelagence->text();
     GestionAgence A(nomAgence,ville,adresseA,numtelA,numAgence);
     int flag1 = 0;
     if(ui->nomagence->text().isEmpty())
         {
             flag1=1;
         }
     else{
     for(int i = 0; i < nomAgence.length(); ++i)
     {
         if(    (((nomAgence[i] >= 'A') && (nomAgence[i] <= 'Z')) || ((nomAgence[i] >= 'a') && (nomAgence[i] <= 'z'))) || (nomAgence[i] == ' '))
           {
             ui->nomagence->setStyleSheet("QLineEdit{border: 2px solid green}");

           }
         else
         {
             ui->nomagence->setStyleSheet("QLineEdit{border: 2px solid red}");
             flag1 = 1;

             break;
         }
     }}

     int flag2 = 0;
     if(ui->numagence->text().isEmpty())
         {
             flag2=1;
         }
     else{
     for(int i = 0; i < numAgencestring.length(); ++i)
     {
         if((numAgencestring[i] >= '0') && (numAgencestring[i] <= '9') )
           {
             ui->numagence->setStyleSheet("QLineEdit{border: 2px solid green}");

           }
         else
         {
             ui->numagence->setStyleSheet("QLineEdit{border: 2px solid red}");
             flag2 = 1;

             break;
         }
     }


     }
     int flag3 = 0;
    if(ui->numtelagence->text().isEmpty())
    {
        flag3=1;
    }
    else
{
    for(int i = 1; i < numtelA.length(); ++i)
    {
        if((((numtelA[i] >= '0') && (numtelA[i] <= '9')) && (numtelA.length()==8)) )
          {
            ui->numtelagence->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->numtelagence->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag3 = 1;
        }
    }
}


     int flag4 = 0;
     if (ui->adresseagence->text().isEmpty())
  {
         flag4=1;
  }
             else{

             for(int i = 0; i < adresseA.length(); ++i)
             {
                 if((((((adresseA[i] >= 'A') && (adresseA[i] <= 'Z')) ||( ((adresseA[i] >= 'a') && (adresseA[i] <= 'z')) || ((adresseA[i] >= '0') && (adresseA[i] <= '9'))) || (adresseA[i] == ' ')) || (adresseA[i] == '/')) || (adresseA[i] == '\'')) || (adresseA[i] == '.') )
                   {
                     ui->adresseagence->setStyleSheet("QLineEdit{border: 2px solid green}");

                   }
                 else
                 {
                     ui->adresseagence->setStyleSheet("QLineEdit{border: 2px solid red}");
                     flag4 = 1;

                     break;
                 }
             }

}
    int  flag5=0;
     if(ui->ville->text().isEmpty())
     {
         flag5=1;
     }
     else
     {
         for(int i = 0; i < ville.length(); ++i)
         {
             if(    (((ville[i] >= 'A') && (ville[i] <= 'Z')) || ((ville[i] >= 'a') && (ville[i] <= 'z'))) || (ville[i] == ' '))
               {
                 ui->ville->setStyleSheet("QLineEdit{border: 2px solid green}");

               }
             else
             {
                 ui->ville->setStyleSheet("QLineEdit{border: 2px solid red}");
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
        ui->numagence->clear();
        ui->nomagence->clear();
        ui->ville->clear();
        ui->adresseagence->clear();
        ui->numtelagence->clear();
        ui->tableagence->setModel(G.afficher());
        ui->comboBoxidagence->setModel(G.comboBoxAgence());
        ui->estimationchiffre->setText(G.calculchiffreaffaire());
        if(test){
             QMessageBox::warning(this,"ajout effectue","Click Cancel to exit.");
        }
        else{
              QMessageBox::warning(this,"ajout non effectue","Click Cancel to exit.");
}
}

}
}

void newWindow::on_supprimeragence_clicked()// boutton supprimer
{
    int numAgence=ui->comboBoxidagence->currentText().toInt();

    bool test=G.supprimer(numAgence);
        ui->tableagence->setModel(G.afficher());
        ui->comboBoxidagence->setModel(G.comboBoxAgence());

    if(test){

       QMessageBox::warning(this,"suppression effectue","Click Cancel to exit.");
    }


    else

 QMessageBox::warning(this,"suppression non effectue","Click Cancel to exit.");

}

void newWindow::on_gomodiferA_clicked()// ouvrir la modification (page ajouter)
{
ui->agencetabwidget->setCurrentIndex(0);
ui->modifierA->setEnabled(true);
ui->numagence->setText(ui->comboBoxidagence->currentText());
ui->numagence->setEnabled(false);
GestionAgence g;
QSqlQueryModel * model=g.testexist(ui->numagence->text());
ui->nomagence->setText(model->record(0).value(1).toString());
ui->ville->setText(model->record(0).value(2).toString());
ui->numtelagence->setText(model->record(0).value(3).toString());
ui->adresseagence->setText(model->record(0).value(4).toString());
ui->estimationchiffre->setText(G.calculchiffreaffaire());
}

void newWindow::on_numagence_textEdited(const QString &str) //numagence
{
    if(ui->numagence->text().isEmpty())
        {
            QMessageBox::warning(this,"Check","Wrong Input!");
        }
    else{


    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->numagence->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->numagence->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }
    }
}

void newWindow::on_nomagence_textEdited(const QString &str) //nomagence
{
            for(int i = 0; i < str.length(); ++i)
            {
                if(    (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) || (str[i] == ' '))
                  {
                    ui->nomagence->setStyleSheet("QLineEdit{border: 2px solid green}");

                  }
                else
                {
                    ui->nomagence->setStyleSheet("QLineEdit{border: 2px solid red}");
                    break;
                }
            }



}

void newWindow::on_numtelagence_textEdited(const QString &str) //tel
{
    for(int i = 0; i < str.length(); ++i)
    {
        if((((str[i] >= '0') && (str[i] <= '9')) && (str.length()==8)) )
          {
            ui->numtelagence->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->numtelagence->setStyleSheet("QLineEdit{border: 2px solid red}");
        }
    }

}

void newWindow::on_adresseagence_textEdited(const QString &str) //adresse
{
    for(int i = 0; i < str.length(); ++i)
    {
        if((((((str[i] >= 'A') && (str[i] <= 'Z')) ||( ((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= '0') && (str[i] <= '9'))) || (str[i] == ' ')) || (str[i] == '/')) || (str[i] == '\'')) || (str[i] == '.') )
          {
            ui->adresseagence->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->adresseagence->setStyleSheet("QLineEdit{border: 2px solid red}");

            break;
        }
    }
}

void newWindow::on_ville_textEdited(const QString &str) //ville
{
    for(int i = 0; i < str.length(); ++i)
    {
        if(    (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) || (str[i] == ' '))
          {
            ui->ville->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->ville->setStyleSheet("QLineEdit{border: 2px solid red}");
            break;
        }
    }
}

void newWindow::on_refreshA_clicked()//refresh
{
    ui->tableagence->setModel(G.afficher());
    ui->comboBoxidagence->setModel(G.comboBoxAgence());//numagence
    ui->comboBoxidagence->setCurrentIndex(0); //numagence
    ui->comboBoxtrieagence->setCurrentIndex(0); //tri
    ui->estimationchiffre->setText(G.calculchiffreaffaire());//calcul chiffreaffaire


    ui->rechercheragence->clear();
}

void newWindow::on_rechercheragence_textEdited(const QString &str)//recherche
{
    ui->tableagence->setModel(G.recherche(str));
}

void newWindow::on_comboBoxtrieagence_currentIndexChanged(int index)//tri
{
    QString t;
    if (index==0)
    {
        ui->tableagence->setModel(G.afficher());
    }
    else if(index==1)
    {
        t="numagence";
        ui->tableagence->setModel(G.trier(t));
    }
    else if(index==2)
    {
        t="nomagence";
        ui->tableagence->setModel(G.trier(t));
    }
    else if(index==3)
    {
        t="ville";
        ui->tableagence->setModel(G.trier(t));
    }
}

void newWindow::on_modifierA_clicked() //button modifier (page ajouter)
{
    QString numAgencestring=ui->numagence->text();
    int numAgence=ui->numagence->text().toInt();
    QString nomAgence=ui->nomagence->text();
    QString ville=ui->ville->text();
    QString adresseA=ui->adresseagence->text();
    QString numtelA=ui->numtelagence->text();
    GestionAgence A;
int flag1 = 0;
if(ui->nomagence->text().isEmpty())
     {
         flag1=1;
     }
else{
 for(int i = 0; i < nomAgence.length(); ++i)
 {
     if(    (((nomAgence[i] >= 'A') && (nomAgence[i] <= 'Z')) || ((nomAgence[i] >= 'a') && (nomAgence[i] <= 'z'))) || (nomAgence[i] == ' '))
       {
         ui->nomagence->setStyleSheet("QLineEdit{border: 2px solid green}");

       }
     else
     {
         ui->nomagence->setStyleSheet("QLineEdit{border: 2px solid red}");
         flag1 = 1;

         break;
     }
 }}

int flag2 = 0;
if(ui->numagence->text().isEmpty())
     {
         flag2=1;
     }
else{
 for(int i = 0; i < numAgencestring.length(); ++i)
 {
     if((numAgencestring[i] >= '0') && (numAgencestring[i] <= '9') )
       {
         ui->numagence->setStyleSheet("QLineEdit{border: 2px solid green}");

       }
     else
     {
         ui->numagence->setStyleSheet("QLineEdit{border: 2px solid red}");
         flag2 = 1;

         break;
     }
 }


 }

int flag3 = 0;
if(ui->numtelagence->text().isEmpty())
{
    flag3=1;
}
else
{
for(int i = 1; i < numtelA.length(); ++i)
{
    if((((numtelA[i] >= '0') && (numtelA[i] <= '9')) && (numtelA.length()==8)) )
      {
        ui->numtelagence->setStyleSheet("QLineEdit{border: 2px solid green}");

      }
    else
    {
        ui->numtelagence->setStyleSheet("QLineEdit{border: 2px solid red}");
        flag3 = 1;
    }
}
}

int flag4 = 0;
if (ui->adresseagence->text().isEmpty())
{
     flag4=1;
}
else{

         for(int i = 0; i < adresseA.length(); ++i)
         {
             if((((((adresseA[i] >= 'A') && (adresseA[i] <= 'Z')) ||( ((adresseA[i] >= 'a') && (adresseA[i] <= 'z')) || ((adresseA[i] >= '0') && (adresseA[i] <= '9'))) || (adresseA[i] == ' ')) || (adresseA[i] == '/')) || (adresseA[i] == '\'')) || (adresseA[i] == '.') )
               {
                 ui->adresseagence->setStyleSheet("QLineEdit{border: 2px solid green}");

               }
             else
             {
                 ui->adresseagence->setStyleSheet("QLineEdit{border: 2px solid red}");
                 flag4 = 1;

                 break;
             }
         }

}

int  flag5=0;
if(ui->ville->text().isEmpty())
 {
     flag5=1;
 }
else
 {
     for(int i = 0; i < ville.length(); ++i)
     {
         if(    (((ville[i] >= 'A') && (ville[i] <= 'Z')) || ((ville[i] >= 'a') && (ville[i] <= 'z'))) || (ville[i] == ' '))
           {
             ui->ville->setStyleSheet("QLineEdit{border: 2px solid green}");

           }
         else
         {
             ui->ville->setStyleSheet("QLineEdit{border: 2px solid red}");
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
         ui->numagence->clear();
         ui->nomagence->clear();
         ui->ville->clear();
         ui->adresseagence->clear();
         ui->numtelagence->clear();
         ui->numagence->setEnabled(true);
         ui->modifierA->setEnabled(false);
         ui->tableagence->setModel(G.afficher()); //si ilya une modification il va afficher
         ui->comboBoxidagence->setModel(G.comboBoxAgence());//refresh combobox
         ui->estimationchiffre->setText(G.calculchiffreaffaire());
    }
    else{
          QMessageBox::warning(this,"modification non effectue","Click Cancel to exit.");
}
}
}

void newWindow::on_chatbox_clicked() //button chat
{
    widget = new Widget(this);
    widget->show();
}

void newWindow::on_carteviste_clicked() //button pdf
{
    QString numagence="1";
    G.cartevisite(numagence);
}
