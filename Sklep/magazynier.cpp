#include "magazynier.h"
#include "ui_magazynier.h"

Magazynier::Magazynier(QWidget *parent, DBProxy &dbproxy, DBProxy &dbproxy2, int pId) :
    QDialog(parent),
    ui(new Ui::Magazynier),
    db( dbproxy ),
    dbH( dbproxy2 ),
    pracownikId( pId )
{

    ui->setupUi(this);
    dbH.polacz();
    dane();

    upust = sklep->upust;
    ui->lineEdit_2->setText( DBProxy::liczbaNaString( upust ).append("%") );

    towaryH = dbH.pobierz< TowarHurtownia >();
    zamowieniaH = dbH.pobierz< ZamowienieHurtownia >();
    towarySS = db.pobierz< TowarSklep >();
    foreach( Kategoria kat, dbH.pobierz< Kategoria >() )
        ui->comboBoxFiltr->addItem(kat.nazwa, 0);
    foreach( Kategoria kat, db.pobierz< Kategoria >() )
        ui->comboBoxFiltr_3->addItem(kat.nazwa, 0);

    pobierzDane( towaryH );
    pobierzZamowienia( zamowieniaH );
    pobierzTowary( towarySS );    

    ograniczeniaZnakow();
    setWindowTitle( "Modu³ magazyniera." );
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

void Magazynier::ograniczeniaZnakow()      //ograniczenia dla lineedit'ow
{
    ui->plainTextEdit->setReadOnly( true );
    ui->lineEdit->setMaxLength( 7 );
}

void Magazynier::dane()      //inicjuje pewne dane
{
    login = dbH.getLogin();
    FiltrSklep filtrS;
    FiltrHurtownia filtrH;

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

void Magazynier::pobierzDane( QList<TowarHurtownia> tH )      //wyswietla towary hurtowni(tylko te, ktore moga trafic do zamowienia)
{    
    ui->labelRazemWybrane_2->setReadOnly( true );


    QList< TowarSklep > towaryWykluczone = zwrocWykluczone();
    FiltrTowarHurtownia filtr;
    foreach( TowarSklep t, towaryWykluczone)
    {
        filtr.insert( TowarHurtownia::Nazwa, DBProxy::Filtr( t.nazwa, DBProxy::NieRowne ) );
    }

    //towaryH = dbH.pobierz< TowarHurtownia >( filtr );  //zfiltrowane towary; tylko te, ktore sklep ma w maksymalnie jednej pozycj
    model.clear();
    for (int i = 0; i < tH.size(); i++) {        
        model.setItem( i, 0, new QStandardItem( dbH.pobierz< Kategoria >(Kategoria::Id, Filtr(tH[i].idKategorii ) ).first().nazwa ) );
        model.setItem( i, 1, new QStandardItem( tH[i].nazwa ) );
        model.setItem( i, 2, new QStandardItem( tH[i].opis ) );
        model.setItem( i, 3, new QStandardItem( QString::number( tH[i].vat ) + "%" ) );
        model.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( tH[i].ilosc ) ) );
        model.setItem( i, 5, new QStandardItem( DBProxy::liczbaNaString( tH[i].cena ) ) );
        model.setItem( i, 6, new QStandardItem( DBProxy::liczbaNaString( tH[i].id ) ) );
    }

    model.setHeaderData( 0, Qt::Horizontal, "Kategoria" );
    model.setHeaderData( 1, Qt::Horizontal, "Nazwa" );
    model.setHeaderData( 2, Qt::Horizontal, "Opis" );
    model.setHeaderData( 3, Qt::Horizontal, "VAT" );
    model.setHeaderData( 4, Qt::Horizontal, "Iloœæ" );
    model.setHeaderData( 5, Qt::Horizontal, "Cena" );

    ui->tableView->setModel( &model );
    ui->tableView->setColumnWidth( 0, 70 );
    ui->tableView->setColumnWidth( 1, 115 );
    ui->tableView->setColumnWidth( 2, 140 );
    ui->tableView->setColumnWidth( 3, 50 );
    ui->tableView->setColumnWidth( 4, 50 );
    ui->tableView->setColumnWidth( 5, 50 );
    ui->tableView->setEditTriggers( QAbstractItemView::NoEditTriggers);

}

void Magazynier::on_tableView_clicked(QModelIndex index)    //po kliknieciu w towar...
{
    int idx = index.row();
    ui->tableView->selectRow( idx );
    
    int id = model.item( ui->tableView->currentIndex().row(), 6)->text().toInt();
    TowarHurtownia t = dbH.pobierz< TowarHurtownia >( TowarHurtownia::Id, Filtr( id ) ).first();

    if ( t.ilosc == 0 ){
        ui->spinBox->setDisabled( true );
        ui->labelCzyDostepny->setText( "TOWAR NIEDOSTÊPNY" );
        ui->buttonDodaj->setDisabled( true );
    }
    else{
        ui->buttonDodaj->setEnabled( true );
        ui->labelCzyDostepny->setText( "" );
        ui->spinBox->setEnabled( true );
        ui->spinBox->setValue( 1 );
        ui->spinBox->setMaximum( t.ilosc );
    }

    ui->labelNazwa->setText( t.nazwa );
    ui->plainTextEdit->setPlainText( t.opis );
    ui->labelCena->setText( QString::number( t.cena - t.cena * (upust/100), 'f', 2 ) );
    ui->labelRazem->setText( QString::number( t.cena - t.cena * (upust/100), 'f', 2 ) );
}

void Magazynier::on_spinBox_valueChanged(int )
{
    float razem = ui->labelCena->text().toFloat() * ui->spinBox->value();
    ui->labelRazem->setText( QString::number(  razem, 'f', 2 ) );
}

void Magazynier::wyswietlWybraneTowary(){  //wybrane towary

    model_2.setItem( wybraneTowaryH.size()-1, 0, new QStandardItem( wybraneTowaryH.last().nazwa ) );
    model_2.setItem( wybraneTowaryH.size()-1, 1, new QStandardItem( wybraneTowaryH.last().opis ) );
    model_2.setItem( wybraneTowaryH.size()-1, 2, new QStandardItem( DBProxy::liczbaNaString( wybraneTowaryH.last().ilosc ) ) );
    model_2.setItem( wybraneTowaryH.size()-1, 3, new QStandardItem( ui->labelRazem->text() ) );

    model_2.setHeaderData( 0, Qt::Horizontal, tr( "Nazwa" ) );
    model_2.setHeaderData( 1, Qt::Horizontal, tr( "Opis" ) );
    model_2.setHeaderData( 2, Qt::Horizontal,  "Iloœæ" );
    model_2.setHeaderData( 3, Qt::Horizontal, tr( "Razem" ) );

    ui->widokWybraneTowary_2->setModel( &model_2 );
    ui->widokWybraneTowary_2->setColumnWidth( 0, 105 );
    ui->widokWybraneTowary_2->setColumnWidth( 1, 150 );
    ui->widokWybraneTowary_2->setColumnWidth( 2, 70 );
    ui->widokWybraneTowary_2->setColumnWidth( 3, 50 );
    ui->widokWybraneTowary_2->setEditTriggers( QAbstractItemView::NoEditTriggers);
}

QString Magazynier::razemWybrane(){
    float razem = 0;
//    foreach( DBProxy::TowarHurtownia towar, wybraneTowaryH){
//        razem += ( towar.cena - towar.cena * (upust/100) ) * towar.ilosc;
//    }
    razem = ui->labelRazem->text().toFloat() + ui->labelRazemWybrane_2->text().toFloat();
    return QString::number( razem, 'f', 2 );
}

void Magazynier::on_buttonDodaj_clicked()       //dodawanie do listy
{
    if ( ui->labelNazwa->text() == "")
        QMessageBox::warning( this, "!", "Najpierw zaznacz towar do dodania.", QMessageBox::Ok);
    else
    {

        int idx = model.item( ui->tableView->currentIndex().row(), 6)->text().toInt();
        TowarHurtownia t = dbH.pobierz< TowarHurtownia >( TowarHurtownia::Id, Filtr( idx ) ).first();

        bool czyTowarWybrany = false;

        foreach( DBProxy::TowarHurtownia towar, wybraneTowaryH){
            if ( towar.id == t.id ){
                czyTowarWybrany = true;
                break;
            }
        }

        if ( czyTowarWybrany )
            QMessageBox::information(  this, "!", "Towar znajdujê siê ju¿ na liœcie wybranych towarów.", QMessageBox::Ok );
        else{
            wybraneTowaryH.append( t );
            wybraneTowaryH.last().ilosc = ui->spinBox->value();
            //wybraneTowaryH.last().cena = zaokraglij( zaokraglij( wybraneTowaryH.last().cena) -  zaokraglij( wybraneTowaryH.last().cena ) * (upust/100) );
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

float Magazynier::zaokraglij(float liczba)
{
    return QString::number(liczba, 'f', 2).toFloat();
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
            QString razem = DBProxy::liczbaNaString( zaokraglij( ( ui->labelRazemWybrane_2->text() ).toFloat() - ( zaokraglij( wybraneTowaryH.at(ind).cena ) - zaokraglij( zaokraglij( wybraneTowaryH.at(ind).cena ) * (upust/100) ) ) * wybraneTowaryH.at(ind).ilosc) );
            ui->labelRazemWybrane_2->setText( razem );
            if( ui->labelRazemWybrane_2->text().toFloat() < 0.01 ) ui->labelRazemWybrane_2->setText( "0" );
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

        zH.upust = upust;
        dbH.uaktualnij( zH );
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

        pobierzZamowienia( dbH.pobierz< ZamowienieHurtownia >() ); //odswieza liste w drugim tabie
        // uaktualnij()  //uaktualnia ilosc towarow
    }
}

void Magazynier::on_buttonSzukaj_clicked()
{
    QList< TowarHurtownia > lista;
    lista.clear();
    QString pozycja, wzorzec = ui->lineEditSzukaj->text();

    if ( ui->comboBoxSzukanie->currentText() == "Nazwa" ){
        foreach( TowarHurtownia towar, towaryH ){
            pozycja = towar.nazwa;
            if ( pozycja.contains( wzorzec, Qt::CaseInsensitive ) ){
                lista.append( towar );
            }
        }
    }

    else{
        foreach( TowarHurtownia towar, towaryH ){
            pozycja = towar.opis;
            if ( pozycja.contains( wzorzec, Qt::CaseInsensitive ) ){
                lista.append( towar );
            }
        }
    }

    pobierzDane( lista );
}

void Magazynier::on_buttonSortMalejaco_clicked()
{
    ui->tableView->sortByColumn( ui->comboBoxSort->currentIndex(), Qt::AscendingOrder );
}

void Magazynier::on_buttonSortRosnaco_clicked()
{
    ui->tableView->sortByColumn( ui->comboBoxSort->currentIndex(), Qt::DescendingOrder );
}

void Magazynier::on_buttonFiltrKat_clicked()
{
    QList< TowarHurtownia >lista;
    foreach( TowarHurtownia towar, towaryH ){
        if ( towar.idKategorii == ui->comboBoxFiltr->currentIndex() + 1 ){
            lista.append( towar );
        }
    }

    pobierzDane( lista );
}

void Magazynier::on_buttonFiltrCena_clicked()
{
    QList< TowarHurtownia >lista;
    foreach( TowarHurtownia towar, towaryH )
    {
        float cena =  towar.cena;
        if ( ( cena >= ui->doubleSpinBoxOd->value() ) && ( cena <= ui->doubleSpinBoxDo->value() ) ){
            lista.append( towar );
        }
    }

    pobierzDane( lista );
}

void Magazynier::on_buttonPokazWszystkich_clicked()
{
    pobierzDane( towaryH );
}




















//###########
//Zarzadzanie zamowieniami
//###########
 void Magazynier::pobierzZamowienia( QList< ZamowienieHurtownia >  zH)       //lista zamowien
 {
     model_3.clear();
     for (int i = 0; i < zH.size(); i++) {
         model_3.setItem( i, 0, new QStandardItem( DBProxy::liczbaNaString( zH[i].id ) ) );
         model_3.setItem( i, 1, new QStandardItem( zH[i].nrFaktury ) );
         model_3.setItem( i, 2, new QStandardItem( DBProxy::dataNaString( zH[i].dataZlozenia ) ) );
         model_3.setItem( i, 3, new QStandardItem( DBProxy::dataNaString( zH[i].dataRealizacji ) ) );
         model_3.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( zH[i].upust ) ) );
         model_3.setItem( i, 5, new QStandardItem( DBProxy::statusNaString( zH[i].status ) ) );
     }

     model_3.setHeaderData( 0, Qt::Horizontal, "Id" );
     model_3.setHeaderData( 1, Qt::Horizontal, "Nr faktury" );
     model_3.setHeaderData( 2, Qt::Horizontal, "Data z³o¿enia" );
     model_3.setHeaderData( 3, Qt::Horizontal, "Data realizacji" );
     model_3.setHeaderData( 4, Qt::Horizontal, "Upust" );
     model_3.setHeaderData( 5, Qt::Horizontal, "Status" );

     ui->tableView_2->setModel( &model_3 );
     ui->tableView_2->setColumnWidth( 0, 50 );
     ui->tableView_2->setColumnWidth( 1, 90 );
     ui->tableView_2->setColumnWidth( 2, 100 );
     ui->tableView_2->setColumnWidth( 3, 100 );
     ui->tableView_2->setColumnWidth( 4, 50 );
     ui->tableView_2->setColumnWidth( 5, 85 );
     ui->tableView_2->setEditTriggers( QAbstractItemView::NoEditTriggers);

     ui->groupBox_5->setDisabled( true );
     ui->groupBox_8->setEnabled( true );
 }

 void Magazynier::on_tableView_2_clicked(QModelIndex index)    //po kliknieciu w zamowienie...
 {
    int idx = index.row();
    ui->tableView_2->selectRow( idx );
    ui->label->setWordWrap( true );
    zamowieniaH = dbH.pobierz< ZamowienieHurtownia >();


    int id = model_3.item( ui->tableView_2->currentIndex().row(), 0)->text().toInt();
    ZamowienieHurtownia z = dbH.pobierz< ZamowienieHurtownia >( ZamowienieHurtownia::Id, Filtr( id ) ).first();


    if ( z.status == DBProxy::Oczekujace ){
        ui->label->setText( "Zamówienie z³o¿one. <br />Czekaj na reakcjê Hurtowni." );
        ui->groupBox_5->setDisabled( true );
    }
    else if( z.status == DBProxy::Anulowane ){
        ui->label->setText( "Zamówienie anulowane przez Hurtowniê." );
        ui->groupBox_5->setDisabled( true );
    }
    else if( z.status == DBProxy::DoRealizacji ){
        ui->label->setText( "Po odebraniu towaru, zrealizuj je." );
        ui->groupBox_5->setEnabled( true );
    }
    else if( z.status == DBProxy::Zrealizowane ){
        ui->label->setText( "Zamówienie zrealizowane" );
        ui->groupBox_5->setDisabled( true );
    }

    int i = model_3.item( ui->tableView_2->currentIndex().row(), 0)->text().toInt();
    zzz.clear();
    zzz.append(  dbH.pobierz< ZamowienieHurtownia >( ZamowienieHurtownia::Id, Filtr( i ) ).first() );

    zamowienieH = &zzz.first();
    qDebug() << zamowienieH->nrFaktury;

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

    FiltrPozycjaZamowienia pf;              //filtr do znajdywania ilosci towaru
    FiltrKategoria kf;              //filtr do znajdywania ilosci towaru
    QString nkat;                     //nazwa kategorii towaru
    int katId;
    foreach( TowarHurtownia tH, towaryHZ)       //lista towarow z zamowienia
    {
        pf.insert( DBProxy::PozycjaZamowienia::IdZamowienia, DBProxy::Filtr( zamowienieH->id, DBProxy::Rowne ) );
        pf.insert( DBProxy::PozycjaZamowienia::IdTowaru, DBProxy::Filtr( tH.id, DBProxy::Rowne ) );

        katId = tH.idKategorii;
        nkat = dbH.pobierz< Kategoria >( Kategoria::Id, Filtr( tH.idKategorii ) ).first().nazwa;
        Kategoria kat( nkat );
        if( db.pobierz< Kategoria >( Kategoria::Nazwa, Filtr( nkat ) ).isEmpty() ) //jesli nie ma odpowiedniej kategorii w sklepie
           katId = db.dodaj( kat );                            //to jest tworzona i zwracane jest id
        else
           katId = db.pobierz< Kategoria >( Kategoria::Nazwa, Filtr( nkat ) ).first().id;


        DBProxy::TowarSklep tS( tH.nazwa,
                                tH.opis,
                                dbH.pobierz< PozycjaZamowienia >( pf ).first().ilosc,
                                tH.cena,
                                tH.vat,
                                zaokraglij( tH.cena - tH.cena * (upust/100) ),
                                katId);
        towaryS.append( tS );       
        pf.clear();
    }

    for (int i = 0; i < towaryS.length(); i++) {                  //blok ustawia tabele
        model_4.setItem( i, 0, new QStandardItem( towaryS[i].nazwa ) );
        model_4.setItem( i, 1, new QStandardItem( towaryS[i].opis ) );
        model_4.setItem( i, 2, new QStandardItem( QString::number( towaryS[i].vat ) + "%"  ) );
        model_4.setItem( i, 3, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].ilosc ) ) );
        model_4.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].cenaZakupu ) ) );
        model_4.setItem( i, 5, new QStandardItem( DBProxy::liczbaNaString( towaryS[i].cenaZakupu * towaryS[i].ilosc) ) );
    }
    model_4.setHeaderData( 0, Qt::Horizontal, tr( "Nazwa" ) );
    model_4.setHeaderData( 1, Qt::Horizontal, tr( "Opis" ) );
    model_4.setHeaderData( 2, Qt::Horizontal, tr( "VAT" ) );
    model_4.setHeaderData( 3, Qt::Horizontal, "Iloœæ" );
    model_4.setHeaderData( 4, Qt::Horizontal, tr( "Cena zakupu" ) );
    model_4.setHeaderData( 5, Qt::Horizontal, "Wartoœæ zam." );
    ui->tableView_3->setModel( &model_4 );
    ui->tableView_3->setColumnWidth( 0, 90 );
    ui->tableView_3->setColumnWidth( 1, 130 );
    ui->tableView_3->setColumnWidth( 2, 50 );
    ui->tableView_3->setColumnWidth( 3, 50 );
    ui->tableView_3->setColumnWidth( 4, 75 );
    ui->tableView_3->setColumnWidth( 5, 80 );
    ui->tableView_3->setEditTriggers( QAbstractItemView::NoEditTriggers);

    float suma = 0;                     //obliczenie kosztu zamowienia
    foreach( TowarSklep t, towaryS)
    {
        suma += t.cenaZakupu * t.ilosc;
    }
    ui->lineEdit_3->setText( DBProxy::liczbaNaString( suma ).append( " z³" ));
    ui->lineEdit_3->setReadOnly( true );


    qDebug() << "heh      "<<zamowienieH->nrFaktury;
 }



void Magazynier::on_pushButton_2_clicked()          //realizacja
{
    QList< TowarSklep > towaryTS;                   //stara lista towarow sklepu
    towaryTS = db.pobierz< TowarSklep >();
    QListIterator< TowarSklep > itTS( towaryTS );   // iterator starych towarow

    qDebug() << "heh      "<<zamowienieH->nrFaktury;

    foreach ( TowarSklep tS, towaryS)               //dodawanie towarow do bazy sklepu
    {
        if( !towaryTS.isEmpty() )                        //jesli sa stare towary
        {            
            stareH = db.pobierz<TowarSklep>( TowarSklep::Nazwa, Filtr( tS.nazwa ) );
            QListIterator< TowarSklep > itS( stareH );
            if( !stareH.isEmpty() )                 //jesli sa juz takie towary
            {
                int q = 0;
                while ( itS.hasNext() )
                {
                    TowarSklep staryT = itS.next();

                    if( tS.cena == staryT.cena )
                    {
                        staryT.ilosc += tS.ilosc;
                        db.uaktualnij( staryT );
                        q = 1;
                        break;
                    }                    
                }
                if(q == 0)                  //taka sama nazwa; cena inna niz starych towarow
                    db.dodaj( tS );
                stareH.clear();
            }
            else
                db.dodaj( tS );            
        }
        else{            
            db.dodaj( tS );
        }
    }

    //zamowienieH->status = DBProxy::Zrealizowane;        //zmiana statusu w hurtowni

    zamowienieH->dataRealizacji = QDate::currentDate(); //ustawianie daty w hurtowni
    dbH.uaktualnij( *zamowienieH );

    ZamowienieSklep zamowienieS = db.pobierz< ZamowienieSklep >( ZamowienieSklep::NrFaktury, Filtr( zamowienieH->nrFaktury ) ).first();
    //zamowienieS.status = DBProxy::Zrealizowane;
    zamowienieS.dataRealizacji = QDate::currentDate();
    db.uaktualnij( zamowienieS );
    pobierzZamowienia( zamowieniaH );        //odswiezanie listy zamowien
    pobierzTowary( db.pobierz<TowarSklep>() );        //odswiezanie listy towarow w tab 3
}


void Magazynier::on_buttonFiltrKat_2_clicked()
{
    if ( ui->comboBoxFiltr_2->currentText() != "Wszystkie" )
    {
        QList< ZamowienieHurtownia >lista;
        foreach( ZamowienieHurtownia zam, zamowieniaH ){

            if ( DBProxy::statusNaString( zam.status ) == ui->comboBoxFiltr_2->currentText() ){
                lista.append( zam );
            }
        }
        pobierzZamowienia( lista );
    }
    else
         pobierzZamowienia( zamowieniaH );
}





//###########
//Zarzadzanie towarami
//###########

 void Magazynier::pobierzTowary( QList< TowarSklep > tSS )       //lista towarow
 {    
    model_5.clear();
    for (int i = 0; i < tSS.length(); i++) {
        model_5.setItem( i, 0, new QStandardItem( DBProxy::liczbaNaString( tSS[i].id ) ) );
        model_5.setItem( i, 1, new QStandardItem( db.pobierz< Kategoria >(Kategoria::Id, Filtr(tSS[i].idKategorii ) ).first().nazwa ) );
        model_5.setItem( i, 2, new QStandardItem( tSS[i].nazwa ) );
        model_5.setItem( i, 3, new QStandardItem( tSS[i].opis ) );
        model_5.setItem( i, 4, new QStandardItem( DBProxy::liczbaNaString( tSS[i].cenaZakupu ) ) );
        model_5.setItem( i, 5, new QStandardItem( DBProxy::liczbaNaString( tSS[i].cena ) ) );
        model_5.setItem( i, 6, new QStandardItem( QString::number( tSS[i].vat ) + "%"  ) );
        model_5.setItem( i, 7, new QStandardItem( DBProxy::liczbaNaString( tSS[i].ilosc ) ) );
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
    ui->tableView_4->setColumnWidth( 3, 115 );
    ui->tableView_4->setColumnWidth( 4, 80 );
    ui->tableView_4->setColumnWidth( 5, 40 );
    ui->tableView_4->setColumnWidth( 6, 35 );
    ui->tableView_4->setColumnWidth( 7, 40 );
    ui->tableView_4->setEditTriggers( QAbstractItemView::NoEditTriggers);

    ui->label_10->setText( QString() );
    ui->label_11->setText( QString() );
    ui->pushButton_4->setDisabled( true );
 }

void Magazynier::on_tableView_4_clicked(QModelIndex index)    //po kliknieciu w towar...
{
    ui->groupBox_8->setEnabled( true );
    ui->label_10->setText( QString() );

    idxTowaru = index.row();
    ui->tableView_4->selectRow( idxTowaru );

    int id = model_5.item( ui->tableView_4->currentIndex().row(), 0)->text().toInt();
    TowarSklep t = db.pobierz< TowarSklep >( TowarSklep::Id, Filtr( id ) ).first();

    ui->label_13->setText( t.nazwa );
    ui->lineEdit->setText( DBProxy::liczbaNaString( t.cena ) );

    if( t.ilosc == 0 ) //enable button usuniecia towaru
        ui->pushButton_4->setEnabled( true );
}

void Magazynier::on_pushButton_3_clicked()      //aktualizuj
{
    int id = model_5.item( ui->tableView_4->currentIndex().row(), 0)->text().toInt();
    TowarSklep t = db.pobierz< TowarSklep >( TowarSklep::Id, Filtr( id ) ).first();

    if( ui->label_13->text().isNull() )                                        //jesli nie wybrano towaru
        ui->label_10->setText( "Nie wybrano towaru." );
    else if( ui->lineEdit->text().toFloat() <= 0 || ui->lineEdit->text().isEmpty() )  //jesli wartosc <= zero lub pusta
        ui->label_10->setText( "Nieprawi³owa wartoœæ." );
    else                                                                        //aktualizacja ok
    {
        ui->label_10->setText( QString() );
        t.cena = ui->lineEdit->text().toFloat();
        db.uaktualnij( t );
        pobierzTowary( towarySS );
        ui->label_10->setText( "Uaktualniono." );
    }
}

void Magazynier::on_pushButton_4_clicked()      //usun towar
{
    int id = model_5.item( ui->tableView_4->currentIndex().row(), 0)->text().toInt();
    TowarSklep t = db.pobierz< TowarSklep >( TowarSklep::Id, Filtr( id ) ).first();

    db.usunRekord( &t );
    ui->label_10->setText( QString() );
    model_5.clear();
    ui->tableView_4->setModel( &model_5 );
    ui->label_13->clear();
    pobierzTowary( towarySS );
    ui->label_11->setText( "Usuniêto." );
}

void Magazynier::on_buttonSzukaj_2_clicked()
{
    QList< TowarSklep > lista;
    lista.clear();
    QString pozycja, wzorzec = ui->lineEditSzukaj_2->text();

    if ( ui->comboBoxSzukanie_2->currentText() == "Nazwa" ){
        foreach( TowarSklep towar, towarySS ){
            pozycja = towar.nazwa;
            if ( pozycja.contains( wzorzec, Qt::CaseInsensitive ) ){
                lista.append( towar );
            }
        }
    }
    else{
        foreach( TowarSklep towar, towarySS ){
            pozycja = towar.opis;
            if ( pozycja.contains( wzorzec, Qt::CaseInsensitive ) ){
                lista.append( towar );
            }
        }
    }

    pobierzTowary( lista );
}

void Magazynier::on_buttonSortMalejaco_2_clicked()
{
    ui->tableView_4->sortByColumn( ui->comboBoxSort_2->currentIndex(), Qt::AscendingOrder );
}

void Magazynier::on_buttonSortRosnaco_2_clicked()
{
    ui->tableView_4->sortByColumn( ui->comboBoxSort_2->currentIndex(), Qt::DescendingOrder );
}

void Magazynier::on_buttonFiltrKat_3_clicked()
{
    QList< TowarSklep >lista;
    Kategoria k = db.pobierz< Kategoria >( Kategoria::Nazwa, Filtr( ui->comboBoxFiltr_3->currentText() ) ).first();
    qDebug() << k.nazwa;
    lista = db.pobierz< TowarSklep >( DBProxy::TowarSklep::IdKategorii, Filtr( k.id ) );

    pobierzTowary( lista );
}

void Magazynier::on_buttonFiltrCena_2_clicked()
{
    QList< TowarSklep >lista;
    foreach( TowarSklep towar, towarySS )
    {
        float cena =  towar.cena;
        if ( ( cena >= ui->doubleSpinBoxOd_2->value() ) && ( cena <= ui->doubleSpinBoxDo_2->value() ) ){
            lista.append( towar );
        }
    }

    pobierzTowary( lista );
}

void Magazynier::on_buttonPokazWszystkich_2_clicked()
{
    pobierzTowary( towarySS );
}




void Magazynier::on_pushButton_5_clicked()      //odswiez liste
{
    towaryH = dbH.pobierz< TowarHurtownia >();
    zamowieniaH = dbH.pobierz< ZamowienieHurtownia >();
    towarySS = db.pobierz< TowarSklep >();
    pobierzDane( towaryH );
    pobierzZamowienia( zamowieniaH );
    pobierzTowary( towarySS );

    ui->labelNazwa->clear();
    ui->plainTextEdit->clear();
    ui->labelCena->clear();
    ui->labelRazem->clear();
    ui->labelCzyDostepny->clear();

    ui->comboBoxFiltr_2->setCurrentIndex(0);
    ui->label->clear();
    model_4.clear();
    ui->tableView_3->setModel( &model_4 );
    ui->lineEdit_3->clear();
    ui->groupBox_5->setDisabled( true );

    ui->label_13->clear();
    ui->lineEdit->clear();
    ui->label_10->clear();
    ui->label_11->clear();
}
