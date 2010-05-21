#ifndef FINALIZACJA_H
#define FINALIZACJA_H

#include <QDialog>
#include <QStandardItemModel>
#include "../DBProxy/dbproxy.h"

namespace Ui {
    class Finalizacja;
}

class Finalizacja : public QDialog {
    Q_OBJECT
public:
    Finalizacja( QWidget *parent, QList< DBProxy::TowarSklep > &wybraneTowary, DBProxy &dbproxy );
    ~Finalizacja();

    QList< DBProxy::Klient > klienci;
    QStandardItemModel model;
    DBProxy &db;


    void wyswietlKlientow();
    void blokujEdycje();
    void umozliwEdycje();
    void czyscEdycje();
    void wypiszSzczegoly();
    void dodajKlienta();


    QString liczbaNaString( float f );
    int ind();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Finalizacja *ui;
    QList< DBProxy::TowarSklep > &wybraneTowary;

private slots:
    void on_buttonDodaj_clicked();
    void on_widokKlienci_clicked(QModelIndex index);
    void on_pushButton_clicked();
};

#endif // FINALIZACJA_H
