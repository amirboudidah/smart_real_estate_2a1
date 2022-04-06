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
#include "chatbox.h"
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
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_ajouterA_clicked();

    void on_supprimeragence_clicked();

    void on_gomodiferA_clicked();

    void on_numagence_textEdited(const QString &str);

    void on_nomagence_textEdited(const QString &arg1);

    void on_numtelagence_textEdited(const QString &arg1);

    void on_adresseagence_textEdited(const QString &arg1);

    void on_ville_textEdited(const QString &arg1);

    void on_refreshA_clicked();

    void on_rechercheragence_textEdited(const QString &arg1);

    void on_comboBoxtrieagence_currentIndexChanged(int index);

    void on_modifierA_clicked(); //modifier page ajouter

    void on_chatbox_clicked();

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
