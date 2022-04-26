#ifndef NEWWINDOW_H
#define NEWWINDOW_H
#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabBar>
#include <QTabWidget>
#include "gestioncontrats.h"
#include "contenu.h"
#include "gestionagence.h"
#include <QTcpSocket>
#include <QTextStream>
#include "chatbox.h"
#include "employees.h"
#include "historique.h"
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include "popup.h"
#include "arduino.h"
#include "arduinorfid.h"
#include "client.h"
namespace Ui {

class newWindow;
}

class QCamera ;

class QCameraViewfinder;

class QCameraImageCapture;

class QVBoxLayout;

class QMenu;

class QAction;

class newWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();
    QString hostname() const;
    quint16 port() const;
    client *cl;
    QCamera *mCamera ;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mCamMenu;
    QAction *mAllumerAction;
    QAction *mEteindreAction;
    QAction *mCapturerAction;

private slots:
    void update_labelrfid();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButtonajoutcontrat_clicked();

    void on_supprimercontrat_clicked();

    void on_numcontrat_textEdited(const QString &arg1);

    void on_gomodifiercontrat_clicked();

    void on_buttonrefreshcontrat_clicked();

    void on_triercontrat_currentIndexChanged(int index);

    void on_pushButtonchoisirtemplatecontrat_clicked();

    void on_voirlerestecontrat_clicked();

    void on_exportercontrat_clicked();

    void on_recherchecontrat_textEdited(const QString &arg1);

    void on_pushButtonmodifiercontrat_clicked();

    void on_radioButtonachatcontrat_clicked();

    void on_radioButtoncontratvendre_clicked();

    void on_buttonanulcontrat_clicked();
//*** eya/agence ***
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
//******************
 //*********employes khadija********//
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_tri_id_clicked();

    void on_tri_nom_clicked();

    void on_lineEdit_RECH_textEdited(const QString &arg1);

    void on_pushButton_modifier_clicked();

    void on_pushButton_historique_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_valider_clicked();

    void update_label_kh();

//********ameni gestion client********
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

//********Blanco gestion imm********
    void on_ajoutprod_clicked();

    void on_suppprod_clicked();

    void on_Modifprod_clicked();

    void on_triprod_currentIndexChanged(int index);

    void on_pdfprod_clicked();

    void on_inserimageprod_clicked();

    void on_rechercheprod_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::newWindow *ui;
    gestioncontrats cont;
    contenu * content;
    Arduinorfid ardrfid;
    QByteArray data;
//*** eya/agence ***
    QString mHostname="localhost";
    quint16 mPort=3333;
    GestionAgence G;
    QTcpSocket *mSocket;
    Widget *widget;
//******************employes khadija**********//
    employees Etmp;
    Arduino A;
    PopUp *popUp;
    //******************ameni client

int id_emp;
QString id_e;
};

//*** eya/agence ***
inline QString newWindow::hostname() const
{
   return mHostname;
}

inline quint16 newWindow::port() const
{
   return mPort;
}
//******************

#endif // NEWWINDOW_H
