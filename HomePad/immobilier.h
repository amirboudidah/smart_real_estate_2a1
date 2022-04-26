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
    void on_ajoutprod_clicked();


    void on_suppprod_clicked();

    void on_Modifprod_clicked();


    void on_triprod_currentIndexChanged(int index);



    void on_pdfprod_clicked();

    void on_inserimageprod_clicked();

    void on_rechercheprod_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::immobilier *ui;

};

#endif // IMMOBILIER_H
