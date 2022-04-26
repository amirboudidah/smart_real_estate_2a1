#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>

namespace Ui {
class Modifier;
}

class Modifier : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier(QWidget *parent = nullptr);
    ~Modifier();
    void setID_PRODUIT(int);
    void setTYPE_PRODUIT( QString);
    void setADRESSE( QString);
    void setDESCRIPTION( QString);
    void setIMAGE( QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modifier *ui;
    int ID_PRODUIT;
    QString TYPE_PRODUIT,ADRESSE,DESCRIPTION,IMAGE;
};

#endif // MODIFIER_H
