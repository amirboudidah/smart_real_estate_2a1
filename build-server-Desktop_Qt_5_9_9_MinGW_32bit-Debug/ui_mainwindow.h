/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionhgvsqdf;
    QAction *actionfqsdjfq;
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionhgvsqdf = new QAction(MainWindow);
        actionhgvsqdf->setObjectName(QStringLiteral("actionhgvsqdf"));
        actionfqsdjfq = new QAction(MainWindow);
        actionfqsdjfq->setObjectName(QStringLiteral("actionfqsdjfq"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 230, 261, 81));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("font: 30pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 40, 181, 181));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/logo.ico);"));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../2.1.png")));
        label_3->setScaledContents(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(560, 190, 201, 35));
        lineEdit->setStyleSheet(QStringLiteral("border-radius: 10px;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 320, 93, 28));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(560, 250, 201, 35));
        lineEdit_2->setStyleSheet(QStringLiteral("border-radius: 10px;"));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 511, 591));
        label->setPixmap(QPixmap(QString::fromUtf8(":/buildings.jpg")));
        label->setScaledContents(false);
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        label_4->raise();
        label_3->raise();
        lineEdit->raise();
        pushButton->raise();
        lineEdit_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HomePad", Q_NULLPTR));
        actionhgvsqdf->setText(QApplication::translate("MainWindow", "hgvsqdf", Q_NULLPTR));
        actionfqsdjfq->setText(QApplication::translate("MainWindow", "fqsdjfq", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "HomePad", Q_NULLPTR));
        label_3->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Nom d'utilisateur", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Connecter", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
