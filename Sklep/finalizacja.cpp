#include "finalizacja.h"
#include "ui_finalizacja.h"
#include "sprzedawca.h"

using namespace DBProxyNS;


Finalizacja::Finalizacja(QWidget *parent, QList<DBProxy::TowarSklep> &wybraneTowaryRef, DBProxy &dbproxy) :
    QDialog(parent),
    ui(new Ui::Finalizacja),
    wybraneTowary(wybraneTowaryRef),
    db( dbproxy )
{
    ui->setupUi(this);


    klienci = db.pobierz< DBProxy::Klient >();
    wyswietlKlientow();
    blokujEdycje();




}

Finalizacja::~Finalizacja()
{
    delete ui;
}

void Finalizacja::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void Finalizacja::wyswietlKlientow() {

    for (int row = 0; row < klienci.size(); ++row) {

        model.setItem( row, 0, new QStandardItem( liczbaNaString( klienci[row].id ) ) );
        model.setItem( row, 1, new QStandardItem( klienci[row].nazwa ) );
        model.setItem( row, 2, new QStandardItem( klienci[row].miejscowosc ) );
        model.setItem( row, 3, new QStandardItem( klienci[row].ulica ) );
    }

    model.setHeaderData( 1, Qt::Horizontal,  "Nazwa" );
    model.setHeaderData( 2, Qt::Horizontal, "Miejscowoœæ" );
    model.setHeaderData( 3, Qt::Horizontal, "Ulica" );

    ui->widokKlienci->setModel( &model );
    ui->widokKlienci->setColumnHidden( 0, true );
    ui->widokKlienci->setColumnWidth( 1, 150 );
    ui->widokKlienci->setColumnWidth( 2, 100 );
    ui->widokKlienci->setColumnWidth( 3, 100 );
}




int Finalizacja::ind(){

   QModelIndex ind = model.index( ui->widokKlienci->currentIndex().row(), 0, QModelIndex() );
   QVariant v(model.itemFromIndex( ind )->text());
   int idKlienta = v.toInt();
   int pozycja = 0;
   foreach( DBProxy::Klient klient, klienci){
       if ( idKlienta == klient.id ){
           return pozycja;
       }
       pozycja++;
   }
}


QString Finalizacja::liczbaNaString( float f ){
    QVariant v( f );
    QString s = v.toString();
    return s;
}


void Finalizacja::blokujEdycje(){

    ui->buttonAnulujEdycja->setEnabled( false );
    ui->buttonCzysc->setEnabled( false );
    ui->buttonZatwierdz->setEnabled( false );
    ui->layoutWidget_2->setEnabled( false );
}



void Finalizacja::umozliwEdycje(){

    ui->buttonAnulujEdycja->setEnabled( true );
    ui->buttonCzysc->setEnabled( true );
    ui->buttonZatwierdz->setEnabled( true );
    ui->layoutWidget_2->setEnabled( true );
}

void Finalizacja::czyscEdycje(){

    ui->lineEditNazwa->clear();
    ui->lineEditEmail->clear();
    ui->lineEditKod->clear();
    ui->lineEditMiejsc->clear();
    ui->lineEditRegon->clear();
    ui->lineEditTelefon->clear();
    ui->lineEditUlica->clear();
}

void Finalizacja::wypiszSzczegoly(){

    int i = ind();
    ui->lineEditNazwa->setText( klienci[i].nazwa );
    ui->lineEditEmail->setText( klienci[i].email );
    ui->lineEditKod->setText( klienci[i].kodPocztowy );
    ui->lineEditMiejsc->setText( klienci[i].miejscowosc );
    ui->lineEditRegon->setText( klienci[i].regon );
    ui->lineEditTelefon->setText( klienci[i].telefon );
    ui->lineEditUlica->setText( klienci[i].ulica );
}



void Finalizacja::dodajKlienta(){
    DBProxyNS::Klient klient( ui->lineEditRegon->text(),
                             ui->lineEditNazwa->text(),
                             ui->lineEditUlica->text(),
                             ui->lineEditMiejsc->text(),
                             ui->lineEditKod->text(),
                             ui->lineEditTelefon->text(),
                             ui->lineEditEmail->text(),
                             7);
    unsigned int id;
    if( ( id = db.dodaj( klient ) ) != 0 )
        qDebug() << "Klient dodany do bazy";
}




void Finalizacja::on_widokKlienci_clicked(QModelIndex index)
{
    ui->widokKlienci->selectRow(index.row());
    wypiszSzczegoly();
}


void Finalizacja::on_pushButton_clicked()
{
    foreach( DBProxy::TowarSklep towar, wybraneTowary ){
        qDebug() << towar.nazwa;
    }
    qDebug() << "";

    ui->widokKlienci->sortByColumn( 0, Qt::DescendingOrder );
    dodajKlienta();

}


void Finalizacja::on_buttonDodaj_clicked()
{
//    unsigned int ret = QMessageBox::question( this, "?", "Chcesz dodaæ nowego klienta?")

    umozliwEdycje();
    czyscEdycje();
}
