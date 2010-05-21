/********************************************************************************
** Form generated from reading UI file 'kierownik.ui'
**
** Created: Fri 21. May 12:21:15 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KIEROWNIK_H
#define UI_KIEROWNIK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Kierownik
{
public:
    QRadioButton *radioButton;

    void setupUi(QWidget *Kierownik)
    {
        if (Kierownik->objectName().isEmpty())
            Kierownik->setObjectName(QString::fromUtf8("Kierownik"));
        Kierownik->resize(400, 300);
        radioButton = new QRadioButton(Kierownik);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(40, 40, 82, 17));

        retranslateUi(Kierownik);

        QMetaObject::connectSlotsByName(Kierownik);
    } // setupUi

    void retranslateUi(QWidget *Kierownik)
    {
        Kierownik->setWindowTitle(QApplication::translate("Kierownik", "Form", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Kierownik", "dla testu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Kierownik: public Ui_Kierownik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KIEROWNIK_H
