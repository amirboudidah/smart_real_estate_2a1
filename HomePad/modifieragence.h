#ifndef MODIFIERAGENCE_H
#define MODIFIERAGENCE_H
#include "gestionagence.h"

#include <QDialog>

namespace Ui {
class modifieragence;
}

class modifieragence : public QDialog
{
    Q_OBJECT

public:
    explicit modifieragence(QWidget *parent = nullptr);
    void setagence(GestionAgence G); //affichage ui de modif
    ~modifieragence();

private slots:
    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_lineEdit_26_textEdited(const QString &arg1);

    void on_lineEdit_27_textEdited(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::modifieragence *ui;
};

#endif // MODIFIERAGENCE_H
