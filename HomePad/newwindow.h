#ifndef NEWWINDOW_H
#define NEWWINDOW_H
#include "gestionagence.h"

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabBar>
#include <QTabWidget>
namespace Ui {
class newWindow;
}

class newWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();

private slots:
    void on_pushButton_2_clicked();




    void on_listWidget_itemClicked(QListWidgetItem *item);


    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_5_textEdited(const QString &str);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_lineEdit_27_textEdited(const QString &arg1);

    void on_lineEdit_26_textEdited(const QString &arg1);

private:
    Ui::newWindow *ui;
    GestionAgence G;
};

#endif // NEWWINDOW_H
