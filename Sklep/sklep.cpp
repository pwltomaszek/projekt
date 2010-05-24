#include "sklep.h"
#include "ui_sklep.h"

OknoSklep::OknoSklep(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sklep),
    db( NULL, "localhost", "Sklep", "root", "" )
{
    ui->setupUi(this);


    if( !db.polacz() )
        qDebug() << "sru";
}

OknoSklep::~OknoSklep()
{
    delete ui;
}

void OknoSklep::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void OknoSklep::on_comboBox_currentIndexChanged( QString posada )
{
    posadaLogowanie = posada;
    if( posada == "wybierz" ){
        ui->listWidget->clear();
        return;
    }

    DBProxyNS::FiltrPracownik filtr;
    filtr.insert( DBProxy::Pracownik::PosadaPole,
                  DBProxy::Filtr( DBProxy::stringNaPosade( posada ) ) );
    pracownicy = db.pobierz< DBProxy::Pracownik >( filtr );



    ui->listWidget->clear();
    foreach( DBProxy::Pracownik pracownik, pracownicy ) {
        ui->listWidget->addItem( new QListWidgetItem( pracownik.nazwa ) );

    }
}

void OknoSklep::on_pushButton_clicked()
{
    QString wpisaneHaslo = ui->lineEdit->text();

    if ( osobaLogowanie == "")
        QMessageBox::information( this, "!", "Musisz wybra? pracownika", QMessageBox::Ok );

    if ( wpisaneHaslo == "")
        QMessageBox::information(  this, "!", "Musisz wprowadzi? has?o", QMessageBox::Ok );

    else {

        bool czyHasloPoprawne;

        foreach( DBProxy::Pracownik pracownik, pracownicy ) {
                    //if ( ( pracownik.nazwa == osobaLogowanie ) && ( pracownik.haslo == wpisaneHaslo ) ){
                    if ( ( pracownik.nazwa == osobaLogowanie )  ){
                        czyHasloPoprawne = true;
                        pracownikId = pracownik.id;
                        break;
                    }
        }

        if ( czyHasloPoprawne ){

            delete ui->widget;
            QSettings settings;

            QWidget *widget = 0;
            if ( posadaLogowanie == "Kierownik" ){
                widget = new Kierownik( this );

            }
            else if ( posadaLogowanie == "Sprzedawca" ){
                widget = new Sprzedawca( this, db );

                QSize size = settings.value( "size", QSize( 1050, 600 ) ).toSize();
                resize( size );
            }
            else {
                widget = new LogowanieH( this, db, pracownikId);
                //QSize size = settings.value( "size", QSize( 1050, 650 ) ).toSize();
                //resize( size );
            }

            ui->centralWidget->layout()->addWidget( widget );
        }

        else
           QMessageBox::information( this, "!", "Wprowadzono b??dne has?o", QMessageBox::Ok );
    }

    int i=10;
    unsigned int un;
    un = i;
    size_t size;
    size = i;
}


void OknoSklep::on_listWidget_itemClicked(QListWidgetItem* item)
{
    osobaLogowanie = item->text();
}
