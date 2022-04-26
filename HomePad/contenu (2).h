#ifndef CONTENU_H
#define CONTENU_H
#include "gestioncontrats.h"
#include <QDialog>

namespace Ui {
class contenu;
}

class contenu : public QDialog
{
    Q_OBJECT

public:
    explicit contenu(QWidget *parent = nullptr);
    void setconrat(gestioncontrats c);
    ~contenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::contenu *ui;

};

#endif // CONTENU_H
