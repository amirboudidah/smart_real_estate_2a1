#include "employes.h"
#include "ui_employes.h"
#include "employees.h"
#include "connection.h"
#include "historique.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>
#include<QComboBox>
#include "compte.h"
#include <QVBoxLayout>
//#include <QScrollArea>
#include <QDebug>
#include <QTimer>
#include <QFileInfo>
#include <QSqlRecord>
#include "QFile"
#include "QTextStream"
#include <QAction>
#include <QFileDialog>


QTimer *timer2 = new QTimer();//refresh

QTimer *timer8 = new QTimer();

employes::employes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employes)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView_2->setModel(Etmp.afficher2());
    ui->lineEdit_ID->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_agence->setValidator(new QIntValidator(0,999,this));
    //ui->lineEdit_supp->setValidator(new QIntValidator(0,99999,this));
    /* hedhom el zouz te3 el modification
    ui->lineEdit->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_8->setValidator(new QIntValidator(0,999,this));
    */
    ui->comboBox->setModel(Etmp.comboBoxemployes());
    ui->comboBox_2->setModel(Etmp.comboBoxemployes());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
            break;
        }
            connect(timer8, SIGNAL(timeout()), this, SLOT(update_label()));

            timer8->start(100);

            popUp = new PopUp();
}

employes::~employes()
{
    delete ui;
}
void employes::update_label()
{
    data=A.read_from_arduino();
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


void employes::on_pushButton_ajouter_clicked()
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
void employes::on_pushButton_supprimer_clicked()
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

/*void employes::on_pushButton_supprimer_clicked()
{

    int ide=ui->comboBox->currentText().toInt();

    bool test=Etmp.supprimer(ide);
    ui->tableView->setModel(Etmp.afficher());
            ui->comboBox->setModel(Etmp.comboBoxemployes());

    if(test)
    {
         ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("suppression non effectuer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}*/







void employes::on_tri_id_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Etmp.tri_ide());

}

void employes::on_tri_nom_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Etmp.tri_nom());

}


void employes::on_lineEdit_RECH_textEdited(const QString &arg1)
{
      ui->tableView->setModel(Etmp.recherche(ui->lineEdit_RECH->text()));
}



void employes::on_pushButton_modifier_clicked()
{
    //récupération des informations saisies
   QString ide=ui->comboBox_2->currentText();
//    e.setId(ui->update_id->text().toInt())
    QString nome=ui->lineEdit_nom->text();
       QString prenome=ui->lineEdit_prenom->text();
       QString adressee=ui->lineEdit_adresse->text();
       QString numtel=ui->lineEdit_tel->text();
          QString emaile=ui->lineEdit_email->text();
         QString role=ui->lineEdit_role->text();
         int numagence=ui->lineEdit_agence->text().toInt();
                 //    e.setNom(ui->new_nom->text());
//    e.setPrenom(ui->new_prenom->text());
//    etudiant e(id,nom,prenom);
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

void employes::on_pushButton_historique_clicked()
{
    Historique h;
  h.load();
  h.load();
  QString link="C:/Users/kchaa/Desktop/qt real estate/khadija/his.txt";
      QDesktopServices::openUrl(QUrl(link));
}





void employes::on_pushButton_afficher_clicked()
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


void employes::on_pushButton_valider_clicked()
{
    QSqlQuery query;
    QString a,b,c,d,e,k,f,l;
            a=ui->comboBox_2->currentText();
           //qDebug()<<"a= "<<a;
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



           /* qDebug()<<"a= "<<a;
            qDebug()<<"b= "<<b;*/
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
