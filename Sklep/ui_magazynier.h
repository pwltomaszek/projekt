/********************************************************************************
** Form generated from reading UI file 'magazynier.ui'
**
** Created: Fri 21. May 20:20:21 2010
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
    QLabel *label_9;
    QLabel *labelRazemWybrane_2;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label_2;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QTableView *tableView_2;
    QLabel *label;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_2;
    QLabel *label_8;

    void setupUi(QDialog *Magazynier)
    {
        if (Magazynier->objectName().isEmpty())
            Magazynier->setObjectName(QString::fromUtf8("Magazynier"));
        Magazynier->resize(830, 650);
        Magazynier->setModal(false);
        tabWidget = new QTabWidget(Magazynier);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 811, 631));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(530, 10, 271, 311));
        buttonDodaj = new QPushButton(groupBox_3);
        buttonDodaj->setObjectName(QString::fromUtf8("buttonDodaj"));
        buttonDodaj->setGeometry(QRect(190, 280, 75, 23));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 46, 13));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 230, 61, 16));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(90, 230, 42, 22));
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
        plainTextEdit->setGeometry(QRect(10, 70, 251, 121));
        plainTextEdit->setReadOnly(true);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 210, 46, 13));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 260, 46, 13));
        labelCena = new QLabel(groupBox_3);
        labelCena->setObjectName(QString::fromUtf8("labelCena"));
        labelCena->setGeometry(QRect(70, 210, 61, 16));
        labelRazem = new QLabel(groupBox_3);
        labelRazem->setObjectName(QString::fromUtf8("labelRazem"));
        labelRazem->setGeometry(QRect(70, 260, 61, 16));
        labelCzyDostepny = new QLabel(groupBox_3);
        labelCzyDostepny->setObjectName(QString::fromUtf8("labelCzyDostepny"));
        labelCzyDostepny->setGeometry(QRect(140, 230, 131, 20));
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
        groupBox_4->setGeometry(QRect(9, 330, 511, 271));
        buttonUsun_2 = new QPushButton(groupBox_4);
        buttonUsun_2->setObjectName(QString::fromUtf8("buttonUsun_2"));
        buttonUsun_2->setGeometry(QRect(20, 240, 75, 23));
        buttonCzysc_2 = new QPushButton(groupBox_4);
        buttonCzysc_2->setObjectName(QString::fromUtf8("buttonCzysc_2"));
        buttonCzysc_2->setGeometry(QRect(110, 240, 75, 23));
        widokWybraneTowary_2 = new QTableView(groupBox_4);
        widokWybraneTowary_2->setObjectName(QString::fromUtf8("widokWybraneTowary_2"));
        widokWybraneTowary_2->setGeometry(QRect(10, 20, 491, 180));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 210, 46, 13));
        labelRazemWybrane_2 = new QLabel(groupBox_4);
        labelRazemWybrane_2->setObjectName(QString::fromUtf8("labelRazemWybrane_2"));
        labelRazemWybrane_2->setGeometry(QRect(90, 210, 46, 13));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 511, 311));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(51, 24, 61, 20));
        lineEdit_2->setReadOnly(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 27, 46, 13));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 50, 490, 250));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 410, 101, 23));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 460, 241, 61));
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
        groupBox_2->setGeometry(QRect(10, 10, 511, 311));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 20, 491, 281));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 40, 251, 101));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 330, 511, 271));
        pushButton_2 = new QPushButton(groupBox_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 20, 91, 23));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 20, 321, 51));
        tabWidget->addTab(tab_2, QString());

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
        label_6->setText(QApplication::translate("Magazynier", "Cena:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Magazynier", "Razem:", 0, QApplication::UnicodeUTF8));
        labelCena->setText(QString());
        labelRazem->setText(QString());
        labelCzyDostepny->setText(QString());
        groupBox_4->setTitle(QApplication::translate("Magazynier", "Lista wybranych przedmiot\303\263w", 0, QApplication::UnicodeUTF8));
        buttonUsun_2->setText(QApplication::translate("Magazynier", "Usu\305\204", 0, QApplication::UnicodeUTF8));
        buttonCzysc_2->setText(QApplication::translate("Magazynier", "Czy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Magazynier", "Razem:", 0, QApplication::UnicodeUTF8));
        labelRazemWybrane_2->setText(QApplication::translate("Magazynier", "0", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Magazynier", "Baza hurtowni", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Magazynier", "Upust:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Magazynier", "Z\305\202\303\263\305\274 zam\303\263wienie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Magazynier", "Sk\305\202adanie zam\303\263wienia", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Magazynier", "Lista zam\303\263wie\305\204", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        groupBox_5->setTitle(QApplication::translate("Magazynier", "Aktualizacja bazy sklepu", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Magazynier", "Aktualizuj", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Magazynier", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Po aktualizacji baza sklepu zostanie update'owana.<br />Do Hurtowni zostanie wys\305\202ane potwierdzenie przyj\304\231cia towaru.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Magazynier", "Aktualizacja bazy sklepu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Magazynier: public Ui_Magazynier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGAZYNIER_H
