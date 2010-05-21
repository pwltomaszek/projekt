/********************************************************************************
** Form generated from reading UI file 'finalizacja.ui'
**
** Created: Fri 21. May 12:21:15 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALIZACJA_H
#define UI_FINALIZACJA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finalizacja
{
public:
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QRadioButton *radioButtonParagon;
    QRadioButton *radioButtonFaktura;
    QGroupBox *groupBoxEdycja;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_55;
    QLabel *label_108;
    QLabel *label_109;
    QLabel *label_110;
    QLabel *label_111;
    QLabel *label_112;
    QLabel *label_113;
    QLabel *label_114;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_56;
    QLineEdit *lineEditRegon;
    QLineEdit *lineEditNazwa;
    QLineEdit *lineEditUlica;
    QLineEdit *lineEditMiejsc;
    QLineEdit *lineEditKod;
    QLineEdit *lineEditTelefon;
    QLineEdit *lineEditEmail;
    QPushButton *buttonAnulujEdycja;
    QPushButton *buttonZatwierdz;
    QPushButton *buttonCzysc;
    QGroupBox *groupBoxKlienci;
    QTableView *widokKlienci;
    QPushButton *buttonDodaj;
    QPushButton *buttonEdytuj;
    QPushButton *buttonWybierz;
    QPushButton *buttonRealizuj;
    QPushButton *buttonAnulujFinaliz;

    void setupUi(QDialog *Finalizacja)
    {
        if (Finalizacja->objectName().isEmpty())
            Finalizacja->setObjectName(QString::fromUtf8("Finalizacja"));
        Finalizacja->setWindowModality(Qt::ApplicationModal);
        Finalizacja->resize(771, 491);
        pushButton = new QPushButton(Finalizacja);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 460, 75, 23));
        groupBox = new QGroupBox(Finalizacja);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(430, 280, 271, 71));
        radioButtonParagon = new QRadioButton(groupBox);
        radioButtonParagon->setObjectName(QString::fromUtf8("radioButtonParagon"));
        radioButtonParagon->setGeometry(QRect(20, 20, 82, 17));
        radioButtonParagon->setChecked(true);
        radioButtonFaktura = new QRadioButton(groupBox);
        radioButtonFaktura->setObjectName(QString::fromUtf8("radioButtonFaktura"));
        radioButtonFaktura->setGeometry(QRect(20, 40, 82, 17));
        radioButtonFaktura->setChecked(false);
        groupBoxEdycja = new QGroupBox(Finalizacja);
        groupBoxEdycja->setObjectName(QString::fromUtf8("groupBoxEdycja"));
        groupBoxEdycja->setEnabled(true);
        groupBoxEdycja->setGeometry(QRect(430, 10, 271, 261));
        layoutWidget = new QWidget(groupBoxEdycja);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 65, 181));
        verticalLayout_55 = new QVBoxLayout(layoutWidget);
        verticalLayout_55->setObjectName(QString::fromUtf8("verticalLayout_55"));
        verticalLayout_55->setContentsMargins(0, 0, 0, 0);
        label_108 = new QLabel(layoutWidget);
        label_108->setObjectName(QString::fromUtf8("label_108"));

        verticalLayout_55->addWidget(label_108);

        label_109 = new QLabel(layoutWidget);
        label_109->setObjectName(QString::fromUtf8("label_109"));

        verticalLayout_55->addWidget(label_109);

        label_110 = new QLabel(layoutWidget);
        label_110->setObjectName(QString::fromUtf8("label_110"));

        verticalLayout_55->addWidget(label_110);

        label_111 = new QLabel(layoutWidget);
        label_111->setObjectName(QString::fromUtf8("label_111"));

        verticalLayout_55->addWidget(label_111);

        label_112 = new QLabel(layoutWidget);
        label_112->setObjectName(QString::fromUtf8("label_112"));

        verticalLayout_55->addWidget(label_112);

        label_113 = new QLabel(layoutWidget);
        label_113->setObjectName(QString::fromUtf8("label_113"));

        verticalLayout_55->addWidget(label_113);

        label_114 = new QLabel(layoutWidget);
        label_114->setObjectName(QString::fromUtf8("label_114"));

        verticalLayout_55->addWidget(label_114);

        layoutWidget_2 = new QWidget(groupBoxEdycja);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 30, 161, 178));
        verticalLayout_56 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_56->setObjectName(QString::fromUtf8("verticalLayout_56"));
        verticalLayout_56->setContentsMargins(0, 0, 0, 0);
        lineEditRegon = new QLineEdit(layoutWidget_2);
        lineEditRegon->setObjectName(QString::fromUtf8("lineEditRegon"));

        verticalLayout_56->addWidget(lineEditRegon);

        lineEditNazwa = new QLineEdit(layoutWidget_2);
        lineEditNazwa->setObjectName(QString::fromUtf8("lineEditNazwa"));

        verticalLayout_56->addWidget(lineEditNazwa);

        lineEditUlica = new QLineEdit(layoutWidget_2);
        lineEditUlica->setObjectName(QString::fromUtf8("lineEditUlica"));

        verticalLayout_56->addWidget(lineEditUlica);

        lineEditMiejsc = new QLineEdit(layoutWidget_2);
        lineEditMiejsc->setObjectName(QString::fromUtf8("lineEditMiejsc"));

        verticalLayout_56->addWidget(lineEditMiejsc);

        lineEditKod = new QLineEdit(layoutWidget_2);
        lineEditKod->setObjectName(QString::fromUtf8("lineEditKod"));

        verticalLayout_56->addWidget(lineEditKod);

        lineEditTelefon = new QLineEdit(layoutWidget_2);
        lineEditTelefon->setObjectName(QString::fromUtf8("lineEditTelefon"));

        verticalLayout_56->addWidget(lineEditTelefon);

        lineEditEmail = new QLineEdit(layoutWidget_2);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        verticalLayout_56->addWidget(lineEditEmail);

        buttonAnulujEdycja = new QPushButton(groupBoxEdycja);
        buttonAnulujEdycja->setObjectName(QString::fromUtf8("buttonAnulujEdycja"));
        buttonAnulujEdycja->setGeometry(QRect(100, 230, 75, 23));
        buttonZatwierdz = new QPushButton(groupBoxEdycja);
        buttonZatwierdz->setObjectName(QString::fromUtf8("buttonZatwierdz"));
        buttonZatwierdz->setGeometry(QRect(180, 230, 75, 23));
        buttonCzysc = new QPushButton(groupBoxEdycja);
        buttonCzysc->setObjectName(QString::fromUtf8("buttonCzysc"));
        buttonCzysc->setGeometry(QRect(20, 230, 75, 23));
        groupBoxKlienci = new QGroupBox(Finalizacja);
        groupBoxKlienci->setObjectName(QString::fromUtf8("groupBoxKlienci"));
        groupBoxKlienci->setGeometry(QRect(10, 10, 411, 341));
        widokKlienci = new QTableView(groupBoxKlienci);
        widokKlienci->setObjectName(QString::fromUtf8("widokKlienci"));
        widokKlienci->setGeometry(QRect(10, 30, 391, 211));
        buttonDodaj = new QPushButton(groupBoxKlienci);
        buttonDodaj->setObjectName(QString::fromUtf8("buttonDodaj"));
        buttonDodaj->setGeometry(QRect(10, 280, 75, 23));
        buttonEdytuj = new QPushButton(groupBoxKlienci);
        buttonEdytuj->setObjectName(QString::fromUtf8("buttonEdytuj"));
        buttonEdytuj->setGeometry(QRect(100, 280, 75, 23));
        buttonWybierz = new QPushButton(groupBoxKlienci);
        buttonWybierz->setObjectName(QString::fromUtf8("buttonWybierz"));
        buttonWybierz->setGeometry(QRect(320, 280, 75, 23));
        buttonRealizuj = new QPushButton(Finalizacja);
        buttonRealizuj->setObjectName(QString::fromUtf8("buttonRealizuj"));
        buttonRealizuj->setGeometry(QRect(690, 460, 75, 23));
        buttonAnulujFinaliz = new QPushButton(Finalizacja);
        buttonAnulujFinaliz->setObjectName(QString::fromUtf8("buttonAnulujFinaliz"));
        buttonAnulujFinaliz->setGeometry(QRect(610, 460, 75, 23));

        retranslateUi(Finalizacja);

        QMetaObject::connectSlotsByName(Finalizacja);
    } // setupUi

    void retranslateUi(QDialog *Finalizacja)
    {
        Finalizacja->setWindowTitle(QApplication::translate("Finalizacja", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Finalizacja", "PushButton", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Finalizacja", "potwierdzenie", 0, QApplication::UnicodeUTF8));
        radioButtonParagon->setText(QApplication::translate("Finalizacja", "paragon", 0, QApplication::UnicodeUTF8));
        radioButtonFaktura->setText(QApplication::translate("Finalizacja", "faktura", 0, QApplication::UnicodeUTF8));
        groupBoxEdycja->setTitle(QApplication::translate("Finalizacja", "Szczeg\303\263\305\202y", 0, QApplication::UnicodeUTF8));
        label_108->setText(QApplication::translate("Finalizacja", "regon", 0, QApplication::UnicodeUTF8));
        label_109->setText(QApplication::translate("Finalizacja", "nazwa", 0, QApplication::UnicodeUTF8));
        label_110->setText(QApplication::translate("Finalizacja", "ulica", 0, QApplication::UnicodeUTF8));
        label_111->setText(QApplication::translate("Finalizacja", "miejscowosc", 0, QApplication::UnicodeUTF8));
        label_112->setText(QApplication::translate("Finalizacja", "kodPocztowy", 0, QApplication::UnicodeUTF8));
        label_113->setText(QApplication::translate("Finalizacja", "telefon", 0, QApplication::UnicodeUTF8));
        label_114->setText(QApplication::translate("Finalizacja", "email", 0, QApplication::UnicodeUTF8));
        buttonAnulujEdycja->setText(QApplication::translate("Finalizacja", "Anuluj", 0, QApplication::UnicodeUTF8));
        buttonZatwierdz->setText(QApplication::translate("Finalizacja", "Zatwierd\305\272", 0, QApplication::UnicodeUTF8));
        buttonCzysc->setText(QApplication::translate("Finalizacja", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        groupBoxKlienci->setTitle(QApplication::translate("Finalizacja", "Lista klient\303\263w", 0, QApplication::UnicodeUTF8));
        buttonDodaj->setText(QApplication::translate("Finalizacja", "Dodaj", 0, QApplication::UnicodeUTF8));
        buttonEdytuj->setText(QApplication::translate("Finalizacja", "Edytuj", 0, QApplication::UnicodeUTF8));
        buttonWybierz->setText(QApplication::translate("Finalizacja", "Wybierz", 0, QApplication::UnicodeUTF8));
        buttonRealizuj->setText(QApplication::translate("Finalizacja", "Realizuj", 0, QApplication::UnicodeUTF8));
        buttonAnulujFinaliz->setText(QApplication::translate("Finalizacja", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Finalizacja: public Ui_Finalizacja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALIZACJA_H
