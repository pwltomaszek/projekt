#include "sprzedawca.h"
#include "ui_sprzedawca.h"

Sprzedawca::Sprzedawca(QWidget *parent, DBProxy &dbproxy) :
    QWidget(parent),
    ui(new Ui::Sprzedawca),
    db( dbproxy )
{
    ui->setupUi(this);
    ui->buttonDodaj->setDisabled( true );


    towary = db.pobierz< DBProxy::TowarSklep >();
    wyswietlTowary();

        
}

Sprzedawca::~Sprzedawca()
{
    delete ui;
}

void Sprzedawca::changeEvent(QEvent *e)
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


void Sprzedawca::wyswietlTowary() {
    
    for (int row = 0; row < towary.size(); ++row) {

        model.setItem( row, 0, new QStandardItem( towary[row].nazwa ) );
        model.setItem( row, 1, new QStandardItem( towary[row].nazwa ) );
        model.setItem( row, 2, new QStandardItem( towary[row].opis ) );
        model.setItem( row, 3, new QStandardItem( liczbaNaString( towary[row].cena) ) );
        model.setItem( row, 4, new QStandardItem( liczbaNaString( towary[row].ilosc ) ) );
        model.setItem( row, 5, new QStandardItem( towary[row].id ) );

    }
    
    model.setHeaderData( 0, Qt::Horizontal,  "Kategoria" );
    model.setHeaderData( 1, Qt::Horizontal, "Nazwa" );
    model.setHeaderData( 2, Qt::Horizontal, "Opis" );
    model.setHeaderData( 3, Qt::Horizontal, "Cena" );
    model.setHeaderData( 4, Qt::Horizontal, "Iloœæ" );

    ui->widokTowary->setModel( &model );
    ui->widokTowary->setColumnWidth( 0, 150 );
    ui->widokTowary->setColumnWidth( 1, 150 );
    ui->widokTowary->setColumnWidth( 2, 150 );
    ui->widokTowary->setColumnWidth( 3, 60 );
    ui->widokTowary->setColumnWidth( 4, 60 );
    ui->widokTowary->setColumnHidden( 5, true );

}


void Sprzedawca::wyswietlWybraneTowary(){

    model_2.setItem( wybraneTowary.size()-1, 0, new QStandardItem( wybraneTowary.last().nazwa ) );
    model_2.setItem( wybraneTowary.size()-1, 1, new QStandardItem( wybraneTowary.last().opis ) );
    model_2.setItem( wybraneTowary.size()-1, 2, new QStandardItem( liczbaNaString( wybraneTowary.last().cena ) ) );
    model_2.setItem( wybraneTowary.size()-1, 3, new QStandardItem( liczbaNaString( wybraneTowary.last().ilosc ) ) );
    model_2.setItem( wybraneTowary.size()-1, 4, new QStandardItem( ui->labelRazem->text() ) );

    model_2.setHeaderData( 0, Qt::Horizontal, tr( "Nazwa" ) );
    model_2.setHeaderData( 1, Qt::Horizontal, tr( "Opis" ) );
    model_2.setHeaderData( 2, Qt::Horizontal, tr( "Cena" ) );
    model_2.setHeaderData( 3, Qt::Horizontal, tr( "Ilosc" ) );
    model_2.setHeaderData( 4, Qt::Horizontal, tr( "Razem" ) );

    ui->widokWybraneTowary->setModel( &model_2 );
    ui->widokWybraneTowary->setColumnWidth( 0, 60 );
    ui->widokWybraneTowary->setColumnWidth( 1, 60 );
    ui->widokWybraneTowary->setColumnWidth( 2, 60 );
    ui->widokWybraneTowary->setColumnWidth( 3, 60 );
    ui->widokWybraneTowary->setColumnWidth( 4, 60 );

}

QString Sprzedawca::razemWybrane(){
    float razem;
    foreach( DBProxy::TowarSklep towar, wybraneTowary){
        razem+= towar.cena * towar.ilosc;
    }

    return liczbaNaString( razem );
}


QString Sprzedawca::liczbaNaString( float f ){
    QVariant v( f );
    QString s = v.toString();
    return s;
}








void Sprzedawca::on_widokTowary_clicked(QModelIndex index)
{
    int ind = index.row();
    ui->widokTowary->selectRow( ind );

    if ( towary[ind].ilosc == 0 ){
        ui->spinBox->setDisabled( true );
        ui->labelCzyDostepny->setText( "TOWAR NIEDOSTÊPNY" );
        ui->buttonDodaj->setDisabled( true );
    }
    else{
        ui->buttonDodaj->setEnabled( true );
        ui->labelCzyDostepny->setText( "" );
        ui->spinBox->setEnabled( true );
        ui->spinBox->setValue( 1 );
        ui->spinBox->setMaximum( towary[ind].ilosc );
    }

    ui->labelNazwa->setText( towary[ind].nazwa );
    ui->plainTextEdit->setPlainText( towary[ind].opis );
    ui->labelCena->setText( liczbaNaString( towary[ind].cena ) );
    ui->labelRazem->setText( liczbaNaString( towary[ind].cena ) );

}



void Sprzedawca::on_spinBox_valueChanged(int )
{
    QVariant v( ui->labelCena->text() );
    float razem = v.toFloat() * ui->spinBox->value();
    ui->labelRazem->setText( liczbaNaString( razem ) );
}



void Sprzedawca::on_buttonDodaj_clicked()
{
    bool czyTowarWybrany = false;

    foreach( DBProxy::TowarSklep towar, wybraneTowary){
        if ( towar.id == towary[ui->widokTowary->currentIndex().row()].id ){
            czyTowarWybrany = true;
            break;
        }
    }

    if ( czyTowarWybrany )
        QMessageBox::information(  this, "!", "Towar znajdujê siê ju¿ na liœcie wybranych towarów", QMessageBox::Ok );

    else{
        wybraneTowary.append( towary[ ui->widokTowary->currentIndex().row() ] );
        unsigned int uInt = ui->spinBox->value();
        wybraneTowary.last().ilosc = uInt;
        wyswietlWybraneTowary();
        ui->labelRazemWybrane->setText( razemWybrane() );

    }

}



void Sprzedawca::on_buttonCzysc_clicked()
{
    unsigned int ret = QMessageBox::question( this, "?",
                                              "Czy na pewno chcesz wyczyœciæ listê zamówionych towarów?",
                                              QMessageBox::Yes | QMessageBox::No );
    if ( ret & QMessageBox::Yes ){
        model_2.clear();
        wybraneTowary.clear();
        ui->labelRazemWybrane->setText( "0" );
        ui->widokWybraneTowary->setModel( &model_2 );
    }

    if ( ret & QMessageBox::No )
        return;
}

void Sprzedawca::on_buttonUsun_clicked()
{
    int ind = ui->widokWybraneTowary->currentIndex().row();

    if ( ind < 0 ){
        QMessageBox::warning( this, "!", "Najpierw zaznacz towar do usuniêcia", QMessageBox::Ok);
    }

    else{
        unsigned int ret = QMessageBox::question( this, "?", "Czy na pewno chcesz usun¹æ wybrany towar?",
                                        QMessageBox::Yes | QMessageBox::No );
        if ( ret & QMessageBox::Yes ){
            wybraneTowary.removeAt( ind );
            model_2.removeRow( ind, QModelIndex() );
        }

        if ( ret & QMessageBox::No )
            return;
    }

}

void Sprzedawca::on_widokWybraneTowary_clicked(QModelIndex index)
{
    ui->widokWybraneTowary->selectRow( index.row() );
}




void Sprzedawca::on_pushButton_clicked()
{
    foreach( DBProxy::TowarSklep towar, wybraneTowary ){
        qDebug() << towar.nazwa;
    }
    qDebug() << "";
}


void Sprzedawca::on_buttonGotowe_clicked()
{
    if ( wybraneTowary.isEmpty() )
        QMessageBox::warning( this, "!", "Lista wybranych towarów jest pusta.", QMessageBox::Ok );

    else{
        Finalizacja *fin = new Finalizacja( this, wybraneTowary, db); //na stercie
        fin->show();
    }
}
