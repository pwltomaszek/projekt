#ifndef MAGAZYNIER_H
#define MAGAZYNIER_H

#include <QDialog>
#include "../DBProxy/dbproxy.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QTableView>
#include <QList>
#include <stdlib.h>


using namespace DBProxyNS;

namespace Ui {
    class Magazynier;
}

class Magazynier : public QDialog {
    Q_OBJECT

private:
    Ui::Magazynier *ui;

public:
    Magazynier(QWidget *parent, DBProxy &dbproxy, DBProxy &dbproxy2, int pId );
    ~Magazynier();
    float upust;

    DBProxy &db, &dbH;
    Sklep *sklep;
    Hurtownia *hurtownia;
    QString login;
    int sklepId, hurtowniaId, pracownikId;
    QList< TowarSklep > towaryS;        //towary zlozonego zamowienia; maja byc dodane do bazy sklepu
    QList< TowarHurtownia > towaryH, towaryHZ;  //HZ - towary hurtowni juz zamowione uzywane w 2. tabie
    QList< PozycjaZamowienia > pozycjeZamowienia;   //wszystkie pozycje zamowienia danego zlecenia
    QList< Kategoria > kH;
    QList< ZamowienieHurtownia > zamowieniaH;
    QList< TowarHurtownia > wybraneTowaryH;
    QStandardItemModel model, model_2, model_3, model_4;    
    QList< TowarHurtownia > towaryHA;  //towary z hurtowni do aktualizacji w sklepie
    ZamowienieHurtownia *zamowienieH;  //konkretne zamowienie do aktualizacji

protected:
    void changeEvent(QEvent *e);



private slots:
    void dane();
    void on_pushButton_2_clicked();
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
