#include "newwindow.h"
#include "ui_newwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QComboBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPdfWriter>
#include <QSqlRecord>
#include <QMessageBox>
#include "gestionagence.h"
#include <QFormLayout>
#include <QIntValidator>
#include <QComboBox>
#include <QTcpSocket>


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
    ui->tablecontrats->setModel(cont.afficher());
    ui->comboBoxnumcontrat->setModel(cont.comboboxcontrat());
    ui->comboBoxidclientcontrat->setModel(cont.employespourcontrat());

    //***** eya/agence *****
    ui->tableagence->setModel(G.afficher());
    ui->comboBoxidagence->setModel(G.comboBoxAgence());
    ui->estimationchiffre->setText(G.calculchiffreaffaire()); //chiffre d'affaire
    ui->nomagence->clear();
    ui->ville->clear();
    ui->adresseagence->clear();
    ui->numtelagence->clear();
    //**********************
}

newWindow::~newWindow()
{
    delete ui;
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

void newWindow::on_pushButtonajoutcontrat_clicked()//ajout
{
    bool test=false;
    QString typec;
    QString numcontratstring=ui->numcontrat->text();
    QString cinstring=ui->comboBoxidclientcontrat->currentText();
    int numcontrat=ui->numcontrat->text().toInt();
    int cin=ui->comboBoxidclientcontrat->currentText().toInt();
    QString contenu=ui->textEditcontenucontrat->toPlainText();
    if(ui->radioButtonachatcontrat->isChecked())
        typec="achat";
    else
        typec="vendre";
    QString imageqr="qrcode_"+numcontratstring+".svg";
    QString datec=ui->dateEditcontrat->date().toString("dd/MM/yyyy");
    gestioncontrats c(numcontrat,cin,typec,contenu,imageqr,datec);
    int flag0=0;

    if(ui->radioButtonachatcontrat->isChecked() || ui->radioButtoncontratvendre->isChecked())
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
                ui->numcontrat->setStyleSheet("QLineEdit{border: 2px solid green}");
              }
            else
            {
                ui->numcontrat->setStyleSheet("QLineEdit{border: 2px solid red}");
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

    int flag3=0;

    if(ui->textEditcontenucontrat->document()->isEmpty())
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
        if (c.testexist(numcontratstring)->rowCount()==1)
        {
            QMessageBox::warning(this,"existe","click cancel to exit.");
        }
        else{
            QString code= ui->numcontrat->text()+"/"+ui->comboBoxidclientcontrat->currentText();
            c.writeqrcode(code,ui->numcontrat->text());
        test=c.ajouter();

    ui->comboBoxnumcontrat->setModel(cont.comboboxcontrat());
    ui->tablecontrats->setModel(cont.afficher());//MISE AJOUR
    ui->numcontrat->clear();
    ui->textEditcontenucontrat->clear();
    ui->radioButtonachatcontrat->setAutoExclusive(false);
    ui->radioButtonachatcontrat->setChecked(false);
    ui->radioButtonachatcontrat->setAutoExclusive(true);
    ui->dateEditcontrat->clear();
    if(test){
            QMessageBox::warning(this,"ajout effectue","click cancel to exit.");

        }
        else
            QMessageBox::warning(this,"ajout NON effectue","click cancel to exit.");}

}
}

void newWindow::on_supprimercontrat_clicked()
{
    if(ui->comboBoxnumcontrat->count()==0)
    {
        QMessageBox::warning(this,"WARNING","Rien a supprimer!");
    }
    else
    {
    int numcontrat=ui->comboBoxnumcontrat->currentText().toInt();
    bool test=cont.supprimer(numcontrat);
    QFile file("C:/Users/amirb/Desktop/project/HomePad/contrats/Contrat_"+ui->comboBoxnumcontrat->currentText()+".pdf");
    QFile file1("C:/Users/amirb/Desktop/project/HomePad/qrcodes/qrcode_"+ui->comboBoxnumcontrat->currentText()+".png");
    file1.remove();
    QString mailtext="Bonjour!\nVotre contrat numero "+ui->comboBoxnumcontrat->currentText()+" a ete supprimer \npour nous contacter utiliser ce mail: homepadinfo@gmail.com\nou bien sur ce numero telephone: 90322256";
    QString subject="Suppression du contrat numero "+ui->comboBoxnumcontrat->currentText();
    cont.envoiemail(mailtext,subject,ui->comboBoxnumcontrat->currentText());
    file.remove();

    ui->tablecontrats->setModel(cont.afficher());
    ui->comboBoxnumcontrat->setModel(cont.comboboxcontrat());
    if(test){
            QMessageBox::warning(this,"suppresion effectue","click cancel to exit.");

        }
        else
            QMessageBox::warning(this,"suppresion NON effectue","click cancel to exit.");

    }
}

void newWindow::on_numcontrat_textEdited(const QString &str)
{
    int flag = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->numcontrat->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->numcontrat->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag = 1;

            break;
        }
    }
}

void newWindow::on_gomodifiercontrat_clicked()
{
    gestioncontrats c;
    if(ui->comboBoxnumcontrat->currentText().count()==0)
    {
        QMessageBox::warning(this,"Warning","Rien a modifier!");
    }
    else
    {

        ui->tabWidget->setCurrentIndex(1);
        ui->pushButtonmodifiercontrat->setEnabled(true);
        ui->numcontrat->setText(ui->comboBoxnumcontrat->currentText());
        ui->numcontrat->setEnabled(false);
        QSqlQueryModel * model=c.testexist(ui->numcontrat->text());
        ui->textEditcontenucontrat->setText(model->record(0).value(2).toString());
        if(model->record(0).value(1).toString()== "achat")
        {
            ui->radioButtonachatcontrat->setChecked(true);
        }
        else if(model->record(0).value(1).toString()== "vendre")
        {
            ui->radioButtoncontratvendre->setChecked(true);
        }
        ui->dateEditcontrat->setDate(model->record(0).value(2).toDate());

    }
}

void newWindow::on_buttonrefreshcontrat_clicked()
{
    ui->comboBoxnumcontrat->setModel(cont.comboboxcontrat());
    ui->tablecontrats->setModel(cont.afficher());//MISE AJOUR
    ui->triercontrat->setCurrentIndex(0);
    ui->comboBoxnumcontrat->setCurrentIndex(0);
    ui->comboBoxidclientcontrat->setCurrentIndex(0);
    ui->recherchecontrat->clear();
}

void newWindow::on_triercontrat_currentIndexChanged(int index)
{
    QString typetri;
    if(index==0)
    {
        ui->tablecontrats->setModel(cont.afficher());
    }
    else if(index==1)
    {
        typetri="numcontrat";
        ui->tablecontrats->setModel(cont.trier(typetri));
    }
    else if(index==2)
    {
        typetri="datec";
        ui->tablecontrats->setModel(cont.trier(typetri));
    }
    else if(index==3)
    {
        typetri="cin";
        ui->tablecontrats->setModel(cont.trier(typetri));
    }
    else if(index==4)
    {
        typetri="typec";
        ui->tablecontrats->setModel(cont.trier(typetri));
    }



}

void newWindow::on_pushButtonchoisirtemplatecontrat_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,
                                                 tr("open file"),
                                                 "C:/",
                                                 "All files(*.*);;Text File (*.txt);;Music file(*.mp3)"
                                                 );
    QFile file(filename);
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    ui->textEditcontenucontrat->setText(in.readAll());
}

void newWindow::on_voirlerestecontrat_clicked()
{
    if(ui->comboBoxnumcontrat->count()==0)
    {
        QMessageBox::warning(this,"WARNING","Rien a voir!");
    }
    else
    {
    gestioncontrats c;
    c.setNumcontrat(ui->comboBoxnumcontrat->currentText().toInt());
    content= new contenu(this);
    content->setconrat(c);
    content->show();
    }
}

void newWindow::on_exportercontrat_clicked()
{
    if(ui->comboBoxnumcontrat->count()==0)
    {
        QMessageBox::warning(this,"WARNING","Rien a exporter!");
    }
    else
    {
    gestioncontrats c;
    c.writePdf(ui->comboBoxnumcontrat->currentText());
    }
}

void newWindow::on_buttonanulcontrat_clicked()
{
    ui->numcontrat->clear();
    ui->textEditcontenucontrat->clear();
    ui->radioButtonachatcontrat->setAutoExclusive(false);
    ui->radioButtonachatcontrat->setChecked(false);
    ui->radioButtonachatcontrat->setAutoExclusive(true);
    ui->dateEditcontrat->clear();
    ui->numcontrat->setEnabled(true);
    ui->pushButtonmodifiercontrat->setEnabled(false);
}

void newWindow::on_recherchecontrat_textEdited(const QString &arg1)
{
    ui->tablecontrats->setModel(cont.recherche(ui->recherchecontrat->text()));
}

void newWindow::on_pushButtonmodifiercontrat_clicked()
{
    QString numcontratstring =ui->numcontrat->text();
    QString cinstring=ui->comboBoxidclientcontrat->currentText();
    int numcontrat=ui->numcontrat->text().toInt();
    int cin=ui->comboBoxidclientcontrat->currentText().toInt();
    QString contenu=ui->textEditcontenucontrat->toPlainText();
    QString typec;
    if(ui->radioButtonachatcontrat->isChecked())
    {
        typec="achat";
    }
    else if(ui->radioButtoncontratvendre->isChecked())
    {
        typec="vendre";
    }
    QString datec=ui->dateEditcontrat->date().toString("dd/MM/yyyy");
    QString imageqr="C:/Users/amirb/Desktop/project/HomePad/qrcode_"+numcontratstring+".png";
    gestioncontrats c;
    int flag0=0;

    if(ui->radioButtonachatcontrat->isChecked() || ui->radioButtoncontratvendre->isChecked())
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
                ui->numcontrat->setStyleSheet("QLineEdit{border: 2px solid green}");
              }
            else
            {
                ui->numcontrat->setStyleSheet("QLineEdit{border: 2px solid red}");
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

    int flag3=0;

    if(ui->textEditcontenucontrat->document()->isEmpty())
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

    bool test=c.Modifier(numcontrat,typec,contenu,imageqr,datec,cin);
    if(test){
            QMessageBox::warning(this,"modification effectue","click cancel to exit.");

            QString mailtext="Bonjour!\nVotre contrat numero "+ui->comboBoxnumcontrat->currentText()+" a ete Modifier \npour nous contacter utiliser ce mail: homepadinfo@gmail.com\nou bien sur ce numero telephone: 90322256";
            QString subject="Modification du contrat numero "+ui->comboBoxnumcontrat->currentText();
            cont.envoiemail(mailtext,subject,ui->comboBoxnumcontrat->currentText());
            ui->numcontrat->clear();
            ui->textEditcontenucontrat->clear();
            ui->radioButtonachatcontrat->setAutoExclusive(false);
            ui->radioButtonachatcontrat->setChecked(false);
            ui->radioButtonachatcontrat->setAutoExclusive(true);
            ui->dateEditcontrat->clear();
            ui->pushButtonmodifiercontrat->setEnabled(false);
            ui->numcontrat->setEnabled(true);
            ui->tablecontrats->setModel(cont.afficher());
            ui->comboBoxnumcontrat->setModel(cont.comboboxcontrat());
        }
        else
            QMessageBox::warning(this,"modification NON effectue","click cancel to exit.");

}
}

void newWindow::on_radioButtonachatcontrat_clicked()
{
    if(ui->textEditcontenucontrat->toPlainText()=="")
    {
    QFile file("C:/Users/amirb/Desktop/project/HomePad/contratachat.txt");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    QSqlQueryModel* model=cont.specificemploye(ui->comboBoxidclientcontrat->currentText());
    QString contents = QString::fromUtf8(file.readAll());
    ui->textEditcontenucontrat->insertPlainText(contents);
    QTextCursor position(ui->textEditcontenucontrat->document());
    position.setPosition(130);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(0).toString());
    position.setPosition(79);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(1).toString()+" "+model->record(0).value(2).toString());
    ui->textEditcontenucontrat->append(ui->dateEditcontrat->text());
    }
    else{
        ui->textEditcontenucontrat->clear();
        QFile file("C:/Users/amirb/Desktop/project/HomePad/contratachat.txt");
        file.open(QFile::ReadOnly);
        QTextStream in(&file);
        QSqlQueryModel* model=cont.specificemploye(ui->comboBoxidclientcontrat->currentText());
        QString contents = QString::fromUtf8(file.readAll());
        ui->textEditcontenucontrat->insertPlainText(contents);
        QTextCursor position(ui->textEditcontenucontrat->document());
        position.setPosition(81);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(0).toString());
        position.setPosition(51);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(1).toString()+" "+model->record(0).value(2).toString());
        ui->textEditcontenucontrat->append(ui->dateEditcontrat->text());
    }
}

void newWindow::on_radioButtoncontratvendre_clicked()
{
    if(ui->textEditcontenucontrat->toPlainText()=="")
    {
    QFile file("C:/Users/amirb/Desktop/project/HomePad/contratvente.txt");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    QSqlQueryModel* model=cont.specificemploye(ui->comboBoxidclientcontrat->currentText());
    QString contents = QString::fromUtf8(file.readAll());
    ui->textEditcontenucontrat->insertPlainText(contents);
    QTextCursor position(ui->textEditcontenucontrat->document());
    position.setPosition(113);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(0).toString());
    position.setPosition(79);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(1).toString()+" "+model->record(0).value(2).toString());
    ui->textEditcontenucontrat->append(ui->dateEditcontrat->text());
    }
    else
    {
        ui->textEditcontenucontrat->clear();
        QFile file("C:/Users/amirb/Desktop/project/HomePad/contratvente.txt");
        file.open(QFile::ReadOnly);
        QTextStream in(&file);
        QSqlQueryModel* model=cont.specificemploye(ui->comboBoxidclientcontrat->currentText());
        QString contents = QString::fromUtf8(file.readAll());
        ui->textEditcontenucontrat->insertPlainText(contents);
        QTextCursor position(ui->textEditcontenucontrat->document());
        position.setPosition(107);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(0).toString());
        position.setPosition(77);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(1).toString()+" "+model->record(0).value(2).toString());
        ui->textEditcontenucontrat->append(ui->dateEditcontrat->text());
    }
}

//***** eya/agence *****
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

//**********************

