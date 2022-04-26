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
#include "chatbox.h"

#include "employees.h"
#include "connection.h"
#include "historique.h"
#include <QPushButton>
#include "compte.h"
#include <QVBoxLayout>
#include <QTimer>
#include <QFileInfo>
#include "QFile"
#include <QAction>
#include <QFileDialog>

#include<QIntValidator>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDate>
#include<QTableWidget>
#include<QPixmap>
#include<QTextDocument>
 #include<QDesktopServices>
#include "client.h"
#include "QTextStream"
#include "historique.h"
#include "QCamera"
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include "mainwindow.h"

#include"produits.h"
#include"QMessageBox"
#include"QSqlQuery"
#include"QSqlRecord"
#include"QDebug"
#include"modifier.h"
#include<QTextDocument>
#include<QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewWidget>
#include<QFileDialog>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QTimer *timer2 = new QTimer();//refresh

QTimer *timer8 = new QTimer();
newWindow::newWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newWindow)
{
    MainWindow m;
        id_e=m.loadID();
        id_emp=id_e.toInt();
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
    ui->stackedWidget->setCurrentIndex(0);
gestioncontrats contrat;
QSqlQueryModel *username;
username=contrat.specificemploye(id_e);
ui->usernamegen->setText(username->record(0).value(1).toString()+" "+username->record(0).value(2).toString());
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
    //********************** khadija /employes *************//
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView_2->setModel(Etmp.afficher2());
    ui->lineEdit_ID->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_agence->setValidator(new QIntValidator(0,999,this));
    ui->comboBox->setModel(Etmp.comboBoxemployes());
    ui->comboBox_2->setModel(Etmp.comboBoxemployes());
    //**************************
    int ret=ardrfid.connect_arduinorfid(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< ardrfid.getarduinorfid_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" << ardrfid.getarduinorfid_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(ardrfid.getserial(),SIGNAL(readyRead()),this,SLOT(update_labelrfid())); // permet de lancer
     //**************** khadija arduino *****************//

//     connect(timer8, SIGNAL(timeout()), this, SLOT(update_label_kh()));

//     timer8->start(100);

     popUp = new PopUp();

//********* AMENI ********
     ui->cin->setValidator(new QIntValidator(0,999999,this));
     ui->emailcl->setValidator(new QRegExpValidator(  QRegExp("[a-z]{1,100}@[a-z]{1,5}\\.[a-z]{1,4}")  ));
     ui->nomcl->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
     ui->prenomcl->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));



     mCamera= new QCamera (this);
     mCameraViewfinder = new QCameraViewfinder (this);
     mCameraImageCapture = new QCameraImageCapture(mCamera,this);
     mLayout = new QVBoxLayout ;
     mCamMenu = new QMenu("camera",this);
     mAllumerAction = new QAction("allumer",this);
     mEteindreAction = new QAction("eteindre",this);
     mCapturerAction = new QAction("capturer",this);

     mCamMenu->addActions({mAllumerAction,mEteindreAction,mCapturerAction});
     ui->cam->setMenu(mCamMenu);
     mCamera->setViewfinder(mCameraViewfinder);
     mLayout->addWidget(mCameraViewfinder);
     mLayout->setMargin(0);
     ui->scrollArea->setLayout(mLayout);

     connect(mAllumerAction,&QAction::triggered,[&](){
       mCamera->start();
     });
     connect(mEteindreAction,&QAction::triggered,[&](){
        mCamera->stop();
     });
     connect(mCapturerAction,&QAction::triggered,[&](){
       auto filename=  QFileDialog::getSaveFileName(this,"capturer","/","image(*.jpg;*.jpeg)");
       if(filename.isEmpty()){
           return ;
       }

       mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
       QImageEncoderSettings imageEncoderSettings;
       imageEncoderSettings.setCodec("image/jpeg");
       imageEncoderSettings.setResolution(1600,1200);
       mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
       mCamera->setCaptureMode(QCamera::CaptureStillImage);
       mCamera->start();
       mCamera->searchAndLock();
       mCameraImageCapture->capture(filename);
       mCamera->unlock();
     });
//****************
//**************** Blanco ************
     Produits p;
     ui->ID_Produit->setValidator( new QIntValidator(0, 9999, this));

     ui->Type->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
     ui->Description->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));

     ui->tabprod->setModel(p.afficher());
 QSqlQuery queryt;
     queryt.prepare("SELECT id_produit FROM produits");
           queryt.exec();
           queryt.first();
            if(queryt.size()!=0)
            {
           int groupid_equipement = queryt.record().indexOf("id_produit");
    ui->id_immeublebox->addItem(queryt.value(0).toString());
 qDebug()<<queryt.value(0);
           while (queryt.next()) {

                 ui->id_immeublebox->addItem(queryt.value(groupid_equipement).toString());
                 qDebug()<< queryt.value(groupid_equipement).toString();
 }
 qDebug()<<queryt.value(groupid_equipement);
            }
 //******* STAT blanco ******
 QPieSeries *series = new QPieSeries();
 QSqlQueryModel* model;
 Produits prod;
 model=prod.statistiqueprod();
     QPieSlice *slice[10] ;
     if(model->rowCount()!=0)
     {
     for (int i=0;i<model->rowCount();i++) {
             series->append(model->record(i).value(0).toString()+" de type "+model->record(i).value(1).toString(),model->record(i).value(0).toInt());
             slice[i]= series->slices().at(i);
             slice[i]->setLabelVisible();
     }
     }
     slice[0]->setExploded();
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle(" Nombre de type / type :");
     QChartView *chartview = new QChartView(chart);
     chartview->setRenderHint(QPainter::Antialiasing);
     chartview->setParent(ui->statprod);

     //*************
}

void newWindow::update_labelrfid()
{
    data=ardrfid.read_from_arduinorfid();
    qDebug() << data;
    gestioncontrats gest;
    QSqlQueryModel* model=gest.rfidtest(data);
    if(model->rowCount()==1)
    {
        ui->rfidnom->setText(model->record(0).value(1).toString());
        ui->rfidprenom->setText(model->record(0).value(2).toString());
        ardrfid.write_to_arduinorfid("y");
    }
    else
    {
        ardrfid.write_to_arduinorfid("n");
    }
}

newWindow::~newWindow()
{
    delete ui;
}

void newWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->text()=="gestion des Clients")
    {
    ui->stackedWidget->setCurrentIndex(0);
    }
    else if(item->text()=="gestion des Employes")
    {
    ui->stackedWidget->setCurrentIndex(1);
    }
    else if(item->text()=="gestion des Agences")
    {
    ui->stackedWidget->setCurrentIndex(2);
    }
    else if(item->text()=="gestion des Produits")
    {
    ui->stackedWidget->setCurrentIndex(3);
    }
    else if(item->text()=="gestion des Contrats")
    {
    ui->stackedWidget->setCurrentIndex(4);
    }
}

//*********** Amir gestion contrat ***********

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
    QString imageqr="C:/Users/amirb/Desktop/project/HomePad/qrcodes/qrcode_"+numcontratstring+".png";
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
    QFile file("C:/Users/amirb/Desktop/project/HomePad/contrats/Contrat_"+ui->comboBoxnumcontrat->currentText()+".pdf");
    QFile file1("C:/Users/amirb/Desktop/project/HomePad/qrcodes/qrcode_"+ui->comboBoxnumcontrat->currentText()+".png");
    file1.remove();
    QString mailtext="Bonjour!\nVotre contrat numero "+ui->comboBoxnumcontrat->currentText()+" a ete supprimer \npour nous contacter utiliser ce mail: homepadinfo@gmail.com\nou bien sur ce numero telephone: 90322256";
    QString subject="Suppression du contrat numero "+ui->comboBoxnumcontrat->currentText();
    cont.envoiemail(mailtext,subject,ui->comboBoxnumcontrat->currentText());
    file.remove();
    bool test=cont.supprimer(numcontrat);
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
    QSqlQueryModel* model=cont.specificclient(ui->comboBoxidclientcontrat->currentText());
    QString contents = QString::fromUtf8(file.readAll());
    ui->textEditcontenucontrat->insertPlainText(contents);
    QTextCursor position(ui->textEditcontenucontrat->document());
    position.setPosition(81);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+ui->comboBoxidclientcontrat->currentText());
    position.setPosition(51);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(1).toString()+" "+model->record(0).value(2).toString());
    ui->textEditcontenucontrat->append(ui->dateEditcontrat->text());
    }
    else{
        ui->textEditcontenucontrat->clear();
        QFile file("C:/Users/amirb/Desktop/project/HomePad/contratachat.txt");
        file.open(QFile::ReadOnly);
        QTextStream in(&file);
        QSqlQueryModel* model=cont.specificclient(ui->comboBoxidclientcontrat->currentText());
        QString contents = QString::fromUtf8(file.readAll());
        ui->textEditcontenucontrat->insertPlainText(contents);
        QTextCursor position(ui->textEditcontenucontrat->document());
        position.setPosition(81);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+ui->comboBoxidclientcontrat->currentText());
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
    QSqlQueryModel* model=cont.specificclient(ui->comboBoxidclientcontrat->currentText());
    QString contents = QString::fromUtf8(file.readAll());
    ui->textEditcontenucontrat->insertPlainText(contents);
    QTextCursor position(ui->textEditcontenucontrat->document());
    position.setPosition(107);
    ui->textEditcontenucontrat->setTextCursor(position);
    ui->textEditcontenucontrat->insertPlainText(" "+ui->comboBoxidclientcontrat->currentText());
    position.setPosition(77);
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
        QSqlQueryModel* model=cont.specificclient(ui->comboBoxidclientcontrat->currentText());
        QString contents = QString::fromUtf8(file.readAll());
        ui->textEditcontenucontrat->insertPlainText(contents);
        QTextCursor position(ui->textEditcontenucontrat->document());
        position.setPosition(107);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+ui->comboBoxidclientcontrat->currentText());
        position.setPosition(77);
        ui->textEditcontenucontrat->setTextCursor(position);
        ui->textEditcontenucontrat->insertPlainText(" "+model->record(0).value(1).toString()+" "+model->record(0).value(2).toString());
        ui->textEditcontenucontrat->append(ui->dateEditcontrat->text());
    }
}

//***** eya gestion agence *****

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
    widget->idemploye=id_e;
    widget->show();
}

void newWindow::on_carteviste_clicked() //button pdf
{
    MainWindow m;
    QSqlQueryModel * model=G.rechercheemployea(m.loadID());
    QString numagence=model->record(0).value(7).toString();
    G.cartevisite(numagence);
}

//********************** khadija gestion employes***************//

void newWindow::update_label_kh()
{
    data=ardrfid.read_from_arduinorfid();
    qDebug() << data;


    if(data == "1")
    {
        popUp->setPopupText("client non satisfait !!!!");

        popUp->show();
        employees E;

        bool test2=E.ajouter_note();
    }
    if(data == "2")
    {
        popUp->setPopupText("client satisfait !!!!");

        popUp->show();
        employees E;

        bool test2=E.ajouter_note2();
    }

}

void newWindow::on_pushButton_ajouter_clicked()
{
    int ide=ui->lineEdit_ID->text().toInt();
    QString nome=ui->lineEdit_nom->text();
    QString prenome=ui->lineEdit_prenom->text();
    QString adressee=ui->lineEdit_adresse->text();
    QString numtel=ui->lineEdit_tel->text();
    QString emaile=ui->lineEdit_email->text();
    QString role=ui->lineEdit_role->text();
     int numagence=ui->lineEdit_agence->text().toInt();
     Historique h;
          h.save("nome:"+ui->lineEdit_nom->text(),"prenome :"+ui->lineEdit_prenom->text());
    employees E(ide,nome,prenome,adressee,numtel,emaile,role,numagence);

    bool test=E.ajouter();

    QString mdp=ui->ajoutmdp->text();
    QString nom=ui->ajoutnom->text();



    compte P(nom,mdp,ide);

    bool test1=P.ajouter();

    ui->tableView->setModel(Etmp.afficher());//MISE AJOUR
    ui->lineEdit_ID->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_tel->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_role->clear() ;
    ui->lineEdit_agence->clear() ;




    if(test && test1)
    {
        ui->comboBox->setModel(Etmp.comboBoxemployes());
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("ajout effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("ajout non effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void newWindow::on_pushButton_supprimer_clicked()
{
    Historique h;
         h.save2("ide"+ui->comboBox->currentText());
    int ide=ui->comboBox->currentText().toInt();
    QString idetest=ui->comboBox->currentText();

    if(idetest.isEmpty()){
        QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("Veuillez choisir un id  d'un employe à supprimer."),QMessageBox::Cancel);
    }
    else {

    bool test=Etmp.supprimer(ide);

    if(test) {
        //refresh
        ui->tableView->setModel(Etmp.afficher());
        ui->comboBox->setModel(Etmp.comboBoxemployes());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr(" suppression effectuer\n"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not Okay"), QObject::tr("suppression non effectuer\n"),QMessageBox::Cancel);

    }
}
}

void newWindow::on_tri_id_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Etmp.tri_ide());

}

void newWindow::on_tri_nom_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Etmp.tri_nom());

}

void newWindow::on_lineEdit_RECH_textEdited(const QString &arg1)
{
      ui->tableView->setModel(Etmp.recherche(ui->lineEdit_RECH->text()));
}

void newWindow::on_pushButton_modifier_clicked()
{

   QString ide=ui->comboBox_2->currentText();

    QString nome=ui->lineEdit_nom->text();
       QString prenome=ui->lineEdit_prenom->text();
       QString adressee=ui->lineEdit_adresse->text();
       QString numtel=ui->lineEdit_tel->text();
          QString emaile=ui->lineEdit_email->text();
         QString role=ui->lineEdit_role->text();
         int numagence=ui->lineEdit_agence->text().toInt();

         int idint=ide.toInt();
    bool test=Etmp.modifier(idint,nome,prenome,adressee,numtel,emaile,role,numagence);
    if(test)
    {
        //REFRESH
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        Historique h;
        h.save1(nome,prenome);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void newWindow::on_pushButton_historique_clicked()
{
    Historique h;
  h.load();
  h.load();
  QString link="C:/Users/amirb/Desktop/HomePad-Copie/hisclient.txt";
      QDesktopServices::openUrl(QUrl(link));
      qDebug() << QDesktopServices::openUrl(QUrl(link));
}

void newWindow::on_pushButton_afficher_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QString sql;
    sql="select IDE from EMPLOYES ";
QSqlDatabase db=QSqlDatabase::database("QODBC");
QSqlQuery *query=new QSqlQuery(db);
query->exec(sql);
model->setQuery(*query);
ui->comboBox_2->setModel(model);
}

void newWindow::on_pushButton_valider_clicked()
{
    QSqlQuery query;
    QString a,b,c,d,e,k,f,l;
            a=ui->comboBox_2->currentText();
            query.prepare("SELECT IDE,NOME,PRENOME,ADRESSEE,NUMTEL,EMAILE,ROLE,NUMAGENCE from employes where IDE=?  ");
             query.addBindValue(a);
            query.exec();
            while(query.next()){
             l=query.value(0).toString();
             a=query.value(1).toString();
             b=query.value(2).toString();
             c=query.value(3).toString();
             d=query.value(4).toString();
             e=query.value(5).toString();
             k=query.value(6).toString();
             f=query.value(7).toString();
            }
            ui->lineEdit_ID->setText(l);
            ui->lineEdit_nom->setText(a);
            ui->lineEdit_prenom->setText(b);
            ui->lineEdit_adresse->setText(c);
            ui->lineEdit_tel->setText(d);
            ui->lineEdit_email->setText(e);
            ui->lineEdit_role->setText(k);
            ui->lineEdit_agence->setText(f);

}

//*********** ameni gestion client********

void newWindow::on_pushButton_4_clicked()//ajout
{
    int cin=ui->cin->text().toInt();
    QString numtelcl=ui->numtelcl->text();

    QString nomcl=ui->nomcl->text();
    QString prenomcl=ui->prenomcl->text();

    QString emailcl(ui->emailcl->text());
    QString typecl(ui->typecl->currentText());
    qDebug() << ui->typecl->currentText();
Historique h;
     h.save4("nomcl:"+ui->nomcl->text(),"prenomcl :"+ui->prenomcl->text(),"numtelcl:"+ui->numtelcl->text());
     client c(cin,nomcl,prenomcl,emailcl,typecl,numtelcl);

bool test=c.ajouter();
ui->tableView_3->setModel(c.afficherclient());//MISE AJOUR
ui->cin->clear();
ui->nomcl->clear();
ui->prenomcl->clear();
ui->emailcl->clear();
ui->numtelcl->clear();

if(test)

        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("Ajout avec succes\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void newWindow::on_pushButton_6_clicked()//modifier
{
    int cin=ui->cin->text().toInt();
    QString nomcl = ui->nomcl->text();
    QString prenomcl = ui->prenomcl->text();
    QString typecl(ui->typecl->currentText());
    QString numtelcl = ui->numtelcl->text();

    bool test=cl->modifierj(ui->cin->text().toInt(),ui->nomcl->text(),ui->prenomcl->text(),ui->emailcl->text(),ui->typecl->currentText(),ui->numtelcl->text());
    Historique h;
         h.save3("nomcl:"+ui->nomcl->text(),"prenomcl :"+ui->prenomcl->text(),"numtelcl:"+ui->numtelcl->text());
    ui->tableView_3->setModel(cl->afficherclient());
    ui->cin->clear();
    ui->nomcl->clear();
    ui->prenomcl->clear();
    ui->emailcl->clear();
    ui->numtelcl->clear();
        if (test)
              {


                  QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("modification établie"),
                                       QMessageBox::Ok);}
              else{
              QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                      QObject::tr("modification non établie"),
                                      QMessageBox::Cancel);}
}

void newWindow::on_pushButton_17_clicked()//his
{
    Historique h;
  h.load2();
  h.load2();
  QString link="C:/Users/amirb/Desktop/HomePad-Copie/hisclient.txt";
      QDesktopServices::openUrl(QUrl(link));
}

void newWindow::on_pushButton_18_clicked()//pdf
{
    client c;
     c.genererPDF();
     QString link="C:/Users/amirb/Desktop/HomePad - Copie/liste.pdf";
         QDesktopServices::openUrl(QUrl("C:/Users/amirb/Desktop/HomePad-Copie/liste.pdf"));
}

void newWindow::on_pushButton_19_clicked()//imprimer
{

    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle("imprimer document");
    if(ui->tableView_3->hasMouseTracking())
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(dialog.exec() != QDialog::Accepted)
    { return;}

}

void newWindow::on_pushButton_20_clicked()//supp
{
    Historique h;
         h.save5("cin:"+ui->sup->text());
    client c1; c1.setcin(ui->sup->text().toInt());
    bool test=c1.supprimer(c1.getcin());
    ui->tableView_3->setModel(cl->afficherclient());

    ui->sup->clear();
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("suppression avec succes.");
    }
    else
          msgBox.setText("echec d'ajout");
                msgBox.exec();
}

void newWindow::on_lineEdit_5_textChanged(const QString &arg1)//recherche
{
    ui->tableView_3->setModel(cl->recherche(arg1));
}

void newWindow::on_comboBox_currentIndexChanged(int index)
{
     ui->tableView_3->setModel(cl->affichertrie(index));
}

//****************** blanco gestion produit ************

void newWindow::on_ajoutprod_clicked()
{
    int ID_PRODUIT=ui->ID_Produit->text().toInt();
    QString TYPE_Produit=ui->Type->text();
    QString ADRESSE=ui->Adresse->text();
    QString DESCRIPTION=ui->Description->text();
    QString IMAGE=ui->img2->text();
    if(ui->Type->text().isEmpty() and ui->Adresse->text().isEmpty() and ui->Description->text().isEmpty()){
        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("Il faut au moin un champ remplit \n"), QMessageBox::Cancel);

    }
    else{
    Produits p(ID_PRODUIT,TYPE_Produit,ADRESSE,DESCRIPTION,IMAGE);
    QMessageBox msg;
    bool test=p.ajout_pr();
    ui->tabprod->setModel(p.afficher());



    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                    QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

}
    else if(ui->ID_Produit->text().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }

}}

void newWindow::on_suppprod_clicked()
{
    Produits p1;
    p1.setID_PRODUIT(ui->id_immeublebox->currentText().toInt());
    bool test=p1.Supprimer(p1.getID_PRODUIT());
    ui->tabprod->setModel(p1.afficher());

    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
    else if(ui->id_immeublebox->currentText().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


}

void newWindow::on_Modifprod_clicked()
{
    Modifier m;

      m.setID_PRODUIT(ui->id_immeublebox->currentText().toInt());
      QSqlQuery qry;
      int ID_PRODUIT=ui->id_immeublebox->currentText().toInt();
        QString ID_AB_STRING= QString::number(ID_PRODUIT);
        qry.prepare("SELECT * from Produits where ID_PRODUIT='"+ID_AB_STRING+"'");
         if (qry.exec())
            {
             while (qry.next()) {
                QString TYPE_PRODUIT=qry.value(1).toString();
              m.setTYPE_PRODUIT(TYPE_PRODUIT);
              QString DESCRIPTION=qry.value(2).toString();
           m.setDESCRIPTION(DESCRIPTION);
           QString ADRESSE=qry.value(3).toString();
            m.setADRESSE(ADRESSE);
            QString IMAGE=qry.value(4).toString();
             m.setIMAGE(IMAGE);
              m.exec();
   }
   }
}

void newWindow::on_triprod_currentIndexChanged(int index)
{
    QString prod;
    Produits p1;
    if (index == 0)
    {
        ui->tabprod->setModel(p1.afficher());
    }
    else if (index == 1)
    {
        prod="ID_PRODUIT";
        ui->tabprod->setModel(p1.trier_produits(prod));
    }
    else if (index == 2)
    {
        prod="TYPE_PRODUIT";
        ui->tabprod->setModel(p1.trier_produits(prod));
    }
    else if (index == 3)
    {
        prod="IDE";
        ui->tabprod->setModel(p1.trier_produits(prod));
    }
}

void newWindow::on_pdfprod_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tabprod->model()->rowCount();
            const int columnCount = ui->tabprod->model()->columnCount();


            out <<  "<html>\n"
                        "<head>\n"

                     <<  QString("<title>%1</title>\n").arg("col1")
                      <<  "</head>\n"
                          "<center><h1>PRODUITS</h1></center>"

                          "  <h2>TABLE DES PRODUITS</h2>"
                          "<body   >\n"
                          "<table border=1 cellspacing=0 cellpadding=2 >\n";

            // headers
            out << "<thead><tr >";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabprod->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabprod->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tabprod->isColumnHidden(column)) {
                        QString data = ui->tabprod->model()->data(ui->tabprod->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";
            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }
}

void newWindow::on_inserimageprod_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images (*.png *.jpg *.jpeg"));
    if (QString::compare(filename,QString())!=0)
    {
      QImage label_image;
      bool valid =label_image.load(filename);
      if (valid)
      {   label_image= label_image.scaledToWidth(ui->img->width(),Qt::SmoothTransformation);
   ui->img->setPixmap(QPixmap::fromImage(label_image));
      }
      QSqlQuery query;
      query.prepare("INSERT INTO PRODUITS (IMAGE)"
                    "VALUES (:IMAGE)");
      query.bindValue(":IMAGE", filename);
ui->img2->setText(filename);
}
}

void newWindow::on_rechercheprod_cursorPositionChanged(int arg1, int arg2)
{
    Produits p1;
    ui->tabprod->setModel(p1.recherche_produits(ui->rechercheprod->text()));
}


