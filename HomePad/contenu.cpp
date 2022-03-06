#include "contenu.h"
#include "ui_contenu.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QtDebug>
#include <QModelIndex>

contenu::contenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contenu)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
}

contenu::~contenu()
{
    delete ui;
}

void contenu::setconrat(gestioncontrats c)
{
    QString s = QString::number(c.getNumcontrat());

    QSqlQueryModel * model=c.testexist(s);
    ui->plainTextEdit->setPlainText(model->record(0).value(2).toString());

}

void contenu::on_pushButton_clicked()
{
    ui->plainTextEdit->zoomIn();
}

void contenu::on_pushButton_2_clicked()
{
    ui->plainTextEdit->zoomOut();
}

void contenu::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QString s=ui->lineEdit->text();
    ui->plainTextEdit->find(s);
}
