/********************************************************************************
** Form generated from reading UI file 'logowanieh.ui'
**
** Created: Fri 28. May 13:37:41 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOWANIEH_H
#define UI_LOGOWANIEH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogowanieH
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *LogowanieH)
    {
        if (LogowanieH->objectName().isEmpty())
            LogowanieH->setObjectName(QString::fromUtf8("LogowanieH"));
        LogowanieH->setWindowModality(Qt::WindowModal);
        LogowanieH->resize(253, 295);
        groupBox = new QGroupBox(LogowanieH);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 221, 161));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 61, 16));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 28, 121, 22));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 60, 121, 20));
        lineEdit->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 41, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 110, 151, 23));

        retranslateUi(LogowanieH);

        QMetaObject::connectSlotsByName(LogowanieH);
    } // setupUi

    void retranslateUi(QWidget *LogowanieH)
    {
        LogowanieH->setWindowTitle(QApplication::translate("LogowanieH", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LogowanieH", "Logowanie do hurtowni", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LogowanieH", "Hurtownia:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LogowanieH", "wybierz", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("LogowanieH", "Has\305\202o:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LogowanieH", "Po\305\202\304\205cz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogowanieH: public Ui_LogowanieH {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOWANIEH_H
