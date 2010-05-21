#ifndef MAGAZYNIER_H
#define MAGAZYNIER_H

#include <QDialog>
#include "../DBProxy/dbproxy.h"
#include <QStandardItemModel>
#include <QMessageBox>
using namespace DBProxyNS;

namespace Ui {
    class Magazynier;
}

class Magazynier : public QDialog {
    Q_OBJECT

private:
    Ui::Magazynier *ui;

public:
    Magazynier(QWidget *parent, DBProxy &dbproxy, DBProxy &dbproxy2);
    ~Magazynier();
    float upust;
    QList< Sklep > sklep;
    QList< TowarHurtownia > towaryH;
    QList< Kategoria > kH;
    QList< ZamowienieHurtownia > zamowieniaH;
    QList< TowarHurtownia > wybraneTowaryH;
    QStandardItemModel model, model_2, model_3;
    DBProxy &db, &dbH;
    PozycjaZamowienia *pz;

protected:
    void changeEvent(QEvent *e);



private slots:
    void on_tableView_2_clicked(QModelIndex index);
    void on_pushButton_clicked();
    void on_buttonUsun_2_clicked();
    void on_buttonCzysc_2_clicked();
    void on_buttonDodaj_clicked();
    void on_spinBox_valueChanged(int );
    void on_tableView_clicked(QModelIndex index);
    void pobierzDane();
    void pobierzZamowienia();
    void wyswietlWybraneTowary();
    QString razemWybrane();
};

#endif // MAGAZYNIER_H
