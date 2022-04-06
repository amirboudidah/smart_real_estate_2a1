#ifndef NEWWINDOW_H
#define NEWWINDOW_H
#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabBar>
#include <QTabWidget>
#include "gestioncontrats.h"
#include "contenu.h"
namespace Ui {
class newWindow;
}

class newWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();

private slots:
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

private:
    Ui::newWindow *ui;
    gestioncontrats cont;
    contenu * content;

};

#endif // NEWWINDOW_H
