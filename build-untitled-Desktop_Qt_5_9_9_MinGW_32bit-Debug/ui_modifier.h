/********************************************************************************
** Form generated from reading UI file 'modifier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIER_H
#define UI_MODIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Modifier
{
public:
    QLineEdit *Image;
    QLabel *label_3;
    QLineEdit *Description;
    QLineEdit *ID_Produit;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *Adresse;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *Type;
    QPushButton *pushButton;

    void setupUi(QDialog *Modifier)
    {
        if (Modifier->objectName().isEmpty())
            Modifier->setObjectName(QStringLiteral("Modifier"));
        Modifier->resize(654, 374);
        Image = new QLineEdit(Modifier);
        Image->setObjectName(QStringLiteral("Image"));
        Image->setGeometry(QRect(140, 200, 113, 22));
        label_3 = new QLabel(Modifier);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(35, 100, 71, 20));
        Description = new QLineEdit(Modifier);
        Description->setObjectName(QStringLiteral("Description"));
        Description->setGeometry(QRect(140, 100, 113, 22));
        ID_Produit = new QLineEdit(Modifier);
        ID_Produit->setObjectName(QStringLiteral("ID_Produit"));
        ID_Produit->setEnabled(false);
        ID_Produit->setGeometry(QRect(140, 20, 113, 22));
        label_6 = new QLabel(Modifier);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 200, 61, 20));
        label = new QLabel(Modifier);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 20, 81, 20));
        Adresse = new QLineEdit(Modifier);
        Adresse->setObjectName(QStringLiteral("Adresse"));
        Adresse->setGeometry(QRect(140, 150, 113, 22));
        label_2 = new QLabel(Modifier);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 60, 56, 16));
        label_4 = new QLabel(Modifier);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(45, 150, 61, 20));
        Type = new QLineEdit(Modifier);
        Type->setObjectName(QStringLiteral("Type"));
        Type->setGeometry(QRect(140, 60, 113, 22));
        pushButton = new QPushButton(Modifier);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 130, 93, 28));

        retranslateUi(Modifier);

        QMetaObject::connectSlotsByName(Modifier);
    } // setupUi

    void retranslateUi(QDialog *Modifier)
    {
        Modifier->setWindowTitle(QApplication::translate("Modifier", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("Modifier", "Description", Q_NULLPTR));
        label_6->setText(QApplication::translate("Modifier", "Image", Q_NULLPTR));
        label->setText(QApplication::translate("Modifier", "ID Immeuble", Q_NULLPTR));
        label_2->setText(QApplication::translate("Modifier", "Type", Q_NULLPTR));
        label_4->setText(QApplication::translate("Modifier", "Adresse", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Modifier", "Modifier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Modifier: public Ui_Modifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_H
