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


    ui->lineEdit_2->setReadOnly( true );
    ui->lineEdit_4->setReadOnly( true );
    ui->lineEdit_5->setReadOnly( true );
    ui->lineEdit_6->setReadOnly( true );
    ui->lineEdit_7->setReadOnly( true );
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
    if ( hurtownia != "wybierz")
    {
        hurtowniaLogowanie = hurtownia;
        Hurtownia h = db.pobierz< Hurtownia >( Hurtownia::Nazwa, Filtr( hurtownia ) ).first();
        ui->lineEdit_2->setText( h.nazwa );
        ui->lineEdit_4->setText( h.telefon );
        ui->lineEdit_5->setText( h.fax );
        ui->lineEdit_6->setText( h.email );
        ui->lineEdit_7->setText( h.miejscowosc );

        hurtowniaHaslo = h.haslo;
    }
    else
    {
        ui->lineEdit_2->setText( QString() );
        ui->lineEdit_4->setText( QString() );
        ui->lineEdit_5->setText( QString() );
        ui->lineEdit_6->setText( QString() );
        ui->lineEdit_7->setText( QString() );

        hurtowniaLogowanie = "";
    }
}

void LogowanieH::on_pushButton_clicked()    //polacz / rozlacz
{
    if( ui->pushButton->text() == "Po³¹cz" ) {        

        if ( hurtowniaLogowanie == "")
            QMessageBox::information( this, "!", "Musisz wybraæ hurtownie", QMessageBox::Ok );

        else {

            bool czyHasloPoprawne = false;

            foreach( DBProxy::Hurtownia hurtownia, hurtownie ) {
                if ( ( hurtownia.nazwa == hurtowniaLogowanie ) ){
                    hurtowniaLogin = hurtownia.login;
                    hurtowniaHost = hurtownia.host;
                    break;
                }
            }

            dbH = new DBProxy( NULL, hurtowniaHost, "Hurtownia", hurtowniaLogin, hurtowniaHaslo );
            dbH->polacz();
                Magazynier *m = new Magazynier( this, db, *dbH, pId); //na stercie
                m->show();
                ui->groupBox->setDisabled( true );
        }
    }
    else{
        //rozlaczH();
    }
}
