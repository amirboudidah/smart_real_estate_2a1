/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QLineEdit *message;
    QPushButton *envoyer;
    QLabel *label_2;
    QPushButton *fermerchat;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(546, 352);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 331, 241));
        message = new QLineEdit(Widget);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(97, 273, 137, 22));
        envoyer = new QPushButton(Widget);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(240, 270, 93, 28));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(31, 270, 54, 16));
        fermerchat = new QPushButton(Widget);
        fermerchat->setObjectName(QStringLiteral("fermerchat"));
        fermerchat->setGeometry(QRect(440, 10, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        envoyer->setText(QApplication::translate("Widget", "envoyer", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Message:", Q_NULLPTR));
        fermerchat->setText(QApplication::translate("Widget", "fermer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
