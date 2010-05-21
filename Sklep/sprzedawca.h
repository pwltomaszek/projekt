#ifndef SPRZEDAWCA_H
#define SPRZEDAWCA_H

#include <QWidget>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QSplitter>
#include <QTextEdit>

#include "../DBProxy/dbproxy.h"
#include "finalizacja.h"



namespace Ui {
    class Sprzedawca;
}

class Sprzedawca : public QWidget {
    Q_OBJECT
public:
    Sprzedawca(QWidget *parent, DBProxy &dbproxy);
    ~Sprzedawca();

    QStandardItemModel model;
    QStandardItemModel model_2;
    QList< DBProxy::TowarSklep > towary;
    QList< DBProxy::TowarSklep > wybraneTowary;



    DBProxy &db;


    void wyswietlTowary();
    void wyswietlWybraneTowary();
    QString liczbaNaString( float f );
    QString razemWybrane();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Sprzedawca *ui;



private slots:
    void on_buttonGotowe_clicked();
    void on_pushButton_clicked();
    void on_widokWybraneTowary_clicked(QModelIndex index);
    void on_buttonUsun_clicked();
    void on_buttonCzysc_clicked();
    void on_buttonDodaj_clicked();
    void on_spinBox_valueChanged(int );
    void on_widokTowary_clicked(QModelIndex index);
};

#endif // SPRZEDAWCA_H
