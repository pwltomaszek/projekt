/********************************************************************************
** Form generated from reading UI file 'magazynier.ui'
**
** Created: Fri 28. May 13:37:42 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGAZYNIER_H
#define UI_MAGAZYNIER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magazynier
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QPushButton *buttonDodaj;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox;
    QLabel *labelNazwa;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *labelCena;
    QLabel *labelRazem;
    QLabel *labelCzyDostepny;
    QGroupBox *groupBox_4;
    QPushButton *buttonUsun_2;
    QPushButton *buttonCzysc_2;
    QTableView *widokWybraneTowary_2;
    QGroupBox *groupBox;
    QTableView *tableView;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QGroupBox *groupBox_10;
    QPushButton *pushButton;
    QLabel *label_9;
    QLineEdit *labelRazemWybrane_2;
    QLabel *label_2;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QTableView *tableView_2;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QLabel *label_14;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_6;
    QTableView *tableView_3;
    QGroupBox *groupBox_9;
    QLabel *label;
    QWidget *tab_3;
    QGroupBox *groupBox_7;
    QTableView *tableView_4;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QPushButton *pushButton_4;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_11;

    void setupUi(QDialog *Magazynier)
    {
        if (Magazynier->objectName().isEmpty())
            Magazynier->setObjectName(QString::fromUtf8("Magazynier"));
        Magazynier->resize(830, 650);
        Magazynier->setModal(false);
        tabWidget = new QTabWidget(Magazynier);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, 10, 811, 631));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(560, 50, 241, 291));
        buttonDodaj = new QPushButton(groupBox_3);
        buttonDodaj->setObjectName(QString::fromUtf8("buttonDodaj"));
        buttonDodaj->setGeometry(QRect(160, 260, 75, 23));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 46, 13));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 210, 61, 16));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(90, 210, 42, 22));
        spinBox->setMinimum(1);
        labelNazwa = new QLabel(groupBox_3);
        labelNazwa->setObjectName(QString::fromUtf8("labelNazwa"));
        labelNazwa->setGeometry(QRect(10, 20, 221, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelNazwa->setFont(font);
        plainTextEdit = new QPlainTextEdit(groupBox_3);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 70, 221, 101));
        plainTextEdit->setReadOnly(true);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 190, 46, 13));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 240, 51, 16));
        labelCena = new QLabel(groupBox_3);
        labelCena->setObjectName(QString::fromUtf8("labelCena"));
        labelCena->setGeometry(QRect(70, 190, 61, 16));
        labelRazem = new QLabel(groupBox_3);
        labelRazem->setObjectName(QString::fromUtf8("labelRazem"));
        labelRazem->setGeometry(QRect(70, 240, 61, 16));
        labelCzyDostepny = new QLabel(groupBox_3);
        labelCzyDostepny->setObjectName(QString::fromUtf8("labelCzyDostepny"));
        labelCzyDostepny->setGeometry(QRect(140, 210, 101, 20));
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
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(9, 350, 541, 251));
        buttonUsun_2 = new QPushButton(groupBox_4);
        buttonUsun_2->setObjectName(QString::fromUtf8("buttonUsun_2"));
        buttonUsun_2->setGeometry(QRect(360, 220, 75, 23));
        buttonCzysc_2 = new QPushButton(groupBox_4);
        buttonCzysc_2->setObjectName(QString::fromUtf8("buttonCzysc_2"));
        buttonCzysc_2->setGeometry(QRect(450, 220, 75, 23));
        widokWybraneTowary_2 = new QTableView(groupBox_4);
        widokWybraneTowary_2->setObjectName(QString::fromUtf8("widokWybraneTowary_2"));
        widokWybraneTowary_2->setGeometry(QRect(10, 20, 520, 191));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 541, 331));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 20, 520, 300));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(610, 20, 61, 20));
        lineEdit_2->setReadOnly(true);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(560, 20, 46, 13));
        groupBox_10 = new QGroupBox(tab);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(560, 350, 241, 251));
        pushButton = new QPushButton(groupBox_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 210, 130, 23));
        label_9 = new QLabel(groupBox_10);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 160, 111, 16));
        labelRazemWybrane_2 = new QLineEdit(groupBox_10);
        labelRazemWybrane_2->setObjectName(QString::fromUtf8("labelRazemWybrane_2"));
        labelRazemWybrane_2->setGeometry(QRect(130, 160, 81, 20));
        label_2 = new QLabel(groupBox_10);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 221, 61));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 541, 331));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 20, 520, 300));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(560, 350, 241, 251));
        pushButton_2 = new QPushButton(groupBox_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 210, 131, 23));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 30, 221, 51));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 160, 101, 16));
        lineEdit_3 = new QLineEdit(groupBox_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 160, 81, 20));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 350, 541, 251));
        tableView_3 = new QTableView(groupBox_6);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(10, 20, 520, 220));
        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(560, 10, 241, 331));
        label = new QLabel(groupBox_9);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 221, 101));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 541, 591));
        tableView_4 = new QTableView(groupBox_7);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(10, 20, 520, 561));
        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(560, 10, 241, 181));
        pushButton_3 = new QPushButton(groupBox_8);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 60, 81, 23));
        lineEdit = new QLineEdit(groupBox_8);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 60, 71, 20));
        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 60, 46, 13));
        pushButton_4 = new QPushButton(groupBox_8);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 120, 81, 23));
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(60, 90, 181, 20));
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 30, 161, 16));
        label_11 = new QLabel(groupBox_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 150, 181, 20));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(Magazynier);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Magazynier);
    } // setupUi

    void retranslateUi(QDialog *Magazynier)
    {
        Magazynier->setWindowTitle(QApplication::translate("Magazynier", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Magazynier", "Wybrany przedmiot:", 0, QApplication::UnicodeUTF8));
        buttonDodaj->setText(QApplication::translate("Magazynier", "Dodaj", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Magazynier", "Opis:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Magazynier", "ilo\305\233\304\207 sztuk:", 0, QApplication::UnicodeUTF8));
        labelNazwa->setText(QString());
        plainTextEdit->setPlainText(QString());
        label_6->setText(QApplication::translate("Magazynier", "Cena z\305\202:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Magazynier", "Razem z\305\202:", 0, QApplication::UnicodeUTF8));
        labelCena->setText(QString());
        labelRazem->setText(QString());
        labelCzyDostepny->setText(QString());
        groupBox_4->setTitle(QApplication::translate("Magazynier", "Lista wybranych przedmiot\303\263w", 0, QApplication::UnicodeUTF8));
        buttonUsun_2->setText(QApplication::translate("Magazynier", "Usu\305\204", 0, QApplication::UnicodeUTF8));
        buttonCzysc_2->setText(QApplication::translate("Magazynier", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Magazynier", "Baza hurtowni", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Magazynier", "Upust:", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("Magazynier", "Sk\305\202adanie zam\303\263wienia", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Magazynier", "Z\305\202\303\263\305\274 zam\303\263wienie", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Magazynier", "Do zap\305\202aty w sumie z\305\202:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Magazynier", "Sk\305\202adanie zam\303\263wienia", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Magazynier", "Lista zam\303\263wie\305\204", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Magazynier", "Realizacja zam\303\263wienia", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Magazynier", "Realizuj zam\303\263wienie", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Magazynier", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Po realizacji zam\303\263wienia baza sklepu zostanie </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">zaktualizowana.<br />Do Hurtowni zostanie wys\305\202ane potwierdzenie </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">przyj\304\231cia towaru.</span></p>\n"
"<p style=\"-qt-paragraph-t"
                        "ype:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Magazynier", "Do zap\305\202aty w sumie:", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("Magazynier", "Lista towarow zamowienia", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("Magazynier", "Informacje", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Magazynier", "Zarz\304\205dzanie zam\303\263wieniami", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("Magazynier", "Lista towar\303\263w sklepu", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("Magazynier", "Operacje", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Magazynier", "Aktualizuj", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Magazynier", "Cena:", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Magazynier", "Usu\305\204 towar", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Magazynier", "Komunikat", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        label_11->setText(QApplication::translate("Magazynier", "Komunikat", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Magazynier", "Zarz\304\205dzanie towarami", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Magazynier: public Ui_Magazynier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGAZYNIER_H
