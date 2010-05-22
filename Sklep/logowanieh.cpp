#include "logowanieh.h"
#include "ui_logowanieh.h"
#include <QMessageBox>
LogowanieH::LogowanieH(QWidget *parent, DBProxy &dbproxy, int pracownikId ) :
    QWidget(parent),
    ui(new Ui::LogowanieH),
    db( dbproxy ),
    pId( pracownikId )
{
    ui->setupUi(this);

    hurtownie = db.pobierz< DBProxy::Hurtownia >();
    foreach( DBProxy::Hurtownia hurtownia, hurtownie ) {
        ui->comboBox->addItem( hurtownia.nazwa );
    }
}


LogowanieH::~LogowanieH()
{
    delete ui;
    delete dbH;
}

void LogowanieH::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}




void LogowanieH::on_comboBox_currentIndexChanged(QString hurtownia)
{
    hurtowniaLogowanie = hurtownia;
}

void LogowanieH::on_pushButton_clicked()    //polacz / rozlacz
{
    if( ui->pushButton->text() == "Po³¹cz" ) {
        QString wpisaneHaslo = ui->lineEdit->text();

        if ( hurtowniaLogowanie == "")
            QMessageBox::information( this, "!", "Musisz wybraæ hurtownie", QMessageBox::Ok );

//        if ( wpisaneHaslo == "")
//            QMessageBox::information(  this, "!", "Musisz wprowadziæ has³o", QMessageBox::Ok );

        else {

            bool czyHasloPoprawne = false;

            foreach( DBProxy::Hurtownia hurtownia, hurtownie ) {
               // if ( ( hurtownia.nazwa == hurtowniaLogowanie ) && ( hurtownia.haslo == wpisaneHaslo ) ){
                if ( ( hurtownia.nazwa == hurtowniaLogowanie ) ){
                    hurtowniaHaslo = hurtownia.haslo;
                    hurtowniaLogin = hurtownia.login;
                    hurtowniaHost = hurtownia.host;
                    czyHasloPoprawne = true;
                    break;
                }
            }

            dbH = new DBProxy( NULL, hurtowniaHost, "Hurtownia", hurtowniaLogin, hurtowniaHaslo );
            dbH->polacz();
            if ( czyHasloPoprawne ){
                Magazynier *m = new Magazynier( this, db, *dbH, pId); //na stercie
                m->show();
            }
            else
               QMessageBox::information( this, "!", "Wprowadzono b³êdne has³o", QMessageBox::Ok );
        }
    }
    else{
        //rozlaczH();
    }
}
