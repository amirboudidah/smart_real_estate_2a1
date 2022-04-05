#include "immobilier.h"
#include "ui_immobilier.h"
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
immobilier::immobilier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::immobilier)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestion immobiliers");
    Produits p;
    ui->ID_Produit->setValidator( new QIntValidator(0, 9999, this));

    ui->Type->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));
    ui->Description->setValidator(new QRegExpValidator( QRegExp("([A-Za-z_][A-Za-z]+)"), this ));

    ui->tableView->setModel(p.afficher());
QSqlQuery queryt;
    queryt.prepare("SELECT id_produit FROM produits");
          queryt.exec();
          queryt.first();
          int groupid_equipement = queryt.record().indexOf("id_produit");
   ui->comboBox_3->addItem(queryt.value(0).toString());
qDebug()<<queryt.value(0);
          while (queryt.next()) {

                ui->comboBox_3->addItem(queryt.value(groupid_equipement).toString());
}
qDebug()<<queryt.value(groupid_equipement);
//******* STAT ******
QPieSeries *series = new QPieSeries();
QSqlQueryModel* model;
Produits prod;
model=prod.statistiqueprod();
    QPieSlice *slice[10] ;
    for (int i=0;i<model->rowCount();i++) {
            series->append(model->record(i).value(0).toString()+" de type "+model->record(i).value(1).toString(),model->record(i).value(0).toInt());
            slice[i]= series->slices().at(i);
            slice[i]->setLabelVisible();
    }
    slice[0]->setExploded();
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(" Nombre de type / type :");
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame);
    //*************
}

immobilier::~immobilier()
{
    delete ui;
}

void immobilier::on_pushButton_clicked()
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
    ui->tableView->setModel(p.afficher());



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

void immobilier::on_pushButton_8_clicked()
{
    Produits p1;
    p1.setID_PRODUIT(ui->comboBox_3->currentText().toInt());
    bool test=p1.Supprimer(p1.getID_PRODUIT());
    ui->tableView->setModel(p1.afficher());

    if(!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
    else if(ui->comboBox_3->currentText().isEmpty()){

        QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                    QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                    QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);


}

void immobilier::on_pushButton_6_clicked()
{
    Modifier m;

      m.setID_PRODUIT(ui->comboBox_3->currentText().toInt());
      QSqlQuery qry;
      int ID_PRODUIT=ui->comboBox_3->currentText().toInt();
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


void immobilier::on_comboBox_currentIndexChanged(int index)
{
    QString prod;
    Produits p1;
    if (index == 0)
    {
        ui->tableView->setModel(p1.afficher());
    }
    else if (index == 1)
    {
        prod="ID_PRODUIT";
        ui->tableView->setModel(p1.trier_produits(prod));
    }
    else if (index == 2)
    {
        prod="TYPE_PRODUIT";
        ui->tableView->setModel(p1.trier_produits(prod));
    }
    else if (index == 3)
    {
        prod="IDE";
        ui->tableView->setModel(p1.trier_produits(prod));
    }
}

void immobilier::on_pushButton_3_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


            const int rowCount = ui->tableView->model()->rowCount();
            const int columnCount = ui->tableView->model()->columnCount();


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
                    if (!ui->tableView->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView->isColumnHidden(column)) {
                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void immobilier::on_pushButton_2_clicked()
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


void immobilier::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    Produits p1;
    ui->tableView->setModel(p1.recherche_produits(ui->lineEdit->text()));
}
