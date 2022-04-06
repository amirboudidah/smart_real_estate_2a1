/********************************************************************************
** Form generated from reading UI file 'newwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINDOW_H
#define UI_NEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_19;
    QWidget *page_2;
    QLabel *label_20;
    QWidget *page_3;
    QTabWidget *agencetabwidget;
    QWidget *ajoutagencetab;
    QGroupBox *ajoutmodiagence;
    QLabel *numagencelabel;
    QLabel *nomAlabel;
    QLabel *villeAlabel;
    QLabel *adresseAlabel;
    QLabel *numtelagencelabel;
    QLineEdit *numagence;
    QLineEdit *nomagence;
    QLineEdit *ville;
    QLineEdit *adresseagence;
    QLineEdit *numtelagence;
    QPushButton *ajouterA;
    QPushButton *modifierA;
    QWidget *afficheagencetab;
    QTableView *tableagence;
    QPushButton *supprimeragence;
    QPushButton *gomodiferA;
    QComboBox *comboBoxidagence;
    QComboBox *comboBoxtrieagence;
    QLabel *labelagencetrie;
    QPushButton *refreshA;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayoutrechercheA;
    QPushButton *iconrechercheagence;
    QLineEdit *rechercheragence;
    QLabel *estimationchiffre;
    QLabel *chiffredaffaire;
    QWidget *page_4;
    QLabel *label_22;
    QWidget *page_5;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_25;
    QWidget *tab_6;
    QLabel *label_9;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLabel *label_10;
    QLabel *label_11;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QDateEdit *dateEdit_3;
    QLabel *label_16;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QLabel *label_17;
    QTextEdit *textEdit_4;
    QLabel *label_18;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *chatbox;
    QPushButton *carteviste;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newWindow)
    {
        if (newWindow->objectName().isEmpty())
            newWindow->setObjectName(QStringLiteral("newWindow"));
        newWindow->resize(909, 520);
        newWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(newWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(179, 9, 731, 471));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_19 = new QLabel(page);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(110, 110, 56, 16));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_20 = new QLabel(page_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(400, 130, 56, 16));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        agencetabwidget = new QTabWidget(page_3);
        agencetabwidget->setObjectName(QStringLiteral("agencetabwidget"));
        agencetabwidget->setGeometry(QRect(0, 0, 871, 481));
        agencetabwidget->setMinimumSize(QSize(871, 0));
        agencetabwidget->setCursor(QCursor(Qt::ArrowCursor));
        ajoutagencetab = new QWidget();
        ajoutagencetab->setObjectName(QStringLiteral("ajoutagencetab"));
        ajoutmodiagence = new QGroupBox(ajoutagencetab);
        ajoutmodiagence->setObjectName(QStringLiteral("ajoutmodiagence"));
        ajoutmodiagence->setGeometry(QRect(90, -30, 531, 441));
        numagencelabel = new QLabel(ajoutmodiagence);
        numagencelabel->setObjectName(QStringLiteral("numagencelabel"));
        numagencelabel->setGeometry(QRect(60, 120, 131, 16));
        nomAlabel = new QLabel(ajoutmodiagence);
        nomAlabel->setObjectName(QStringLiteral("nomAlabel"));
        nomAlabel->setGeometry(QRect(60, 160, 121, 16));
        villeAlabel = new QLabel(ajoutmodiagence);
        villeAlabel->setObjectName(QStringLiteral("villeAlabel"));
        villeAlabel->setGeometry(QRect(60, 210, 81, 16));
        adresseAlabel = new QLabel(ajoutmodiagence);
        adresseAlabel->setObjectName(QStringLiteral("adresseAlabel"));
        adresseAlabel->setGeometry(QRect(60, 260, 81, 16));
        numtelagencelabel = new QLabel(ajoutmodiagence);
        numtelagencelabel->setObjectName(QStringLiteral("numtelagencelabel"));
        numtelagencelabel->setGeometry(QRect(60, 310, 71, 16));
        numagence = new QLineEdit(ajoutmodiagence);
        numagence->setObjectName(QStringLiteral("numagence"));
        numagence->setGeometry(QRect(260, 120, 113, 22));
        nomagence = new QLineEdit(ajoutmodiagence);
        nomagence->setObjectName(QStringLiteral("nomagence"));
        nomagence->setGeometry(QRect(260, 160, 113, 22));
        ville = new QLineEdit(ajoutmodiagence);
        ville->setObjectName(QStringLiteral("ville"));
        ville->setGeometry(QRect(260, 210, 113, 22));
        adresseagence = new QLineEdit(ajoutmodiagence);
        adresseagence->setObjectName(QStringLiteral("adresseagence"));
        adresseagence->setGeometry(QRect(260, 260, 113, 22));
        numtelagence = new QLineEdit(ajoutmodiagence);
        numtelagence->setObjectName(QStringLiteral("numtelagence"));
        numtelagence->setGeometry(QRect(260, 310, 113, 22));
        ajouterA = new QPushButton(ajoutmodiagence);
        ajouterA->setObjectName(QStringLiteral("ajouterA"));
        ajouterA->setGeometry(QRect(390, 380, 93, 28));
        modifierA = new QPushButton(ajoutmodiagence);
        modifierA->setObjectName(QStringLiteral("modifierA"));
        modifierA->setEnabled(false);
        modifierA->setGeometry(QRect(90, 380, 93, 28));
        agencetabwidget->addTab(ajoutagencetab, QString());
        afficheagencetab = new QWidget();
        afficheagencetab->setObjectName(QStringLiteral("afficheagencetab"));
        tableagence = new QTableView(afficheagencetab);
        tableagence->setObjectName(QStringLiteral("tableagence"));
        tableagence->setGeometry(QRect(0, 0, 721, 341));
        supprimeragence = new QPushButton(afficheagencetab);
        supprimeragence->setObjectName(QStringLiteral("supprimeragence"));
        supprimeragence->setGeometry(QRect(110, 400, 93, 28));
        gomodiferA = new QPushButton(afficheagencetab);
        gomodiferA->setObjectName(QStringLiteral("gomodiferA"));
        gomodiferA->setGeometry(QRect(110, 350, 93, 28));
        comboBoxidagence = new QComboBox(afficheagencetab);
        comboBoxidagence->setObjectName(QStringLiteral("comboBoxidagence"));
        comboBoxidagence->setGeometry(QRect(20, 380, 73, 22));
        comboBoxtrieagence = new QComboBox(afficheagencetab);
        comboBoxtrieagence->setObjectName(QStringLiteral("comboBoxtrieagence"));
        comboBoxtrieagence->setGeometry(QRect(540, 390, 131, 22));
        labelagencetrie = new QLabel(afficheagencetab);
        labelagencetrie->setObjectName(QStringLiteral("labelagencetrie"));
        labelagencetrie->setGeometry(QRect(470, 390, 56, 16));
        refreshA = new QPushButton(afficheagencetab);
        refreshA->setObjectName(QStringLiteral("refreshA"));
        refreshA->setGeometry(QRect(680, 390, 31, 21));
        QIcon icon;
        icon.addFile(QStringLiteral(":/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshA->setIcon(icon);
        refreshA->setIconSize(QSize(50, 50));
        layoutWidget = new QWidget(afficheagencetab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(464, 350, 251, 30));
        horizontalLayoutrechercheA = new QHBoxLayout(layoutWidget);
        horizontalLayoutrechercheA->setObjectName(QStringLiteral("horizontalLayoutrechercheA"));
        horizontalLayoutrechercheA->setContentsMargins(0, 0, 0, 0);
        iconrechercheagence = new QPushButton(layoutWidget);
        iconrechercheagence->setObjectName(QStringLiteral("iconrechercheagence"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        iconrechercheagence->setIcon(icon1);

        horizontalLayoutrechercheA->addWidget(iconrechercheagence);

        rechercheragence = new QLineEdit(layoutWidget);
        rechercheragence->setObjectName(QStringLiteral("rechercheragence"));

        horizontalLayoutrechercheA->addWidget(rechercheragence);

        estimationchiffre = new QLabel(afficheagencetab);
        estimationchiffre->setObjectName(QStringLiteral("estimationchiffre"));
        estimationchiffre->setGeometry(QRect(230, 380, 221, 20));
        chiffredaffaire = new QLabel(afficheagencetab);
        chiffredaffaire->setObjectName(QStringLiteral("chiffredaffaire"));
        chiffredaffaire->setGeometry(QRect(290, 360, 101, 16));
        agencetabwidget->addTab(afficheagencetab, QString());
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(350, 240, 56, 16));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 611, 678));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 771, 481));
        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(0, 20, 601, 111));
        lineEdit_9->setStyleSheet(QStringLiteral(""));
        pushButton_21 = new QPushButton(groupBox_3);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(500, 160, 93, 28));
        pushButton_21->setStyleSheet(QStringLiteral(""));
        pushButton_22 = new QPushButton(groupBox_3);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(390, 160, 93, 28));
        pushButton_22->setStyleSheet(QStringLiteral(""));
        pushButton_23 = new QPushButton(groupBox_3);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(390, 350, 93, 28));
        pushButton_23->setStyleSheet(QStringLiteral(""));
        pushButton_24 = new QPushButton(groupBox_3);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(500, 350, 93, 28));
        pushButton_24->setStyleSheet(QStringLiteral(""));
        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(0, 210, 601, 111));
        lineEdit_10->setStyleSheet(QStringLiteral(""));
        pushButton_25 = new QPushButton(groupBox_3);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(612, 0, 151, 28));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(25, 40, 101, 20));
        lineEdit_11 = new QLineEdit(tab_6);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(140, 40, 113, 22));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy);
        lineEdit_11->setStyleSheet(QStringLiteral(""));
        lineEdit_12 = new QLineEdit(tab_6);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(140, 70, 113, 22));
        lineEdit_12->setStyleSheet(QStringLiteral(""));
        label_10 = new QLabel(tab_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(25, 70, 101, 20));
        label_11 = new QLabel(tab_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 100, 131, 20));
        radioButton_5 = new QRadioButton(tab_6);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(60, 140, 97, 20));
        radioButton_6 = new QRadioButton(tab_6);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(60, 170, 97, 20));
        dateEdit_3 = new QDateEdit(tab_6);
        dateEdit_3->setObjectName(QStringLiteral("dateEdit_3"));
        dateEdit_3->setGeometry(QRect(150, 200, 110, 22));
        dateEdit_3->setStyleSheet(QStringLiteral(""));
        label_16 = new QLabel(tab_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 200, 101, 20));
        pushButton_26 = new QPushButton(tab_6);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setGeometry(QRect(30, 250, 111, 28));
        pushButton_26->setStyleSheet(QStringLiteral(""));
        pushButton_27 = new QPushButton(tab_6);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(200, 400, 93, 28));
        pushButton_27->setStyleSheet(QStringLiteral(""));
        label_17 = new QLabel(tab_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(310, 30, 121, 16));
        textEdit_4 = new QTextEdit(tab_6);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(310, 60, 211, 151));
        textEdit_4->setAutoFillBackground(false);
        textEdit_4->setStyleSheet(QStringLiteral(""));
        textEdit_4->setFrameShadow(QFrame::Plain);
        label_18 = new QLabel(tab_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(330, 220, 121, 16));
        pushButton_28 = new QPushButton(tab_6);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(310, 250, 141, 28));
        pushButton_28->setStyleSheet(QStringLiteral(""));
        pushButton_29 = new QPushButton(tab_6);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setGeometry(QRect(290, 400, 151, 28));
        pushButton_29->setStyleSheet(QStringLiteral(""));
        pushButton_30 = new QPushButton(tab_6);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        pushButton_30->setGeometry(QRect(440, 400, 151, 28));
        pushButton_30->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab_6, QString());
        stackedWidget->addWidget(page_5);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 181, 341));
        listWidget->setStyleSheet(QStringLiteral(""));
        listWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setTextElideMode(Qt::ElideLeft);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 340, 181, 171));
        groupBox->setStyleSheet(QStringLiteral(""));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 91, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 51, 51));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/blankprofile.png")));
        label_2->setScaledContents(true);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 90, 93, 28));
        chatbox = new QPushButton(centralwidget);
        chatbox->setObjectName(QStringLiteral("chatbox"));
        chatbox->setGeometry(QRect(740, 0, 93, 28));
        carteviste = new QPushButton(centralwidget);
        carteviste->setObjectName(QStringLiteral("carteviste"));
        carteviste->setGeometry(QRect(592, 0, 141, 28));
        newWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(newWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 909, 26));
        newWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(newWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        newWindow->setStatusBar(statusbar);

        retranslateUi(newWindow);

        stackedWidget->setCurrentIndex(2);
        agencetabwidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(newWindow);
    } // setupUi

    void retranslateUi(QMainWindow *newWindow)
    {
        newWindow->setWindowTitle(QApplication::translate("newWindow", "HomePad-Contrats", Q_NULLPTR));
        label_19->setText(QApplication::translate("newWindow", "page1", Q_NULLPTR));
        label_20->setText(QApplication::translate("newWindow", "page2", Q_NULLPTR));
        ajoutmodiagence->setTitle(QString());
        numagencelabel->setText(QApplication::translate("newWindow", "Numero de l'agence:", Q_NULLPTR));
        nomAlabel->setText(QApplication::translate("newWindow", "Nom de l'agence:", Q_NULLPTR));
        villeAlabel->setText(QApplication::translate("newWindow", "Ville:", Q_NULLPTR));
        adresseAlabel->setText(QApplication::translate("newWindow", "Adresse:", Q_NULLPTR));
        numtelagencelabel->setText(QApplication::translate("newWindow", "Num tel:", Q_NULLPTR));
        ajouterA->setText(QApplication::translate("newWindow", "Ajouter", Q_NULLPTR));
        modifierA->setText(QApplication::translate("newWindow", "Modifier", Q_NULLPTR));
        agencetabwidget->setTabText(agencetabwidget->indexOf(ajoutagencetab), QApplication::translate("newWindow", "Ajouter", Q_NULLPTR));
        supprimeragence->setText(QApplication::translate("newWindow", "Supprimer", Q_NULLPTR));
        gomodiferA->setText(QApplication::translate("newWindow", "Modifier", Q_NULLPTR));
        comboBoxtrieagence->clear();
        comboBoxtrieagence->insertItems(0, QStringList()
         << QApplication::translate("newWindow", "Par defaut", Q_NULLPTR)
         << QApplication::translate("newWindow", "Numero Agence", Q_NULLPTR)
         << QApplication::translate("newWindow", "Nom Agence", Q_NULLPTR)
         << QApplication::translate("newWindow", "Ville", Q_NULLPTR)
        );
        labelagencetrie->setText(QApplication::translate("newWindow", "trier par:", Q_NULLPTR));
        refreshA->setText(QString());
        iconrechercheagence->setText(QString());
        rechercheragence->setPlaceholderText(QApplication::translate("newWindow", "recherche...", Q_NULLPTR));
        estimationchiffre->setText(QString());
        chiffredaffaire->setText(QApplication::translate("newWindow", "chiffre d'affaire :", Q_NULLPTR));
        agencetabwidget->setTabText(agencetabwidget->indexOf(afficheagencetab), QApplication::translate("newWindow", "Affichage", Q_NULLPTR));
        label_22->setText(QApplication::translate("newWindow", "page4", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("newWindow", "Les Contrats:", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("newWindow", "Voir le reste", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("newWindow", "exporter", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("newWindow", "exporter", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("newWindow", "Voir le reste", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("newWindow", "scanner le QR code", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("newWindow", "afficher", Q_NULLPTR));
        label_9->setText(QApplication::translate("newWindow", "nom du client", Q_NULLPTR));
        label_10->setText(QApplication::translate("newWindow", "Prenom du client", Q_NULLPTR));
        label_11->setText(QApplication::translate("newWindow", "Type du contrat:", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("newWindow", "Achat", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("newWindow", "Vendre", Q_NULLPTR));
        label_16->setText(QApplication::translate("newWindow", "Date :", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("newWindow", "QR Generateur", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("newWindow", "Valider", Q_NULLPTR));
        label_17->setText(QApplication::translate("newWindow", "Inserer le contenu", Q_NULLPTR));
        label_18->setText(QApplication::translate("newWindow", "OU", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("newWindow", "choisir une template", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("newWindow", "Modifier", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("newWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("newWindow", "inserer", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("newWindow", "USER", Q_NULLPTR));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("newWindow", "Deconnecter", Q_NULLPTR));
        chatbox->setText(QApplication::translate("newWindow", "chat", Q_NULLPTR));
        carteviste->setText(QApplication::translate("newWindow", "generer une cartevisite", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newWindow: public Ui_newWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINDOW_H
