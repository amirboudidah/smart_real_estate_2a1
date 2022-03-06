#ifndef MODIFIERCONTRAT_H
#define MODIFIERCONTRAT_H
#include "gestioncontrats.h"
#include <QDialog>

namespace Ui {
class modifiercontrat;
}

class modifiercontrat : public QDialog
{
    Q_OBJECT

public:
    explicit modifiercontrat(QWidget *parent = nullptr);
    void setconrat(gestioncontrats c);
    ~modifiercontrat();

private slots:
    void on_pushButton_27_clicked();
    void on_lineEdit_11_textEdited(const QString &str);
    void on_lineEdit_12_textEdited(const QString &str);

private:
    Ui::modifiercontrat *ui;
};

#endif // MODIFIERCONTRAT_H
