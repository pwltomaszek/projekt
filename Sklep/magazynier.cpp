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
    pobierzTowary();
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

QList< TowarSklep > Magazynier::zwrocWykluczone()
{
    QList< TowarSklep > towaryS = db.pobierz< TowarSklep >(); //wszystkie towary sklepu
    QList< TowarSklep > towaryWykluczone;
    FiltrTowarSklep filtrS;
    foreach( TowarSklep tS, towaryS)
    {        
        filtrS.clear();
        filtrS.insert( TowarSklep::Nazwa, DBProxy::Filtr( tS.nazwa, DBProxy::Rowne ) );
        if( db.pobierz< TowarSklep >( filtrS ).length() == 2 )  //jesli znaleziono 2 takie same produkty
            towaryWykluczone.append( tS );
    }
    return towaryWykluczone;
}

void Magazynier::pobierzDane()      //wyswietla towary hurtowni(tylko te, ktore moga trafic do zamowienia)
{
    upust = sklep->upust;
    ui->lineEdit_2->setText( DBProxy::liczbaNaString( upust ).append("%") );


    QList< TowarSklep > towaryWykluczone = zwrocWykluczone();    
    FiltrTowarHurtownia filtr;
    foreach( TowarSklep t, towaryWykluczone)
    {
        filtr.insert( TowarHurtownia::Nazwa, DBProxy::Filtr( t.nazwa, DBProxy::NieRowne ) );
    }

    towaryH = dbH.pobierz< DBProxy::TowarHurtownia >( filtr );  //zfiltrowane towary; tylko te, ktore sklep ma w maksymalnie jednej pozycj

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
    model.setHeaderData( 4, Qt::Horizontal, "Iloœæ" );
    model.setHeaderData( 5, Qt::Horizontal, "Cena" );

    ui->tableView->setModel( &model );
    ui->tableView->setColumnWidth( 0, 80 );
    ui->tableView->setColumnWidth( 1, 120 );
    ui->tableView->setColumnWidth( 2, 120 );
    ui->tableView->setColumnWidth( 3, 50 );
    ui->tableView->setColumnWidth( 4, 50 );
    ui->tableView->setColumnWidth( 5, 50 );
    ui->tableView->setEditTriggers( QAbstractItemView::NoEditTriggers);

}

void Magazynier::on_tableView_clicked(QModelIndex index)    //po kliknieciu w towar...
{
    int idx = index.row();
    ui->tableView->selectRow( idx );

    if ( towaryH[idx].ilosc == 0 ){
        ui->spinBox->setDisabled( true );
        ui->labelCzyDostepny->setText( "TOWAR NIEDOSTÊPNY" );
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
    ui->labelCena->setText( DBProxy::liczbaNaString( towaryH[idx].cena - towaryH[idx].cena * (upust/100) ) );
    ui->labelRazem->setText( DBProxy::liczbaNaString( towaryH[idx].cena - towaryH[idx].cena * (upust/100) ) );
}

void Magazynier::on_spinBox_valueChanged(int )
{
    QVariant v( ui->labelCena->text() );
    float razem = v.toFloat() * ui->spinBox->value();
    ui->labelRazem->setText( DBProxy::liczbaNaString( razem ) );
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
    ui->widokWybraneTowary_2->setEditTriggers( QAbstractItemView::NoEditTriggers);
}

QString Magazynier::razemWybrane(){
    float razem = 0;
    foreach( DBProxy::TowarHurtownia towar, wybraneTowaryH){
        razem += ( towar.cena - towar.cena * (upust/100) ) * towar.ilosc;
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
            QMessageBox::information(  this, "!", "Towar znajdujê siê ju¿ na liœcie wybranych towarów.", QMessageBox::Ok );
        else{            
            wybraneTowaryH.append( towaryH[ ui->tableView->currentIndex().row() ] );
            wybraneTowaryH.last().ilosc = ui->spinBox->value();
            wybraneTowaryH.last().cena *= (upust/100);
            wyswietlWybraneTowary();
            ui->labelRazemWybrane_2->setText( razemWybrane() );
        }
    }
}

void Magazynier::on_buttonCzysc_2_clicked()     //czyszczenie listy
{
    unsigned int ret = QMessageBox::question( this, "?",
                                              "Czy na pewno chcesz wyczyœciæ listê zamówionych towarów?",
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
        QMessageBox::warning( this, "!", "Najpierw zaznacz towar do usuniêcia.", QMessageBox::Ok);
    }

    else{
        unsigned int ret = QMessageBox::question( this, "?", "Czy na pewno chcesz usun¹æ wybrany towar?",
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
        ZamowienieHurtownia zH( sklepId, QDate::currentDate() );
        unsigned int lastId = dbH.dodaj( zH );

        QString faktura = QString::number(hurtowniaId)+ "-" + QString::number( lastId );        //sklada sie z: idHurtowni-random
        zH.nrFaktury = faktura;

        ZamowienieSklep zS( hurtowniaId, pracownikId, QDate::currentDate(), faktura );
        db.dodaj( zS );  

        zH.status = DBProxy::DoRealizacji;      //do wywalenia
        dbH.uaktualnij( zH );                   //do wywalenia
        for(int i=0; i<wybraneTowaryH.length(); i++)    //dodawanie pozycji zamowien do ostatnio dodanego zamowienia
        {
            PozycjaZamowienia pz( wybraneTowaryH[i].id, wybraneTowaryH[i].ilosc, lastId );
            dbH.dodaj( pz );
        }

        ui->label_2->setWordWrap( true );
        ui->label_2->setText( "Zamówienie zosta³o z³o¿one. <br /> Status realizacji zamówienia spradzisz w drugim tabie." );

        model_2.clear();            //czyszczenie listy
        wybraneTowaryH.clear();
        ui->labelRazemWybrane_2->setText( "0" );
        ui->widokWybraneTowary_2->setModel( &model_2 );

        pobierzZamowienia(); //odswieza liste w drugim tabie
        // uaktualnij()  //uaktualnia ilosc towarow
    }
}






//###########
//Zarzadzanie zamowieniami
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
     model_3.setHeaderData( 2, Qt::Horizontal, "Data z³o¿enia" );
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
     ui->tableView_2->setEditTriggers( QAbstractItemView::NoEditTriggers);

     ui->groupBox_5->setDisabled( true );
 }

 void Magazynier::on_tableView_2_clicked(QModelIndex index)    //po kliknieciu w zamowienie...
 {

    int idx = index.row();
    ui->tableView_2->selectRow( idx );
    ui->label->setWordWrap( true );

    if ( zamowieniaH[idx].status == DBProxy::Oczekujace ){
        ui->label->setText( "Zamówienie z³o¿one. <br />Czekaj na reakcjê Hurtowni." );
        ui->groupBox_5->setDisabled( true );
    }
    else if( zamowieniaH[idx].status == DBProxy::Anulowane ){
        ui->label->setText( "Zamówienie anulowane przez Hurtowniê." );
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

    towaryS.clear();                    //czyszczenie
    model_4.clear();

    FiltrPozycjaZamowienia fi;              //filtr do znajdywania ilosci towaru
    foreach( TowarHurtownia tH, towaryHZ)       //lista towarow z zamowienia
    {
        fi.insert( DBProxy::PozycjaZamowienia::IdZamowienia, DBProxy::Filtr( zamowienieH->id, DBProxy::Rowne ) );
        fi.insert( DBProxy::PozycjaZamowienia::IdTowaru, DBProxy::Filtr( tH.id, DBProxy::Rowne ) );
        DBProxy::TowarSklep tS( tH.nazwa,
                                tH.opis,
                                dbH.pobierz< PozycjaZamowienia >( fi ).first().ilosc,
                                tH.cena,
                                tH.vat,
                                tH.cena - tH.cena * (upust/100),
                                tH.idKategorii);  //tH.idKategorii
        towaryS.append( tS );
        fi.clear();
    }

    for (int i = 0; i < towaryS.length(); i++) {                  //blok ustawia tabele
        model_4.setItem( i, 0, new QStandardItem( towaryS[i].nazwa ) );
        model_4.setItem( i, 1, new QStandardItem( towaryS[i].opis ) );
        model_4.setItem( i, 2, new QStandardItem( DBProxy::vatNaString( towaryS[i].vat ) ) );
        model_4.setItem( i, 3, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].ilosc ) ) );
        model_4.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].cenaZakupu ) ) );
        model_4.setItem( i, 5, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].cenaZakupu * towaryS[i].ilosc) ) );
    }
    model_4.setHeaderData( 0, Qt::Horizontal, tr( "Nazwa" ) );
    model_4.setHeaderData( 1, Qt::Horizontal, tr( "Opis" ) );
    model_4.setHeaderData( 2, Qt::Horizontal, tr( "VAT" ) );
    model_4.setHeaderData( 3, Qt::Horizontal, tr( "Ilosc" ) );
    model_4.setHeaderData( 4, Qt::Horizontal, tr( "Cena zakupu" ) );
    model_4.setHeaderData( 5, Qt::Horizontal, tr( "Cena * ilosc" ) );
    ui->tableView_3->setModel( &model_4 );
    ui->tableView_3->setColumnWidth( 0, 40 );
    ui->tableView_3->setColumnWidth( 1, 120 );
    ui->tableView_3->setColumnWidth( 2, 60 );
    ui->tableView_3->setColumnWidth( 3, 60 );
    ui->tableView_3->setColumnWidth( 4, 100 );
    ui->tableView_3->setColumnWidth( 5, 100 );
    ui->tableView_3->setEditTriggers( QAbstractItemView::NoEditTriggers);

    float suma = 0;                     //obliczenie kosztu zamowienia
    foreach( TowarSklep t, towaryS)
    {
        suma += t.cenaZakupu * t.ilosc;
    }
    ui->lineEdit_3->setText( DBProxy::liczbaNaString( suma ).append( " z³" ));
    ui->lineEdit_3->setReadOnly( true );
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

            if( tS.nazwa == staryT.nazwa )          //jesli nazwy towarow sa takie same...
            {
                if( tS.cena == staryT.cenaZakupu )  // i ceny tez...
                {
                    staryT.ilosc += tS.ilosc;    //tylko zmienia ilosc
                    db.uaktualnij( staryT );
                }
                else
                    db.dodaj( tS );     //nazwy te same. ceny inne.

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

    zamowienieH->status = DBProxy::Zrealizowane;        //zmiana statusu
    dbH.uaktualnij( *zamowienieH );
    pobierzZamowienia();        //odswiezanie listy zamowien
    pobierzTowary();        //odswiezanie listy towarow w tab 3
}



//###########
//Zarzadzanie towarami
//###########

 void Magazynier::pobierzTowary()       //lista towarow
 {
    towarySS = db.pobierz< TowarSklep >();

    for (int i = 0; i < towarySS.length(); i++) {
        model_5.setItem( i, 0, new QStandardItem( DBProxy::liczbaNaString( towarySS[i].id ) ) );
        model_5.setItem( i, 1, new QStandardItem( DBProxy::liczbaNaString( towarySS[i].idKategorii ) ) );
        model_5.setItem( i, 2, new QStandardItem( towarySS[i].nazwa ) );
        model_5.setItem( i, 3, new QStandardItem( towarySS[i].opis ) );
        model_5.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( towarySS[i].cenaZakupu ) ) );
        model_5.setItem( i, 5, new QStandardItem( DBProxy::liczbaNaString( towarySS[i].cena ) ) );
        model_5.setItem( i, 6, new QStandardItem( DBProxy::vatNaString( towarySS[i].vat ) ) );
        model_5.setItem( i, 7, new QStandardItem( DBProxy::liczbaNaString( towarySS[i].ilosc ) ) );
    }

    model_5.setHeaderData( 0, Qt::Horizontal, "Id" );
    model_5.setHeaderData( 1, Qt::Horizontal, "Kategoria" );
    model_5.setHeaderData( 2, Qt::Horizontal, "Nazwa" );
    model_5.setHeaderData( 3, Qt::Horizontal, "Opis" );
    model_5.setHeaderData( 4, Qt::Horizontal, "Cena zakupu" );
    model_5.setHeaderData( 5, Qt::Horizontal, "Cena" );
    model_5.setHeaderData( 6, Qt::Horizontal, "VAT" );
    model_5.setHeaderData( 7, Qt::Horizontal, "Iloœæ" );

    ui->tableView_4->setModel( &model_5 );
    ui->tableView_4->setColumnWidth( 0, 20 );
    ui->tableView_4->setColumnWidth( 1, 70 );
    ui->tableView_4->setColumnWidth( 2, 80 );
    ui->tableView_4->setColumnWidth( 3, 100 );
    ui->tableView_4->setColumnWidth( 4, 90 );
    ui->tableView_4->setColumnWidth( 5, 40 );
    ui->tableView_4->setColumnWidth( 6, 40 );
    ui->tableView_4->setColumnWidth( 7, 40 );
    ui->tableView_4->setEditTriggers( QAbstractItemView::NoEditTriggers);

    ui->label_10->setText( QString() );
    ui->label_11->setText( QString() );
    ui->pushButton_4->setDisabled( true );
 }

void Magazynier::on_tableView_4_clicked(QModelIndex index)    //po kliknieciu w towar...
{ 
    ui->label_10->setText( QString() );

    idxTowaru = index.row();
    ui->tableView_4->selectRow( idxTowaru );
    ui->label_13->setText( towarySS[idxTowaru].nazwa );
    ui->lineEdit->setText( DBProxy::liczbaNaString( towarySS[idxTowaru].cena ) );

    if( towarySS[idxTowaru].ilosc == 0 ) //enable button usuniecia towaru
        ui->pushButton_4->setEnabled( true );
}

void Magazynier::on_pushButton_3_clicked()      //aktualizuj
{
    if( ui->label_13->text().isNull() )                                        //jesli nie wybrano towaru
        ui->label_10->setText( "Nie wybrano towaru." );
    else if( ui->lineEdit->text().toFloat() <= 0 || ui->lineEdit->text().isEmpty() )  //jesli wartosc <= zero lub pusta
        ui->label_10->setText( "Nieprawi³owa wartoœæ." );
    else                                                                        //aktualizacja ok
    {
        ui->label_10->setText( QString() );
        towarySS[idxTowaru].cena = ui->lineEdit->text().toFloat();
        db.uaktualnij( towarySS[idxTowaru] );
        pobierzTowary();
        ui->label_10->setText( "Uaktualniono." );
    }
}

void Magazynier::on_pushButton_4_clicked()      //usun towar
{
    db.usunRekord( &towarySS[idxTowaru] );
    ui->label_10->setText( QString() );
    pobierzTowary();
    ui->label_11->setText( "Usuniêto." );
}
