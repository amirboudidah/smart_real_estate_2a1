#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDoubleValidator>
#include "connection.h"
#include "employees.h"
#include "employes.h"
#include <QMainWindow>
#include "popup.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int rech(QString,QString);

private slots :

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    employees Etmp;
    PopUp *popUp;

};

#endif // MAINWINDOW_H
