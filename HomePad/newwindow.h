#ifndef NEWWINDOW_H
#define NEWWINDOW_H
#include "gestionagence.h"
#include "modifieragence.h"
#include <QTcpSocket>
#include <QTextStream>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabBar>
#include <QTabWidget>
#include "widget.h"
namespace Ui {
class newWindow;
}

class newWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();
    QString hostname() const;
    quint16 port() const;

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

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_carteviste_clicked();

private:
    Ui::newWindow *ui;
    QString mHostname="localhost";
    quint16 mPort=3333;
    GestionAgence G;
    modifieragence *M;
    QTcpSocket *mSocket;
    Widget *widget;
};

inline QString newWindow::hostname() const
{
   return mHostname;
}
inline quint16 newWindow::port() const
{
   return mPort;
}

#endif // NEWWINDOW_H
