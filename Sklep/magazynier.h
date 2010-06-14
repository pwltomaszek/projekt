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
    QList< ZamowienieHurtownia > zamowieniaH, zzz;
    QList< TowarHurtownia > wybraneTowaryH;
    QList< TowarSklep > stareH;
    QStandardItemModel model, model_2, model_3, model_4, model_5;
    QList< TowarHurtownia > towaryHA;  //towary z hurtowni do aktualizacji w sklepie
    ZamowienieHurtownia *zamowienieH;  //konkretne zamowienie do aktualizacji
    QDate odDate, doDate;
    //TowarHurtownia towarH;      //towar sklepu do dodania

    int idxTowaru;      //do operacji na liscie towarow

protected:
    void changeEvent(QEvent *e);



private slots:
    void on_pushButton_5_clicked();
    void on_buttonPokazWszystkich_2_clicked();
    void on_buttonFiltrCena_2_clicked();
    void on_buttonFiltrKat_3_clicked();
    void on_buttonSortRosnaco_2_clicked();
    void on_buttonSortMalejaco_2_clicked();
    void on_buttonSzukaj_2_clicked();
    void on_buttonFiltrKat_2_clicked();
    void on_buttonPokazWszystkich_clicked();
    void on_buttonFiltrCena_clicked();
    void on_buttonFiltrKat_clicked();
    void on_buttonSortRosnaco_clicked();
    void on_buttonSortMalejaco_clicked();
    void on_buttonSzukaj_clicked();
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
    void pobierzDane( QList< TowarHurtownia > );
    void pobierzZamowienia( QList< ZamowienieHurtownia > );
    void wyswietlWybraneTowary();
    void pobierzTowary( QList< TowarSklep > );
    void ograniczeniaZnakow();
    float zaokraglij( float );
    QString razemWybrane();
    QList< TowarSklep > zwrocWykluczone();
};

#endif // MAGAZYNIER_H
