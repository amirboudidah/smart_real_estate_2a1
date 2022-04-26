#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QDoubleValidator>
#include "connection.h"
#include "employees.h"
#include <QMainWindow>
#include "historique.h"
#include "arduino.h"
#include <QDialog>
#include "popup.h"

namespace Ui {
class employes;
}

class employes : public QDialog
{
    Q_OBJECT

public:
    explicit employes(QWidget *parent = nullptr);
    ~employes();

private slots:

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_tri_id_clicked();

    void on_tri_nom_clicked();

    void on_lineEdit_RECH_textEdited(const QString &arg1);

    QSqlQueryModel *  comboBoxemployes();

    void on_pushButton_modifier_clicked();

    void on_pushButton_historique_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_activated(int index);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_id_line_returnPressed();

    void on_pushButton_afficher_clicked();

    void on_pushButton_valider_clicked();
    void update_label();

private:
    Ui::employes *ui;
    employees Etmp;
    QByteArray data;
    Arduino A;
    PopUp *popUp;
};

#endif // EMPLOYES_H
