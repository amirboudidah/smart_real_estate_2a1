#ifndef IMMOBILIER_H
#define IMMOBILIER_H

#include <QDialog>

namespace Ui {
class immobilier;

}

class immobilier : public QDialog
{
    Q_OBJECT

public:
    explicit immobilier(QWidget *parent = nullptr);
    ~immobilier();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::immobilier *ui;

};

#endif // IMMOBILIER_H
