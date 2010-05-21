/********************************************************************************
** Form generated from reading UI file 'sklep.ui'
**
** Created: Fri 21. May 12:58:34 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKLEP_H
#define UI_SKLEP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sklep
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QComboBox *comboBox;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sklep)
    {
        if (Sklep->objectName().isEmpty())
            Sklep->setObjectName(QString::fromUtf8("Sklep"));
        Sklep->setWindowModality(Qt::NonModal);
        Sklep->setEnabled(true);
        Sklep->resize(253, 295);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sklep->sizePolicy().hasHeightForWidth());
        Sklep->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(Sklep);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 111, 22));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 30, 231, 161));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 200, 121, 21));
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit->setReadOnly(false);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 200, 61, 23));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 200, 46, 20));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        Sklep->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Sklep);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 253, 18));
        Sklep->setMenuBar(menuBar);
        statusBar = new QStatusBar(Sklep);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        Sklep->setStatusBar(statusBar);

        retranslateUi(Sklep);

        QMetaObject::connectSlotsByName(Sklep);
    } // setupUi

    void retranslateUi(QMainWindow *Sklep)
    {
        Sklep->setWindowTitle(QApplication::translate("Sklep", "Sklep", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Sklep", "wybierz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Sklep", "Kierownik", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Sklep", "Sprzedawca", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Sklep", "Magazynier", 0, QApplication::UnicodeUTF8)
        );
        lineEdit->setInputMask(QString());
        pushButton->setText(QApplication::translate("Sklep", "loguj", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Sklep", "has\305\202o:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sklep: public Ui_Sklep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKLEP_H
