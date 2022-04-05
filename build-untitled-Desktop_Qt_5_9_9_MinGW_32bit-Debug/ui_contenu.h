/********************************************************************************
** Form generated from reading UI file 'contenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTENU_H
#define UI_CONTENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_contenu
{
public:
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *contenu)
    {
        if (contenu->objectName().isEmpty())
            contenu->setObjectName(QStringLiteral("contenu"));
        contenu->resize(788, 626);
        plainTextEdit = new QPlainTextEdit(contenu);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 0, 691, 621));
        pushButton = new QPushButton(contenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(720, 480, 51, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(30, 30));
        pushButton_2 = new QPushButton(contenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(720, 550, 51, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));
        lineEdit = new QLineEdit(contenu);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(708, 50, 71, 22));

        retranslateUi(contenu);

        QMetaObject::connectSlotsByName(contenu);
    } // setupUi

    void retranslateUi(QDialog *contenu)
    {
        contenu->setWindowTitle(QApplication::translate("contenu", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class contenu: public Ui_contenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTENU_H
