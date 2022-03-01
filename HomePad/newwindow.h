#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabBar>
#include <QTabWidget>
#include "gestioncontrats.h"
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


    void on_pushButton_27_clicked();

    void on_pushButton_30_clicked();

    void on_lineEdit_10_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::newWindow *ui;
    gestioncontrats cont;
};

#endif // NEWWINDOW_H
