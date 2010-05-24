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
    QList< TowarSklep > towarySS;       //towary sklepu; 3. tab
    QList< TowarHurtownia > towaryH, towaryHZ;  //HZ - towary hurtowni juz zamowione uzywane w 2. tabie
    QList< PozycjaZamowienia > pozycjeZamowienia;   //wszystkie pozycje zamowienia danego zlecenia
    QList< Kategoria > kH;
    QList< ZamowienieHurtownia > zamowieniaH;
    QList< TowarHurtownia > wybraneTowaryH;
    QStandardItemModel model, model_2, model_3, model_4, model_5;
    QList< TowarHurtownia > towaryHA;  //towary z hurtowni do aktualizacji w sklepie
    ZamowienieHurtownia *zamowienieH;  //konkretne zamowienie do aktualizacji

    int idxTowaru;      //do operacji na liscie towarow

protected:
    void changeEvent(QEvent *e);



private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_tableView_4_clicked(QModelIndex index);
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
    void pobierzTowary();
    QString razemWybrane();
    QList< TowarSklep > zwrocWykluczone();
};

#endif // MAGAZYNIER_H
