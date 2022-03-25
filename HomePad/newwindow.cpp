
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
    ui->tableView->setModel(cont.afficher());
    ui->comboBox->setModel(cont.comboboxcontrat());
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

void newWindow::on_pushButton_27_clicked()//ajout
{
    bool test=false;
    QString typec;
    QString numcontratstring=ui->lineEdit_11->text();
    QString cinstring=ui->lineEdit_12->text();
    int numcontrat=ui->lineEdit_11->text().toInt();
    int cin=ui->lineEdit_12->text().toInt();
    QString contenu=ui->textEdit_4->toPlainText();
    if(ui->radioButton_5->isChecked())
        typec="achat";
    else
        typec="vendre";
    QString imageqr="qrcode_"+numcontratstring+".svg";
    QString datec=ui->dateEdit_3->date().toString("dd/MM/yyyy");
    gestioncontrats c(numcontrat,cin,typec,contenu,imageqr,datec);
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
        if (c.testexist(numcontratstring)->rowCount()==1)
        {
            QMessageBox::warning(this,"existe","click cancel to exit.");
        }
        else{
            QString code= ui->lineEdit_11->text()+"/"+ui->lineEdit_12->text();
            c.writeqrcode(code,ui->lineEdit_11->text());
        test=c.ajouter();

    ui->comboBox->setModel(cont.comboboxcontrat());
    ui->tableView->setModel(cont.afficher());//MISE AJOUR
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->textEdit_4->clear();
    ui->radioButton_5->setAutoExclusive(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_5->setAutoExclusive(true);
    ui->dateEdit_3->clear();
    if(test){
            QMessageBox::warning(this,"ajout effectue","click cancel to exit.");

        }
        else
            QMessageBox::warning(this,"ajout NON effectue","click cancel to exit.");}

}
}

void newWindow::on_pushButton_30_clicked()
{
    if(ui->comboBox->count()==0)
    {
        QMessageBox::warning(this,"WARNING","Rien a supprimer!");
    }
    else
    {
    int numcontrat=ui->comboBox->currentText().toInt();
    bool test=cont.supprimer(numcontrat);
    QFile file("C:/Users/amirb/Desktop/GitHub/HomePad/contrats/Contrat_"+ui->comboBox->currentText()+".pdf");
    QFile file1("C:/Users/amirb/Desktop/GitHub/HomePad/qrcodes/qrcode_"+ui->comboBox->currentText()+".png");
    file1.remove();
    QString mailtext="Bonjour!\nVotre contrat numero "+ui->comboBox->currentText()+" a ete supprimer \npour nous contacter utiliser ce mail: homepadinfo@gmail.com\nou bien sur ce numero telephone: 90322256";
    QString subject="Suppression du contrat numero "+ui->comboBox->currentText();
    cont.envoiemail(mailtext,subject,ui->comboBox->currentText());
    file.remove();

    ui->tableView->setModel(cont.afficher());
    ui->comboBox->setModel(cont.comboboxcontrat());
    if(test){
            QMessageBox::warning(this,"suppresion effectue","click cancel to exit.");

        }
        else
            QMessageBox::warning(this,"suppresion NON effectue","click cancel to exit.");

    }
}

void newWindow::on_lineEdit_11_textEdited(const QString &str)
{
    int flag = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->lineEdit_11->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_11->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag = 1;

            break;
        }
    }
}

void newWindow::on_lineEdit_12_textEdited(const QString &str)
{
    int flag = 0;

    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] >= '0') && (str[i] <= '9') )
          {
            ui->lineEdit_12->setStyleSheet("QLineEdit{border: 2px solid green}");

          }
        else
        {
            ui->lineEdit_12->setStyleSheet("QLineEdit{border: 2px solid red}");
            flag = 1;

            break;
        }
    }
}

void newWindow::on_pushButton_29_clicked()
{
    gestioncontrats c;
    if(ui->comboBox->currentText().count()==0)
    {
        QMessageBox::warning(this,"Warning","Rien a modifier!");
    }
    else
    {

        ui->tabWidget->setCurrentIndex(1);
        ui->pushButton_20->setEnabled(true);
        ui->lineEdit_11->setText(ui->comboBox->currentText());
        ui->lineEdit_11->setEnabled(false);
        QSqlQueryModel * model=c.testexist(ui->lineEdit_11->text());
        ui->lineEdit_12->setText(model->record(0).value(5).toString());
        ui->textEdit_4->setText(model->record(0).value(2).toString());
        if(model->record(0).value(1).toString()== "achat")
        {
            ui->radioButton_5->setChecked(true);
        }
        else if(model->record(0).value(1).toString()== "vendre")
        {
            ui->radioButton_6->setChecked(true);
        }
        ui->dateEdit_3->setDate(model->record(0).value(2).toDate());

    }
}

void newWindow::on_pushButton_19_clicked()
{
    ui->comboBox->setModel(cont.comboboxcontrat());
    ui->tableView->setModel(cont.afficher());//MISE AJOUR
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_10->clear();
}

void newWindow::on_comboBox_2_currentIndexChanged(int index)
{
    QString typetri;
    if(index==0)
    {
        ui->tableView->setModel(cont.afficher());
    }
    else if(index==1)
    {
        typetri="numcontrat";
        ui->tableView->setModel(cont.trier(typetri));
    }
    else if(index==2)
    {
        typetri="datec";
        ui->tableView->setModel(cont.trier(typetri));
    }
    else if(index==3)
    {
        typetri="cin";
        ui->tableView->setModel(cont.trier(typetri));
    }
    else if(index==4)
    {
        typetri="typec";
        ui->tableView->setModel(cont.trier(typetri));
    }



}

void newWindow::on_pushButton_28_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,
                                                 tr("open file"),
                                                 "C:/",
                                                 "All files(*.*);;Text File (*.txt);;Music file(*.mp3)"
                                                 );
    QFile file(filename);
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    ui->textEdit_4->setText(in.readAll());
}

void newWindow::on_pushButton_17_clicked()
{
    if(ui->comboBox->count()==0)
    {
        QMessageBox::warning(this,"WARNING","Rien a voir!");
    }
    else
    {
    gestioncontrats c;
    c.setNumcontrat(ui->comboBox->currentText().toInt());
    content= new contenu(this);
    content->setconrat(c);
    content->show();
    }
}

void newWindow::on_pushButton_2_clicked()
{

}

void newWindow::on_pushButton_16_clicked()
{
    if(ui->comboBox->count()==0)
    {
        QMessageBox::warning(this,"WARNING","Rien a exporter!");
    }
    else
    {
    gestioncontrats c;
    c.writePdf(ui->comboBox->currentText());
    }
}

void newWindow::on_pushButton_26_clicked()
{
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->textEdit_4->clear();
    ui->radioButton_5->setAutoExclusive(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_5->setAutoExclusive(true);
    ui->dateEdit_3->clear();
    ui->lineEdit_11->setEnabled(true);
    ui->pushButton_20->setEnabled(false);
}

void newWindow::on_lineEdit_10_textEdited(const QString &arg1)
{
    ui->tableView->setModel(cont.recherche(ui->lineEdit_10->text()));
}

void newWindow::on_pushButton_20_clicked()
{
    QString numcontratstring =ui->lineEdit_11->text();
    QString cinstring=ui->lineEdit_12->text();
    int numcontrat=ui->lineEdit_11->text().toInt();
    int cin=ui->lineEdit_12->text().toInt();
    QString contenu=ui->textEdit_4->toPlainText();
    QString typec;
    if(ui->radioButton_5->isChecked())
    {
        typec="achat";
    }
    else if(ui->radioButton_6->isChecked())
    {
        typec="vendre";
    }
    QString datec=ui->dateEdit_3->date().toString("dd/MM/yyyy");
    QString imageqr="C:/Users/amirb/Desktop/GitHub/HomePad/building.png";
    gestioncontrats c;
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

    bool test=c.Modifier(numcontrat,typec,contenu,imageqr,datec,cin);
    if(test){
            QMessageBox::warning(this,"modification effectue","click cancel to exit.");

            QString mailtext="Bonjour!\nVotre contrat numero "+ui->comboBox->currentText()+" a ete Modifier \npour nous contacter utiliser ce mail: homepadinfo@gmail.com\nou bien sur ce numero telephone: 90322256";
            QString subject="Modification du contrat numero "+ui->comboBox->currentText();
            cont.envoiemail(mailtext,subject,ui->comboBox->currentText());
            ui->lineEdit_11->clear();
            ui->lineEdit_12->clear();
            ui->textEdit_4->clear();
            ui->radioButton_5->setAutoExclusive(false);
            ui->radioButton_5->setChecked(false);
            ui->radioButton_5->setAutoExclusive(true);
            ui->dateEdit_3->clear();
            ui->pushButton_20->setEnabled(false);
            ui->lineEdit_11->setEnabled(true);
            ui->tableView->setModel(cont.afficher());
            ui->comboBox->setModel(cont.comboboxcontrat());
        }
        else
            QMessageBox::warning(this,"modification NON effectue","click cancel to exit.");

}
}
