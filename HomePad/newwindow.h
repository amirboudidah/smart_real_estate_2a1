#ifndef NEWWINDOW_H
#define NEWWINDOW_H
#include "modifiercontrat.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabBar>
#include <QTabWidget>
#include "gestioncontrats.h"
#include "contenu.h"
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

    void on_lineEdit_11_textEdited(const QString &arg1);

    void on_lineEdit_12_textEdited(const QString &arg1);

    void on_pushButton_29_clicked();

    void on_pushButton_19_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_28_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::newWindow *ui;
    gestioncontrats cont;
    modifiercontrat * mod;
    contenu * content;

};

#endif // NEWWINDOW_H
