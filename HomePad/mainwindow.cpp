#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "newwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    Dialog dialog;
//    dialog.setModal(true);
//    dialog.exec();
//    this->close();
    newwindow=new newWindow(this);
    newwindow->show();
    MainWindow::hide();
}
