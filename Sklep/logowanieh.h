#ifndef LOGOWANIEH_H
#define LOGOWANIEH_H

#include <QWidget>
#include <QSize>
#include "../DBProxy/dbproxy.h"
#include "../Sklep/magazynier.h"
namespace Ui {
    class LogowanieH;
}

class LogowanieH : public QWidget {
    Q_OBJECT

private:
    Ui::LogowanieH *ui;


public:
    LogowanieH(QWidget *parent, DBProxy &dbproxy, int pracownikId);
    ~LogowanieH();

    DBProxy &db, *dbH;
    int pId;
    QString hurtowniaLogowanie, hurtowniaHost, hurtowniaLogin, hurtowniaHaslo;
    QList< DBProxy::Hurtownia > hurtownie;
protected:
    void changeEvent(QEvent *e);



private slots:
    void on_pushButton_clicked();
    void on_comboBox_currentIndexChanged(QString);
};
#endif // LOGOWANIEH_H
