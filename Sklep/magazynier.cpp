#include "magazynier.h"
#include "ui_magazynier.h"

Magazynier::Magazynier(QWidget *parent, DBProxy &dbproxy, DBProxy &dbproxy2) :
    QDialog(parent),
    ui(new Ui::Magazynier),
    db( dbproxy ),
    dbH( dbproxy2 )
{
    ui->setupUi(this);

    dbH.polacz();

    pobierzDane();
    pobierzZamowienia();
}

Magazynier::~Magazynier()
{
    delete ui;
    delete pz;
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


void Magazynier::pobierzDane()      //wyswietla towary hurtowni
{
    //QMultiMap< DBProxy::Sklep::PoleBazy, DBProxy::Filtr > filtr;
    //filtr.insert( DBProxy::Sklep::Login, DBProxy::Filtr( hurtowniaLogin, DBProxy::Rowne ) );
    sklep = dbH.pobierz< DBProxy::Sklep >();

    upust = sklep.first().upust/100;
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
    model.setHeaderData( 4, Qt::Horizontal, "Iloœæ" );
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
            QMessageBox::information(  this, "!", "Towar znajdujê siê ju¿ na liœcie wybranych towarów.", QMessageBox::Ok );
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
        ZamowienieHurtownia zh( sklep.first().id, QDate::currentDate(), "" );
        dbH.dodaj( zh );

        for(int i=0; i<wybraneTowaryH.length(); i++)
        {
            PozycjaZamowienia pz( wybraneTowaryH[i].id, wybraneTowaryH[i].ilosc, dbH.pobierz< ZamowienieHurtownia >().last().id );
            dbH.dodaj( pz );
        }

        ui->label_2->setWordWrap( true );
        ui->label_2->setText( "Zamówienie zosta³o z³o¿one. <br /> Status realizacji zamówienia spradzisz w drugim tabie." );

        model_2.clear();            //czyszczenie listy
        wybraneTowaryH.clear();
        ui->labelRazemWybrane_2->setText( "0" );
        ui->widokWybraneTowary_2->setModel( &model_2 );
    }

    pobierzZamowienia(); //odswieza liste w drugim tabie
    // uaktualnij()  //uaktualnia ilosc towarow
}






//###########
//aktualizacja bazy sklepu
//###########
 void Magazynier::pobierzZamowienia()       //lista zamowien
 {
     zamowieniaH = dbH.pobierz< DBProxy::ZamowienieHurtownia >();

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
     ui->tableView_2->setColumnWidth( 2, 80 );
     ui->tableView_2->setColumnWidth( 3, 80 );
     ui->tableView_2->setColumnWidth( 4, 80 );
     ui->tableView_2->setColumnWidth( 5, 80 );

     ui->groupBox_5->setDisabled( true );
 }

 void Magazynier::on_tableView_2_clicked(QModelIndex index)    //po kliknieciu w zamowienie...
 {

    int idx = index.row();
    ui->tableView_2->selectRow( idx );
    ui->label->setWordWrap( true );

    if ( zamowieniaH[idx].status == DBProxy::Oczekujace ){
        ui->label->setText( "Zamówienie z³o¿one. <br />Czekaj na reakcjê Hurtowni." );
    }
    else if( zamowieniaH[idx].status == DBProxy::Anulowane ){
        ui->label->setText( "Zamówienie anulowane przez Hurtowniê." );
    }
    else if( zamowieniaH[idx].status == DBProxy::Zrealizowane ){
        ui->label->setText( "Po odebraniu towaru, zaktualizuj go w bazie sklepu" );
        ui->groupBox_5->setEnabled( true );
        zamowienieH = zamowieniaH[idx];
    }

 }

void Magazynier::on_pushButton_2_clicked()      //aktualizacja cen
{
    //QMultiMap< DBProxy::TowarHurtownia::PoleBazy, DBProxy::Filtr > filtr;
    //filtr.insert( DBProxy::TowarHurtownia::Id, DBProxy::Filtr( zamowieniaH[idx].id , DBProxy::Rowne ) );
 /*/
    int idZamowienia = zamowienieH[0].id;
    qDebug()<<idZamowienia; /*/
    //towaryHA = (dbH.pobierz< ZamowienieHurtownia >()).;
    //towaryS = dbH.pobierz< TowarSklep >();
   // for(int i=0; i< )
}
