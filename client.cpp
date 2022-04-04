#include "client.h"
#include<QString>
#include<QtSql/QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QtSql/QSqlQueryModel>
#include<QPdfWriter>
#include<QPainter>
#include<QMessageBox>
#include<QSystemTrayIcon>

//constructeur sans parametre
client::client()
{

    cin=0;
    nomcl=" ";
    prenomcl=" ";
    numtelcl="";
    typecl=" ";
    emailcl="";


}
//constructeur avec parametre
client::client(int cin,QString nomcl,QString prenomcl,QString emailcl,QString typecl,QString numtelcl)
{
    this->nomcl=nomcl;
    this->prenomcl=prenomcl;
    this->cin=cin;
    this->typecl=typecl;
    this->emailcl=emailcl;
    this->numtelcl=numtelcl;



}

//les getters
int client::getcin(){return cin;}
QString client::getnumtelcl(){return numtelcl;}
QString client::getemailcl(){return emailcl;}
QString client::gettypecl(){return typecl;}
QString client::getnomcl(){return nomcl;}
QString client::getprenomcl(){return prenomcl;}


//les setters

void client::setcin(int cin){this->cin=cin ;}
void client::setnumtelcl(QString numtelcl){this->numtelcl=numtelcl ;}
void client::settypecl(QString typecl){this->typecl=typecl ;}
void client::setemailcl(QString emailcl){this->emailcl=emailcl  ;}
void client::setnomcl(QString nomcl){this->nomcl=nomcl   ;}
void client::setprenomcl(QString prenomcl){this->prenomcl=prenomcl   ;}

bool client::ajouter()
{
    bool test=false;
    QSqlQuery query;

        QString CIN_string=QString::number(cin);

          query.prepare("INSERT INTO CLIENTS (cin,nomcl,prenomcl,emailcl,typecl,numtelcl) VALUES (:cin, :nomcl, :prenomcl , :emailcl  , :typecl , :numtelcl )");
          query.bindValue(":cin" , CIN_string);
          query.bindValue(":nomcl" , nomcl);
          query.bindValue(":prenomcl", prenomcl);
          query.bindValue(":emailcl" ,emailcl);
          query.bindValue(":type",typecl );
          query.bindValue(":numtelcl", numtelcl);

          query.exec();
    return test;
}


QSqlQueryModel * client ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomcl "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomcl "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("emailcl "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("typecl"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("numtelcl "));

        return model;
}

bool client::modifierj(int cin ,QString nomcl , QString prenomcl  ,QString emailcl,QString typecl ,QString numtelcl)
{
    QSqlQuery query;

    query.prepare("UPDATE CLIENTS SET NOMCL= :nomcl,PRENOMCL= :prenomcl, EMAILCL= :emailcl, TYPECL= :typecl , NUMTELCL= :numtelcl  where CIN= :cin ");
    query.bindValue(":cin", cin);
    query.bindValue(":nomcl",nomcl);
    query.bindValue(":prenomcl", prenomcl);
    query.bindValue(":emailcl",emailcl);
    query.bindValue(":typecl",typecl);
    query.bindValue(":numtelcl",numtelcl);

            return    query.exec();
}

bool client :: supprimer(int id)
{

    QSqlQuery query;
    query.prepare("DELETE from CLIENTS where cin = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
void  client::genererPDF(){
//QDateTime datecreation = date.currentDateTime();
              //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                     QPdfWriter pdf("C:/Users/user/Desktop/interfaceG_projet/liste.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"Liste Des clients");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                        // painter.drawText(1100,2000,afficheDC);
                         painter.drawRect(100,100,7300,2600);

                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"CIN");
                         painter.drawText(1300,3300,"nom");
                         painter.drawText(2100,3300,"prenom");
                         painter.drawText(3300,3300,"email");
                         painter.drawText(4500,3300,"type");
                         painter.drawText(5300,3300,"num tel");

                         QSqlQuery query;
                         query.prepare("select * from CLIENTS");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2100,i,query.value(2).toString());
                             painter.drawText(3300,i,query.value(3).toString());
                             painter.drawText(4500,i,query.value(4).toString());
                             painter.drawText(5300,i,query.value(5).toString());


                            i = i + 500;
                         }


      int reponse = QMessageBox::Yes;
          if (reponse == QMessageBox::Yes)
          {
              QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
             notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION DES  CLIENTS ","Liste clients pret dans PDF",QSystemTrayIcon::Information,15000);

              painter.end();
          }
          if (reponse == QMessageBox::No)
          {
               painter.end();
          }
}

QSqlQueryModel * client::affichertrie(int index)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if (index==1)
    {
        model->setQuery("select * from CLIENTS order by CIN");
    }else if (index==2)
    {
        model->setQuery("select * from CLIENTS order by NOMCL");
    }else if(index==3)
    {
        model->setQuery("select * from CLIENTS order by PRENOMCL");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomcl "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomcl "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("emailcl "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("typecl"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("numtelcl "));
    return model;
}

QSqlQueryModel* client::recherche(QString id){
   QSqlQueryModel* model = new QSqlQueryModel();
   QString search = "%"+id+"%";
    model->setQuery("SELECT * FROM clients WHERE cin like '"+search+"'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomcl "));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomcl "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("emailcl "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("typecl"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("numtelcl "));
    return model ;
}
