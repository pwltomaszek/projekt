/********************************************************************************
** Form generated from reading UI file 'sprzedawca.ui'
**
** Created: Fri 21. May 12:21:15 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRZEDAWCA_H
#define UI_SPRZEDAWCA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sprzedawca
{
public:
    QTableView *widokTowary;
    QGroupBox *groupBox;
    QPushButton *buttonDodaj;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *labelNazwa;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelCena;
    QLabel *labelRazem;
    QLabel *labelCzyDostepny;
    QGroupBox *groupBox_2;
    QPushButton *buttonUsun;
    QPushButton *buttonCzysc;
    QPushButton *buttonGotowe;
    QTableView *widokWybraneTowary;
    QLabel *label;
    QLabel *labelRazemWybrane;
    QPushButton *pushButton;

    void setupUi(QWidget *Sprzedawca)
    {
        if (Sprzedawca->objectName().isEmpty())
            Sprzedawca->setObjectName(QString::fromUtf8("Sprzedawca"));
        Sprzedawca->resize(1004, 523);
        widokTowary = new QTableView(Sprzedawca);
        widokTowary->setObjectName(QString::fromUtf8("widokTowary"));
        widokTowary->setGeometry(QRect(0, 0, 601, 461));
        groupBox = new QGroupBox(Sprzedawca);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(630, 0, 371, 221));
        buttonDodaj = new QPushButton(groupBox);
        buttonDodaj->setObjectName(QString::fromUtf8("buttonDodaj"));
        buttonDodaj->setGeometry(QRect(290, 190, 75, 23));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 46, 13));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 170, 61, 16));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(100, 170, 42, 22));
        spinBox->setMinimum(1);
        labelNazwa = new QLabel(groupBox);
        labelNazwa->setObjectName(QString::fromUtf8("labelNazwa"));
        labelNazwa->setGeometry(QRect(20, 20, 221, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelNazwa->setFont(font);
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 70, 341, 71));
        plainTextEdit->setReadOnly(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 150, 46, 13));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 200, 46, 13));
        labelCena = new QLabel(groupBox);
        labelCena->setObjectName(QString::fromUtf8("labelCena"));
        labelCena->setGeometry(QRect(80, 150, 61, 16));
        labelRazem = new QLabel(groupBox);
        labelRazem->setObjectName(QString::fromUtf8("labelRazem"));
        labelRazem->setGeometry(QRect(80, 200, 61, 16));
        labelCzyDostepny = new QLabel(groupBox);
        labelCzyDostepny->setObjectName(QString::fromUtf8("labelCzyDostepny"));
        labelCzyDostepny->setGeometry(QRect(240, 170, 131, 20));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        labelCzyDostepny->setPalette(palette);
        labelCzyDostepny->setFont(font);
        labelCzyDostepny->setTextFormat(Qt::PlainText);
        labelCzyDostepny->setWordWrap(false);
        groupBox_2 = new QGroupBox(Sprzedawca);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(630, 240, 371, 221));
        buttonUsun = new QPushButton(groupBox_2);
        buttonUsun->setObjectName(QString::fromUtf8("buttonUsun"));
        buttonUsun->setGeometry(QRect(20, 190, 75, 23));
        buttonCzysc = new QPushButton(groupBox_2);
        buttonCzysc->setObjectName(QString::fromUtf8("buttonCzysc"));
        buttonCzysc->setGeometry(QRect(110, 190, 75, 23));
        buttonGotowe = new QPushButton(groupBox_2);
        buttonGotowe->setObjectName(QString::fromUtf8("buttonGotowe"));
        buttonGotowe->setGeometry(QRect(290, 190, 75, 23));
        widokWybraneTowary = new QTableView(groupBox_2);
        widokWybraneTowary->setObjectName(QString::fromUtf8("widokWybraneTowary"));
        widokWybraneTowary->setGeometry(QRect(20, 20, 341, 131));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 160, 46, 13));
        labelRazemWybrane = new QLabel(groupBox_2);
        labelRazemWybrane->setObjectName(QString::fromUtf8("labelRazemWybrane"));
        labelRazemWybrane->setGeometry(QRect(90, 160, 46, 13));
        pushButton = new QPushButton(Sprzedawca);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(920, 490, 75, 23));

        retranslateUi(Sprzedawca);

        QMetaObject::connectSlotsByName(Sprzedawca);
    } // setupUi

    void retranslateUi(QWidget *Sprzedawca)
    {
        Sprzedawca->setWindowTitle(QApplication::translate("Sprzedawca", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Sprzedawca", "Wybrany przedmiot:", 0, QApplication::UnicodeUTF8));
        buttonDodaj->setText(QApplication::translate("Sprzedawca", "Dodaj", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Sprzedawca", "Opis:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Sprzedawca", "ilo\305\233\304\207 sztuk:", 0, QApplication::UnicodeUTF8));
        labelNazwa->setText(QApplication::translate("Sprzedawca", "Logitech M305", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QString());
        label_5->setText(QApplication::translate("Sprzedawca", "Cena:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Sprzedawca", "Razem:", 0, QApplication::UnicodeUTF8));
        labelCena->setText(QString());
        labelRazem->setText(QString());
        labelCzyDostepny->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Sprzedawca", "Lista wybranych przedmiot\303\263w", 0, QApplication::UnicodeUTF8));
        buttonUsun->setText(QApplication::translate("Sprzedawca", "Usu\305\204", 0, QApplication::UnicodeUTF8));
        buttonCzysc->setText(QApplication::translate("Sprzedawca", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        buttonGotowe->setText(QApplication::translate("Sprzedawca", "Gotowe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Sprzedawca", "Razem:", 0, QApplication::UnicodeUTF8));
        labelRazemWybrane->setText(QApplication::translate("Sprzedawca", "0", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Sprzedawca", "test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sprzedawca: public Ui_Sprzedawca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRZEDAWCA_H
