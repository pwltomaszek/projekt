#include "magazynier.h"
#include "ui_magazynier.h"

Magazynier::Magazynier(QWidget *parent, DBProxy &dbproxy, DBProxy &dbproxy2, int pId) :
    QDialog(parent),
    ui(new Ui::Magazynier),
    db( dbproxy ),
    dbH( dbproxy2 ),
    pracownikId( pId )
    //zamowienieH( NULL ),

{
    ui->setupUi(this);
    dbH.polacz();

    dane();
    pobierzDane();
    pobierzZamowienia();
}

Magazynier::~Magazynier()
{
    delete ui;
    dbH.rozlacz();
}

void Magazynier::changeEvent(QEvent *e)
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


void Magazynier::dane()      //inicjuje pewne dane
{
    login = dbH.getLogin();
    FiltrSklep filtrS;
    FiltrHurtownia filtrH;
    FiltrPracownik filtrP;

    filtrH.insert( Hurtownia::Login, DBProxy::Filtr( login, DBProxy::Rowne ) );
    hurtownia = &db.pobierz< Hurtownia >( filtrH ).first();
    hurtowniaId = hurtownia->id;

    filtrS.insert( Sklep::Login, DBProxy::Filtr( login, DBProxy::Rowne ) );
    sklep = &dbH.pobierz< Sklep >( filtrS ).first();
    sklepId = sklep->id;
}


void Magazynier::pobierzDane()      //wyswietla towary hurtowni
{
    upust = sklep->upust/100;
    ui->lineEdit_2->setText( DBProxy::liczbaNaString( upust*100 ).append("%") );

    towaryH = dbH.pobierz< DBProxy::TowarHurtownia >();

    for (int i = 0; i < towaryH.size(); i++) {
        model.setItem( i, 0, new QStandardItem( DBProxy::liczbaNaString( towaryH[i].id ) ) );
        model.setItem( i, 1, new QStandardItem( towaryH[i].nazwa ) );
        model.setItem( i, 2, new QStandardItem( towaryH[i].opis ) );
        model.setItem( i, 3, new QStandardItem( DBProxy::vatNaString( towaryH[i].vat ) ) );
        model.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( towaryH[i].ilosc ) ) );
        model.setItem( i, 5, new QStandardItem( DBProxy::liczbaNaString( towaryH[i].cena ) ) );
    }

    model.setHeaderData( 0, Qt::Horizontal, "Id" );
    model.setHeaderData( 1, Qt::Horizontal, "Nazwa" );
    model.setHeaderData( 2, Qt::Horizontal, "Opis" );
    model.setHeaderData( 3, Qt::Horizontal, "VAT" );
    model.setHeaderData( 4, Qt::Horizontal, "Ilość" );
    model.setHeaderData( 5, Qt::Horizontal, "Cena" );

    ui->tableView->setModel( &model );
    ui->tableView->setColumnWidth( 0, 80 );
    ui->tableView->setColumnWidth( 1, 120 );
    ui->tableView->setColumnWidth( 2, 120 );
    ui->tableView->setColumnWidth( 3, 50 );
    ui->tableView->setColumnWidth( 4, 50 );
    ui->tableView->setColumnWidth( 5, 50 );

}

void Magazynier::on_tableView_clicked(QModelIndex index)    //po kliknieciu w towar...
{
    int idx = index.row();
    ui->tableView->selectRow( idx );

    if ( towaryH[idx].ilosc == 0 ){
        ui->spinBox->setDisabled( true );
        ui->labelCzyDostepny->setText( "TOWAR NIEDOSTĘPNY" );
        ui->buttonDodaj->setDisabled( true );
    }
    else{
        ui->buttonDodaj->setEnabled( true );
        ui->labelCzyDostepny->setText( "" );
        ui->spinBox->setEnabled( true );
        ui->spinBox->setValue( 1 );
        ui->spinBox->setMaximum( towaryH[idx].ilosc );
    }

    ui->labelNazwa->setText( towaryH[idx].nazwa );
    ui->plainTextEdit->setPlainText( towaryH[idx].opis );
    ui->labelCena->setText( DBProxy::liczbaNaString( towaryH[idx].cena - towaryH[idx].cena * upust) );
    ui->labelRazem->setText( DBProxy::liczbaNaString( towaryH[idx].cena - towaryH[idx].cena * upust) );
}

void Magazynier::on_spinBox_valueChanged(int )
{
    QVariant v( ui->labelCena->text() );
    float razem = v.toFloat() * ui->spinBox->value();
    ui->labelRazem->setText( DBProxy::liczbaNaString( razem - razem * upust ) );
}

void Magazynier::wyswietlWybraneTowary(){  //wybrane towary

    model_2.setItem( wybraneTowaryH.size()-1, 0, new QStandardItem( wybraneTowaryH.last().nazwa ) );
    model_2.setItem( wybraneTowaryH.size()-1, 1, new QStandardItem( DBProxy::liczbaNaString( wybraneTowaryH.last().ilosc ) ) );
    model_2.setItem( wybraneTowaryH.size()-1, 2, new QStandardItem( ui->labelRazem->text() ) );

    model_2.setHeaderData( 0, Qt::Horizontal, tr( "Nazwa" ) );
    model_2.setHeaderData( 1, Qt::Horizontal, tr( "Ilosc" ) );
    model_2.setHeaderData( 2, Qt::Horizontal, tr( "Razem" ) );

    ui->widokWybraneTowary_2->setModel( &model_2 );
    ui->widokWybraneTowary_2->setColumnWidth( 0, 150 );
    ui->widokWybraneTowary_2->setColumnWidth( 1, 150 );
    ui->widokWybraneTowary_2->setColumnWidth( 2, 60 );
}

QString Magazynier::razemWybrane(){
    float razem = 0;
    foreach( DBProxy::TowarHurtownia towar, wybraneTowaryH){
        razem += ( towar.cena - towar.cena * upust ) * towar.ilosc;
    }
    return DBProxy::liczbaNaString( razem );
}

void Magazynier::on_buttonDodaj_clicked()       //dodawanie do listy
{
    if ( ui->labelNazwa->text() == "")
        QMessageBox::warning( this, "!", "Najpierw zaznacz towar do dodania.", QMessageBox::Ok);
    else
    {
        bool czyTowarWybrany = false;

        foreach( DBProxy::TowarHurtownia towar, wybraneTowaryH){
            if ( towar.id == towaryH[ui->tableView->currentIndex().row()].id ){
                czyTowarWybrany = true;                
                break;
            }
        }

        if ( czyTowarWybrany )
            QMessageBox::information(  this, "!", "Towar znajduję się już na liście wybranych towarów.", QMessageBox::Ok );
        else{
            wybraneTowaryH.append( towaryH[ ui->tableView->currentIndex().row() ] );
            wybraneTowaryH.last().ilosc = ui->spinBox->value();
            wyswietlWybraneTowary();
            ui->labelRazemWybrane_2->setText( razemWybrane() );
        }
    }
}

void Magazynier::on_buttonCzysc_2_clicked()     //czyszczenie listy
{
    unsigned int ret = QMessageBox::question( this, "?",
                                              "Czy na pewno chcesz wyczyścić listę zamówionych towarów?",
                                              QMessageBox::Yes | QMessageBox::No );
    if ( ret & QMessageBox::Yes ){
        model_2.clear();
        wybraneTowaryH.clear();
        ui->labelRazemWybrane_2->setText( "0" );
        ui->widokWybraneTowary_2->setModel( &model_2 );
    }

    if ( ret & QMessageBox::No )
        return;
}


void Magazynier::on_buttonUsun_2_clicked()  //usuwanie towaru z listy
{
    int ind = ui->widokWybraneTowary_2->currentIndex().row();

    if ( ind < 0 ){
        QMessageBox::warning( this, "!", "Najpierw zaznacz towar do usunięcia.", QMessageBox::Ok);
    }

    else{
        unsigned int ret = QMessageBox::question( this, "?", "Czy na pewno chcesz usunąć wybrany towar?",
                                        QMessageBox::Yes | QMessageBox::No );
        if ( ret & QMessageBox::Yes ){
            wybraneTowaryH.removeAt( ind );
            model_2.removeRow( ind, QModelIndex() );
        }

        if ( ret & QMessageBox::No )
            return;
    }
}

void Magazynier::on_pushButton_clicked()    //zloz zamowienie
{

    if( wybraneTowaryH.isEmpty() )
        QMessageBox::warning( this, "!", "Puste zamówienie.", QMessageBox::Ok);
    else
    {

        ZamowienieHurtownia zH( sklepId, QDate::currentDate(), "" );
        dbH.dodaj( zH );
        int lastId = dbH.pobierz< ZamowienieHurtownia >().last().id;

        QString faktura = QString::number(hurtowniaId)+ "-" + QString::number( lastId );        //sklada sie z: idHurtowni-random
        dbH.wpiszFakture( lastId , faktura );

        ZamowienieSklep zS( hurtowniaId, pracownikId, QDate::currentDate(), faktura );
        db.dodaj( zS );


        //filtrF.insert( , DBProxy::Filtr( login, DBProxy::Rowne ) );

        

        for(int i=0; i<wybraneTowaryH.length(); i++)    //dodawanie pozycji zamowien do ostatnio dodanego zamowienia
        {
            PozycjaZamowienia pz( wybraneTowaryH[i].id, wybraneTowaryH[i].ilosc, dbH.pobierz< ZamowienieHurtownia >().last().id );
            dbH.dodaj( pz );
        }

        ui->label_2->setWordWrap( true );
        ui->label_2->setText( "Zamówienie zostało złożone. <br /> Status realizacji zamówienia spradzisz w drugim tabie." );

        model_2.clear();            //czyszczenie listy
        wybraneTowaryH.clear();
        ui->labelRazemWybrane_2->setText( "0" );
        ui->widokWybraneTowary_2->setModel( &model_2 );

        pobierzZamowienia(); //odswieza liste w drugim tabie
        // uaktualnij()  //uaktualnia ilosc towarow
    }
}






//###########
//aktualizacja bazy sklepu
//###########
 void Magazynier::pobierzZamowienia()       //lista zamowien
 {
     zamowieniaH = dbH.pobierz< DBProxy::ZamowienieHurtownia >();

//     qDebug() << zamowieniaH[0].status;
//     qDebug() << zamowieniaH[1].status;
//     qDebug() << DBProxy::statusNaString( zamowieniaH[0].status );
     //qDebug() << DBProxy::statusNaString( zamowieniaH[1].status );

     //qDebug() << db.pobierz<ZamowienieSklep>()[2].status;
     //qDebug() << DBProxy::statusNaString( db.pobierz<ZamowienieSklep>()[2].status );

     for (int i = 0; i < zamowieniaH.size(); i++) {
         model_3.setItem( i, 0, new QStandardItem( DBProxy::liczbaNaString( zamowieniaH[i].id ) ) );
         model_3.setItem( i, 1, new QStandardItem( zamowieniaH[i].nrFaktury ) );
         model_3.setItem( i, 2, new QStandardItem( DBProxy::dataNaString( zamowieniaH[i].dataZlozenia ) ) );
         model_3.setItem( i, 3, new QStandardItem( DBProxy::dataNaString( zamowieniaH[i].dataRealizacji ) ) );
         model_3.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( zamowieniaH[i].upust ) ) );
         model_3.setItem( i, 5, new QStandardItem( DBProxy::statusNaString( zamowieniaH[i].status ) ) );
     }

     model_3.setHeaderData( 0, Qt::Horizontal, "Id" );
     model_3.setHeaderData( 1, Qt::Horizontal, "Nr faktury" );
     model_3.setHeaderData( 2, Qt::Horizontal, "Data złożenia" );
     model_3.setHeaderData( 3, Qt::Horizontal, "Data realizacji" );
     model_3.setHeaderData( 4, Qt::Horizontal, "Upust" );
     model_3.setHeaderData( 5, Qt::Horizontal, "Status" );

     ui->tableView_2->setModel( &model_3 );
     ui->tableView_2->setColumnWidth( 0, 50 );
     ui->tableView_2->setColumnWidth( 1, 80 );
     ui->tableView_2->setColumnWidth( 2, 100 );
     ui->tableView_2->setColumnWidth( 3, 100 );
     ui->tableView_2->setColumnWidth( 4, 50 );
     ui->tableView_2->setColumnWidth( 5, 80 );

     ui->groupBox_5->setDisabled( true );
 }

 void Magazynier::on_tableView_2_clicked(QModelIndex index)    //po kliknieciu w zamowienie...
 {

    int idx = index.row();
    ui->tableView_2->selectRow( idx );
    ui->label->setWordWrap( true );

    if ( zamowieniaH[idx].status == DBProxy::Oczekujace ){
        ui->label->setText( "Zamówienie złożone. <br />Czekaj na reakcję Hurtowni." );
        ui->groupBox_5->setDisabled( true );
    }
    else if( zamowieniaH[idx].status == DBProxy::Anulowane ){
        ui->label->setText( "Zamówienie anulowane przez Hurtownię." );
        ui->groupBox_5->setDisabled( true );
    }
    else if( zamowieniaH[idx].status == DBProxy::DoRealizacji ){
        ui->label->setText( "Po odebraniu towaru, zaktualizuj go w bazie sklepu." );
        ui->groupBox_5->setEnabled( true );
    }
    else if( zamowieniaH[idx].status == DBProxy::Zrealizowane ){
        ui->label->setText( "Zamówienie zrealizowane" );
        ui->groupBox_5->setDisabled( true );
    }
    zamowienieH = &zamowieniaH[idx];

    FiltrPozycjaZamowienia filtrPZ;
    FiltrTowarHurtownia filtrTH;

    filtrPZ.insert( DBProxy::PozycjaZamowienia::IdZamowienia, DBProxy::Filtr( zamowienieH->id, DBProxy::Rowne ) );

    pozycjeZamowienia = dbH.pobierz< PozycjaZamowienia >( filtrPZ );    
    foreach (PozycjaZamowienia pZ, pozycjeZamowienia)
    {
        filtrTH.insert( DBProxy::TowarHurtownia::Id, DBProxy::Filtr( pZ.idTowaru, DBProxy::Rowne ) );
    }

    towaryHZ = dbH.pobierz< TowarHurtownia >( filtrTH, DBProxy::OR ); //wszystkie towary danego zamowienia
    QListIterator< PozycjaZamowienia > itPZ( pozycjeZamowienia );

    //qDebug() << "przed czyszczeniem " << towaryS.length();
    towaryS.clear();                    //czyszczenie
    model_4.clear();
    foreach( TowarHurtownia tH, towaryHZ)
    {
        DBProxy::TowarSklep tS( tH.nazwa,
                                tH.opis,
                                itPZ.next().ilosc,
                                tH.cena,
                                tH.vat,
                                tH.cena,
                                 1);  //tH.idKategorii
        towaryS.append( tS );
    }

    for (int i = 0; i < towaryS.length(); i++) {                  //blok ustawia tabele
        model_4.setItem( i, 0, new QStandardItem( towaryS[i].nazwa ) );
        model_4.setItem( i, 1, new QStandardItem( towaryS[i].opis ) );
        model_4.setItem( i, 2, new QStandardItem( DBProxy::vatNaString( towaryS[i].vat ) ) );
        model_4.setItem( i, 3, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].ilosc ) ) );
        model_4.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].cena ) ) );
    }
    model_4.setHeaderData( 0, Qt::Horizontal, tr( "Nazwa" ) );
    model_4.setHeaderData( 1, Qt::Horizontal, tr( "Opis" ) );
    model_4.setHeaderData( 2, Qt::Horizontal, tr( "VAT" ) );
    model_4.setHeaderData( 3, Qt::Horizontal, tr( "Ilosc" ) );
    model_4.setHeaderData( 4, Qt::Horizontal, tr( "Cena" ) );
    ui->tableView_3->setModel( &model_4 );
    ui->tableView_3->setColumnWidth( 0, 80 );
    ui->tableView_3->setColumnWidth( 1, 80 );
    ui->tableView_3->setColumnWidth( 2, 80 );
    ui->tableView_3->setColumnWidth( 3, 80 );
    ui->tableView_3->setColumnWidth( 4, 80 );
 }



void Magazynier::on_pushButton_2_clicked()          //aktualizacja bazy sklepu
{
    QList< TowarSklep > towaryTS;                   //stara lista towarow sklepu
    towaryTS = db.pobierz< TowarSklep >();
    QListIterator< TowarSklep > itTS( towaryTS );   // iterator starych towarow

    foreach ( TowarSklep tS, towaryS)               //dodawanie towarow do bazy sklepu
    {
        while ( itTS.hasNext() )
        {
            TowarSklep staryT = itTS.next();

            if( tS.nazwa == staryT.nazwa )       //jesli nazwy towarow sa takie same...
            {
                db.wpiszIlosc( staryT.id, staryT.ilosc + tS.ilosc );
                break;
            }
            else if ( !itTS.hasNext() )                                 //jesli nazwy towarow sa inne, i juz koniec listy starych towarow...
            {
                db.dodaj( tS );
                break;
            }
        }
        itTS.toFront(); // iterator starych towarow ustawiany na poczatek
    }
    dbH.wpiszStatus( zamowienieH->id , DBProxy::Zrealizowane );     //zmiana statusu
    pobierzZamowienia();        //odswiezanie listy zamowien
}
