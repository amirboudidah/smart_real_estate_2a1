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


    void on_comboBox_currentIndexChanged(int index);



    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::immobilier *ui;

};

#endif // IMMOBILIER_H
