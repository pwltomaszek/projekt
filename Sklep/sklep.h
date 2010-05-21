#ifndef SKLEP_H
#define SKLEP_H

#include <QDebug>
#include <QtSql>
#include <QMainWindow>
#include <QGridLayout>
#include <QListWidgetItem>
#include <QMessageBox>


#include "sprzedawca.h"
#include "kierownik.h"
#include "logowanieh.h"
//#include "magazynier.h"
#include "../DBProxy/dbproxy.h"

class Sprzedawca;

namespace Ui {
    class Sklep;
}

class OknoSklep : public QMainWindow {
    Q_OBJECT
public:
    OknoSklep(QWidget *parent = 0);
    ~OknoSklep();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Sklep *ui;

public:
    DBProxy db;

    QString posadaLogowanie;
    QString osobaLogowanie;
    QList< DBProxy::Pracownik > pracownicy;

private slots:

    void on_listWidget_itemClicked(QListWidgetItem* item);
    void on_pushButton_clicked();
    void on_comboBox_currentIndexChanged(QString );

friend class Sprzedawca;

};

#endif // SKLEP_H
