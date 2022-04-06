#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class QTcpSocket;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_envoyer_clicked();


    void on_fermerchat_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};
#endif // WIDGET_H
