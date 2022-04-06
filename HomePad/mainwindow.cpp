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
    newwindow=new newWindow(this);
    newwindow->show();
    MainWindow::hide();
}
