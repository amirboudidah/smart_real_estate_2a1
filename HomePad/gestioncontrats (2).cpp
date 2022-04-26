#include "gestioncontrats.h"
#include <QDate>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QFile>
#include <iostream>
#include <fstream>
#include <vector>
#include <QFileDialog>
#include <QPixmap>
#include <QSvgRenderer>
#include "qrcode.h"
#include <QFileInfo>
#include "src/SmtpMime"


gestioncontrats::gestioncontrats(int numcontrat,int CIN,QString typec,QString contenu,QString imageqr,QString datec)
{
    this->numcontrat=numcontrat;
    this->CIN=CIN;
    this->typec=typec;
    this->contenu=contenu;
    this->imageqr=imageqr;
    this->datec=datec;
}

bool gestioncontrats::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(numcontrat);
    QString res1= QString::number(CIN);

    QDate da = QDate::fromString(datec,"dd/MM/yyyy");
    query.prepare("insert into contrats (numcontrat,CIN,typeC,contenu,imageqr,datec) values (:numcontrat,:CIN,:typec,:contenu,:imageqr,:datec)");

    query.bindValue(":numcontrat",res);
    query.bindValue(":CIN",res1);
    query.bindValue(":typec",typec);
    query.bindValue(":contenu",contenu);
    query.bindValue(":imageqr",imageqr);
    query.bindValue(":datec",da);

    return query.exec();
}

QSqlQueryModel * gestioncontrats::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from contrats");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numContrat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("imageqr"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN"));

    return model;
}

bool gestioncontrats::supprimer(int numcontrat)
{
    QSqlQuery query;
    QString res=QString::number(numcontrat);
    query.prepare("delete from contrats where numcontrat=:numcontrat");
    query.bindValue(":numcontrat",res);
    return query.exec();
}

bool gestioncontrats::Modifier(int numContrat,QString typec,QString contenu,QString imageqr,QString datec,int cin)
{
    QSqlQuery query;

    QDate da = QDate::fromString(datec,"dd/MM/yyyy");
    query.prepare("update contrats set CIN=:CIN,typec=:typec,contenu=:contenu,imageqr=:imageqr,datec=:datec where numcontrat=:numcontrat");

    query.bindValue(":numcontrat",numContrat);
    query.bindValue(":CIN",cin);
    query.bindValue(":typec",typec);
    query.bindValue(":contenu",contenu);
    query.bindValue(":imageqr",imageqr);
    query.bindValue(":datec",da);

    return query.exec();

}

QSqlQueryModel * gestioncontrats::recherche(QString  ch)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    model->setQuery("select * from contrats where lower(cast(numcontrat as varchar(20))) like lower(('"+ch+"%')) or lower(cast(CIN as varchar(20))) like lower(('"+ch+"%')) or lower(typec) like lower(('"+ch+"%'))");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numContrat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("imageqr"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN"));
    return model;
}

QSqlQueryModel * gestioncontrats::trier(QString type)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(type=="datec")
    {
        model->setQuery("select * from contrats order by "+type+" DESC");
    }
    else
    {
        model->setQuery("select * from contrats order by "+type);
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numContrat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("contenu"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("imageqr"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN"));

    return model;
}

QSqlQueryModel * gestioncontrats::comboboxcontrat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select numContrat from contrats");
    return model;
}

QSqlQueryModel * gestioncontrats::testexist(QString numcontrat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from contrats where cast(numcontrat as varchar(20))="+numcontrat);
    return model;
}

void gestioncontrats::writePdf(QString num)
{
gestioncontrats c;
QSqlQueryModel * model=c.testexist(num);
QString numcontrat=model->record(0).value(0).toString();
QString contenu = model->record(0).value(2).toString();
QString imageqr = "C:/Users/amirb/Desktop/HomePad-Copie/qrcodes/qrcode_"+numcontrat+".png";
QString filename1="C:/Users/amirb/Desktop/HomePad-Copie/Contrat_"+numcontrat+".docx";
QFile file( filename1 );
QTextStream stream( &file );
file.open(QIODevice::ReadWrite);
stream << contenu << endl;
QFile inputFile(filename1);
QString filename="C:/Users/amirb/Desktop/HomePad-Copie/contrats/Contrat_"+numcontrat+".pdf";
QPdfWriter pdfwriter(filename);
pdfwriter.setPageSize(QPageSize(QPageSize::A4));
QPainter painter(&pdfwriter);
QString pdfcontenu[1000];
int j=0;
int i=0;
QString line;
if (inputFile.open(QIODevice::ReadOnly))
{

   QTextStream in(&inputFile);
   while (!in.atEnd())
   {
       line = in.readLine();
      pdfcontenu[i]=line;
      painter.drawText(0,j,QString::fromUtf8(pdfcontenu[i].toUtf8().constData()));
      i=i+1;
      j=j+150;
   }
   inputFile.close();
}
QImage logo("C:/Users/amirb/Desktop/HomePad-Copie/logo.png");
painter.drawImage(7000,j+150,logo);
QImage image(imageqr);
painter.drawImage(4000,j+150,image);
painter.end();
file.remove();
}

void gestioncontrats::writeqrcode(QString code,QString id)
{
                   std::string str = code.toStdString();
                   const QrCode qr =QrCode::encodeText(str.c_str(), QrCode::Ecc::LOW);
                   QString file="C:/Users/amirb/Desktop/HomePad-Copie/qrcodes/qrcode_"+id+".svg";
                   std::ofstream myfile;
                   myfile.open(file.toStdString());
                   myfile << qr.toSvgString(1);
                   myfile.close();
                   QSvgRenderer svgRenderer(QString("C:/Users/amirb/Desktop/HomePad-Copie/qrcodes/qrcode_"+id+".svg"));
                   QPixmap pix( QSize(1000, 1000) );
                   QPainter pixPainter( &pix );
                   svgRenderer.render( &pixPainter );
                   // Load your SVG
                   QSvgRenderer renderer(QString("C:/Users/amirb/Desktop/HomePad-Copie/qrcodes/qrcode_"+id+".svg"));

                   // Prepare a QImage with desired characteritisc
                   QImage image(2000,2000, QImage::Format_ARGB32);
                   image.fill(0xaaA08080);  // partly transparent red-ish background

                   // Get QPainter that paints to the image
                   QPainter painter(&image);
                   renderer.render(&painter);
                   // Save, image format based on file extension
                   image.save("C:/Users/amirb/Desktop/HomePad-Copie/qrcodes/qrcode_"+id+".png");
                   QFile F(file);
                   F.remove();
}

void gestioncontrats::envoiemail(QString mail, QString subject,QString id)
{
        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
        gestioncontrats g;
        QSqlQueryModel *model=g.recherche(id);
        QSqlQueryModel *model1=g.specificclient(model->record(0).value(5).toString());
        smtp.setUser("homepadinfo@gmail.com");
        smtp.setPassword("25819166amir");
        MimeMessage message;
        message.setSender(new EmailAddress("homepadinfo@gmail.com", "HomePad"));
        message.addRecipient(new EmailAddress(model1->record(0).value(3).toString(), model1->record(0).value(1).toString()));
        message.setSubject(subject);
        MimeText text;
        text.setText(mail);
        message.addPart(&text);
        MimeAttachment document(new QFile("C:/Users/amirb/Desktop/HomePad-Copie/contrats/Contrat_"+id+".pdf"));
        message.addPart(&document);
        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();
}

QSqlQueryModel * gestioncontrats::employespourcontrat()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from clients");
    return model;
}

QSqlQueryModel * gestioncontrats::specificemploye(QString id)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employes where ide='"+id+"'");
    return model;
}

QSqlQueryModel * gestioncontrats::rfidtest(QString id)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employes where UID_RFID='"+id+"'");
    return model;
}

QSqlQueryModel * gestioncontrats::rfidsender(QString nom,QString prenom)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from employes where nome='"+nom+"' and nome='"+prenom+"'");
    return model;
}

QSqlQueryModel * gestioncontrats::specificclient(QString id)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from clients where cin="+id);
    return model;
}
