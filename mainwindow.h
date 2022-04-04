#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QCamera ;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
//    void on_ajouter_clicked();

//    void on_supprimer_clicked();

//    void on_button_modifier_clicked();

    //void on_radioButton_clicked();

    //void on_radioButton_3_clicked();

    //void on_radioButton_2_clicked();

    //void on_l_r_returnPressed();

//    void on_l_r_textChanged(const QString &arg1);

  void on_pushButton_clicked();



//    void on_pushButton_2_clicked();

//    void on_listWidget_currentRowChanged(int currentRow);

   void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

 void on_pushButton_6_clicked();

 void on_pushButton_4_clicked();

 void on_pushButton_7_clicked();

 void on_comboBox_currentIndexChanged(int index);

 void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    client *c;
    QCamera *mCamera ;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mCamMenu;
    QAction *mAllumerAction;
    QAction *mEteindreAction;
    QAction *mCapturerAction;

};



#endif // MAINWINDOW_H
