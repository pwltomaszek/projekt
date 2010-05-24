#ifndef DBPROXY_H
#define DBPROXY_H

#include <QtSql>

#include <QObject>

class DBProxy : public QObject
{
    Q_OBJECT
public:
    // klasy i enumeracje pomocnicze

    enum StawkaVAT {
        VAT0,
        VAT3 = 3,
        VAT7 = 7,
        VAT14 = 14,
        VAT22 = 22,
        VATBlad
    };

    enum StatusZamowienia {
        Oczekujace,
        Anulowane,
        DoRealizacji,
        Zrealizowane,
        StatusBlad
    };

    enum Posada {
        Kierownik,
        Sprzedawca,
        Magazynier,
        PosadaBlad
    };

    enum Potwierdzenie {
        PotwierdzenieParagon,
        PotwierdzenieFaktura,
        PotwierdzenieBlad
    };

    enum Relacja {
        Rowne, NieRowne, Wieksze, WiekszeRowne, Mniejsze, MniejszeRowne, Zawiera
    };

    enum Dzialanie {
        AND, OR
    };

    struct Filtr {
        Filtr( const QVariant &wartosc, Relacja relacja = Rowne ) {
            this->wartosc = wartosc;
            this->relacja = relacja;
        }

        Relacja relacja;
        QVariant wartosc;
    };

    struct Rekord {
    protected:
        Rekord( const QString &tabela, unsigned int id = 0 )
        {
            this->id = id;
            this->tabela = tabela;
        }

    public:
        unsigned int id;

        QString tabela;

        static QStringList polaEnum;
        static QStringList polaUInt;
        static QStringList polaFloat;
        static QStringList polaQDate;
    };

    struct HurtowniaProto {
    protected:
        HurtowniaProto( const QString &nazwa, const QString &regon, const QString &ulica, const QString &miejscowosc,
                   const QString &kodPocztowy, const QString &telefon, const QString &fax, const QString &email,
                   const QString &login, const QString &haslo, float upust = 0 )
        {
            this->nazwa = nazwa;
            this->REGON = regon;
            this->ulica = ulica;
            this->miejscowosc = miejscowosc;
            this->kodPocztowy = kodPocztowy;
            this->telefon = telefon;
            this->fax = fax;
            this->email = email;
            this->upust = upust;
            this->login = login;
            this->haslo = haslo;
        }

        HurtowniaProto() {}

    public:
        QString nazwa, REGON, ulica, miejscowosc, kodPocztowy, telefon, fax, email, login, haslo;
        float upust;
    };

    struct Hurtownia : public HurtowniaProto, Rekord {
        Hurtownia( const QString &nazwa, const QString &regon, const QString &ulica, const QString &miejscowosc,
                   const QString &kodPocztowy, const QString &telefon, const QString &fax, const QString &email,
                   const QString &login, const QString &haslo, const QString &host,
                   float upust = 0, unsigned int id = 0 )
                       : HurtowniaProto( nazwa, regon, ulica, miejscowosc, kodPocztowy, telefon,
                                         fax, email, login, haslo, upust ),
                         Rekord( "Hurtownia", id )
        {
            this->host = host;
        }

        Hurtownia( const QSqlQuery &query )
            : Rekord( "Hurtownia", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
            REGON = query.value( polaBazy.indexOf( "regon" ) ).toString();
            ulica = query.value( polaBazy.indexOf( "ulica" ) ).toString();
            miejscowosc = query.value( polaBazy.indexOf( "miejscowosc" ) ).toString();
            kodPocztowy = query.value( polaBazy.indexOf( "kodPocztowy" ) ).toString();
            telefon = query.value( polaBazy.indexOf( "telefon" ) ).toString();
            fax = query.value( polaBazy.indexOf( "fax" ) ).toString();
            email = query.value( polaBazy.indexOf( "email" ) ).toString();
            upust = query.value( polaBazy.indexOf( "upust" ) ).toFloat();
            login = query.value( polaBazy.indexOf( "login" ) ).toString();
            haslo = query.value( polaBazy.indexOf( "haslo" ) ).toString();
            host = query.value( polaBazy.indexOf( "host" ) ).toString();
            id = query.value( polaBazy.indexOf( "id" ) ).toUInt();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12" )
                    .arg( nawiasy( REGON ) )
                    .arg( nawiasy( nazwa ) )
                    .arg( liczbaNaString( upust ) )
                    .arg( nawiasy( ulica ) )
                    .arg( nawiasy( miejscowosc ) )
                    .arg( nawiasy( kodPocztowy ) )
                    .arg( nawiasy( telefon ) )
                    .arg( nawiasy( fax ) )
                    .arg( nawiasy( email ) )
                    .arg( nawiasy( login ) )
                    .arg( nawiasy( haslo ) )
                    .arg( nawiasy( host ) );
        }

        QString host;

        static QString tabela;
        static QStringList polaBazy;

        enum PoleBazy {
            Id, Regon, Nazwa, Upust, Ulica, Miejscowosc, KodPocztowy, Telefon, Fax, Email,
            Login, Haslo, Host
        };
    };

    struct Sklep : public HurtowniaProto, Rekord {
        Sklep( const QString &nazwa, const QString &regon, const QString &ulica,
               const QString &miejscowosc, const QString &kodPocztowy, const QString &telefon,
               const QString &fax, const QString &email, const QString &login,
               const QString &haslo, float upust = 0, unsigned int id = 0 )
                   : HurtowniaProto( nazwa, regon, ulica, miejscowosc, kodPocztowy, telefon, fax,
                                     email, login, haslo, upust ),
                     Rekord( "Sklep", id )
        {}

        Sklep( const QSqlQuery &query )
            : Rekord( "Sklep", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
            REGON = query.value( polaBazy.indexOf( "regon" ) ).toString();
            ulica = query.value( polaBazy.indexOf( "ulica" ) ).toString();
            miejscowosc = query.value( polaBazy.indexOf( "miejscowosc" ) ).toString();
            kodPocztowy = query.value( polaBazy.indexOf( "kodPocztowy" ) ).toString();
            telefon = query.value( polaBazy.indexOf( "telefon" ) ).toString();
            fax = query.value( polaBazy.indexOf( "fax" ) ).toString();
            email = query.value( polaBazy.indexOf( "email" ) ).toString();
            upust = query.value( polaBazy.indexOf( "upust" ) ).toFloat();
            id = query.value( polaBazy.indexOf( "id" ) ).toUInt();
            login = query.value( polaBazy.indexOf( "login" ) ).toString();
            haslo = query.value( polaBazy.indexOf( "haslo" ) ).toString();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11" )
                        .arg( nawiasy( REGON ) )
                        .arg( nawiasy( nazwa ) )
                        .arg( liczbaNaString( upust ) )
                        .arg( nawiasy( login ) )
                        .arg( nawiasy( haslo ) )
                        .arg( nawiasy( ulica ) )
                        .arg( nawiasy( miejscowosc ) )
                        .arg( nawiasy( kodPocztowy ) )
                        .arg( nawiasy( telefon ) )
                        .arg( nawiasy( fax ) )
                        .arg( nawiasy( email ) );
        }

        static QString tabela;
        static QStringList polaBazy;

        enum PoleBazy {
            Id, Regon, Nazwa, Upust, Login, Haslo, Ulica, Miejscowosc, KodPocztowy, Telefon, Fax, Email
        };
    };

    struct Towar {
    protected:
        Towar( const QString &nazwa, const QString &opis, size_t ilosc, float cena, StawkaVAT vat,
               unsigned int idKategorii )
        {
            this->nazwa = nazwa;
            this->opis = opis;
            this->ilosc = ilosc;
            this->cena = cena;
            this->vat = vat;
            this->idKategorii = idKategorii;
        }

        Towar() {}

    public:
        unsigned int idKategorii;
        QString nazwa, opis;
        size_t ilosc;
        float cena;
        StawkaVAT vat;
    };

    struct TowarHurtownia : public Towar, Rekord {
        TowarHurtownia( const QString &nazwa, const QString &opis, size_t ilosc, float cena,
                        StawkaVAT vat, unsigned int idKategorii, unsigned int id = 0 )
                            : Towar( nazwa, opis, ilosc, cena, vat, idKategorii ),
                              Rekord( "Towar", id )
        {}

        TowarHurtownia( const QSqlQuery &query )
            : Rekord( "Towar", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
            opis = query.value( polaBazy.indexOf( "opis" ) ).toString();
            ilosc = query.value( polaBazy.indexOf( "ilosc" ) ).toUInt();
            cena = query.value( polaBazy.indexOf( "cena" ) ).toFloat();
            vat = stringNaVat( query.value( polaBazy.indexOf( "vat" ) ).toString() );
            idKategorii = query.value( polaBazy.indexOf( "idKategorii" ) ).toUInt();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6" )
                        .arg( nawiasy( nazwa ) )
                        .arg( nawiasy( opis ) )
                        .arg( liczbaNaString( cena ) )
                        .arg( liczbaNaString( ilosc ) )
                        .arg( nawiasy( liczbaNaString( vat ) ) )
                        .arg( liczbaNaString( idKategorii ) );
        }

        static QString tabela;
        static QStringList polaBazy;

        enum PoleBazy {
            Id, Nazwa, Opis, Cena, Ilosc, VAT, IdKategorii
        };
    };

    struct TowarSklep : public Towar, Rekord {
        TowarSklep( const QString &nazwa, const QString &opis, size_t ilosc, float cena,
                    StawkaVAT vat, float cenaZakupu, unsigned int idKategorii, unsigned int id = 0 )
                            : Towar( nazwa, opis, ilosc, cena, vat, idKategorii ),
                              Rekord( "Towar", id )
        {
            this->cenaZakupu = cenaZakupu;
        }

        TowarSklep( const QSqlQuery &query )
            : Rekord( "Towar", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
            opis = query.value( polaBazy.indexOf( "opis" ) ).toString();
            ilosc = query.value( polaBazy.indexOf( "ilosc" ) ).toUInt();
            cena = query.value( polaBazy.indexOf( "cena" ) ).toFloat();
            vat = stringNaVat( query.value( polaBazy.indexOf( "vat" ) ).toString() );
            cenaZakupu = query.value( polaBazy.indexOf( "cenaZakupu" ) ).toFloat();
            idKategorii = query.value( polaBazy.indexOf( "idKategorii" ) ).toUInt();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6, %7" )
                        .arg( nawiasy( nazwa ) )
                        .arg( nawiasy( opis ) )
                        .arg( liczbaNaString( cena ) )
                        .arg( liczbaNaString( ilosc ) )
                        .arg( liczbaNaString( idKategorii ) )
                        .arg( nawiasy( liczbaNaString( vat ) ) )
                        .arg( liczbaNaString( cenaZakupu ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        float cenaZakupu;
        //unsigned int idKategorii;

        enum PoleBazy {
            Id, Nazwa, Opis, Cena, Ilosc, VAT, CenaZakupu
        };
    };

    struct Pozycja {
    protected:
        Pozycja( unsigned int idTowaru, size_t ilosc ) {
            this->idTowaru = idTowaru;
            this->ilosc = ilosc;
        }

        Pozycja() {}

    public:
        unsigned int idTowaru;
        size_t ilosc;
    };

    struct PozycjaZamowienia : public Pozycja, Rekord {
        PozycjaZamowienia( unsigned int idTowaru, size_t ilosc, unsigned int idZamowienia,
                           unsigned int id = 0 )
                               : Pozycja( idTowaru, ilosc ),
                                 Rekord( "Pozycja_zamowienia", id )
        {
            this->idZamowienia = idZamowienia;
        }

        PozycjaZamowienia( const QSqlQuery &query )
            : Rekord( "Pozycja_zamowienia", query.value( 0 ).toUInt() )
        {
            idTowaru = query.value( polaBazy.indexOf( "idTowaru" ) ).toUInt();
            ilosc = query.value( polaBazy.indexOf( "ilosc" ) ).toUInt();
            idZamowienia = query.value( polaBazy.indexOf( "idZamowienia" ) ).toUInt();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3" )
                    .arg( liczbaNaString( idZamowienia ) )
                    .arg( liczbaNaString( idTowaru ) )
                    .arg( liczbaNaString( ilosc ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        unsigned int idZamowienia;

        enum PoleBazy {
            Id, IdZamowienia, IdTowaru, Ilosc
        };
    };

    struct PozycjaSprzedazy : public Pozycja, Rekord {
        PozycjaSprzedazy( unsigned int idTowaru, size_t ilosc, unsigned int idSprzedazy,
                          float cena, StawkaVAT vat, unsigned int id = 0 )
                               : Pozycja( idTowaru, ilosc ),
                                 Rekord( "Pozycja_sprzedazy", id )
        {
            this->idSprzedazy = idSprzedazy;
            this->cena = cena;
            this->vat = vat;
        }

        PozycjaSprzedazy( const QSqlQuery &query )
            : Rekord( "Pozycja_sprzedazy", query.value( 0 ).toUInt() )
        {
            idTowaru = query.value( polaBazy.indexOf( "idTowaru" ) ).toUInt();
            ilosc = query.value( polaBazy.indexOf( "ilosc" ) ).toUInt();
            idSprzedazy = query.value( polaBazy.indexOf( "idSprzedazy" ) ).toUInt();
            cena = query.value( polaBazy.indexOf( "cena" ) ).toUInt();
            vat = stringNaVat( query.value( polaBazy.indexOf( "vat" ) ).toString() );
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5" )
                    .arg( liczbaNaString( idSprzedazy ) )
                    .arg( liczbaNaString( idTowaru ) )
                    .arg( liczbaNaString( ilosc ) )
                    .arg( liczbaNaString( cena ) )
                    .arg( liczbaNaString( vat ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        unsigned int idSprzedazy;
        float cena;
        StawkaVAT vat;

        enum PoleBazy {
            Id, IdSprzedazy, IdTowaru, Ilosc, Cena, VAT
        };
    };

    struct Transakcja {
    protected:
        Transakcja( const QDate dataRealizacji = QDate(), float upust = 0.0,
                    StatusZamowienia status = Oczekujace )
        {
            this->dataRealizacji = dataRealizacji;
            this->upust = upust;
            this->status = status;
        }

        // nie dzia?a dla konstruktora bez argument?w (ambigous function call)
        Transakcja(int) {}

    public:
        QDate dataRealizacji;
        float upust;
        StatusZamowienia status;
    };

    struct ZamowienieHurtownia : public Transakcja, Rekord {
        ZamowienieHurtownia( unsigned int idSklepu, const QDate dataZlozenia,
                             const QString &nrFaktury = QString(), const QDate dataRealizacji = QDate(),
                             float upust = 0.0, StatusZamowienia status = Oczekujace, unsigned int id = 0 )
                                 : Transakcja( dataRealizacji, upust, status ),
                                   Rekord( "Zamowienie", id )
        {
            this->idSklepu = idSklepu;
            this->dataZlozenia = dataZlozenia;
            this->nrFaktury = nrFaktury;
        }

        ZamowienieHurtownia( const QSqlQuery &query )
            : Transakcja( 0 ),
              Rekord( "Zamowienie", query.value( 0 ).toUInt() )
        {
            idSklepu = query.value( polaBazy.indexOf( "idSklepu" ) ).toUInt();
            dataZlozenia = query.value( polaBazy.indexOf( "dataZlozenia" ) ).toDate();
            nrFaktury = query.value( polaBazy.indexOf( "nrFaktury" ) ).toString();
            dataRealizacji = query.value( polaBazy.indexOf( "dataRealizacji" ) ).toDate();
            upust = query.value( polaBazy.indexOf( "upust" ) ).toFloat();
            status = stringNaStatus( query.value( polaBazy.indexOf( "status" ) ).toString() );
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6" )
                        .arg( liczbaNaString( idSklepu ) )
                        .arg( nawiasy( dataNaString( dataZlozenia ) ) )
                        .arg( nawiasy( dataNaString( dataRealizacji ) ) )
                        .arg( liczbaNaString( upust ) )
                        .arg( nawiasy( statusNaString( status) ) )
                        .arg( nawiasy( nrFaktury ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        unsigned int idSklepu;
        QDate dataZlozenia;
        QString nrFaktury;

        enum PoleBazy {
            Id, IdSklepu, DataZlozenia, DataRealizacji, Upust, Status, NrFaktury
        };
    };

    struct ZamowienieSklep : public Transakcja, Rekord {
        ZamowienieSklep( unsigned int idHurtowni, unsigned int idPracownika, const QDate dataZlozenia,
                         const QString &nrFaktury, const QDate dataRealizacji = QDate(), float upust = 0.0,
                         StatusZamowienia status = Oczekujace, unsigned int id = 0 )
            : Transakcja( dataRealizacji, upust, status ),
              Rekord( "Zamowienie", id )
        {
            this->idHurtowni = idHurtowni;
            this->idPracownika = idPracownika;
            this->nrFaktury = nrFaktury;
            this->dataZlozenia = dataZlozenia;
        }

        ZamowienieSklep( const QSqlQuery &query )
            : Transakcja( 0 ),
              Rekord( "Zamowienie", query.value( 0 ).toUInt() )
        {
            idHurtowni = query.value( polaBazy.indexOf( "idHurtowni" ) ).toUInt();
            idPracownika = query.value( polaBazy.indexOf( "idPracownika" ) ).toUInt();
            dataZlozenia = query.value( polaBazy.indexOf( "dataZlozenia" ) ).toDate();
            nrFaktury = query.value( polaBazy.indexOf( "nrFaktury" ) ).toString();
            dataRealizacji = query.value( polaBazy.indexOf( "dataRealizacji" ) ).toDate();
            upust = query.value( polaBazy.indexOf( "upust" ) ).toFloat();
            status = stringNaStatus( query.value( polaBazy.indexOf( "status" ) ).toString() );
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6" )
                        .arg( liczbaNaString( idHurtowni ) )
                        .arg( nawiasy( dataNaString( dataZlozenia ) ) )
                        .arg( nawiasy( dataNaString( dataRealizacji ) ) )
                        .arg( nawiasy( statusNaString( status ) ) )
                        .arg( nawiasy( nrFaktury ) )
                        .arg( liczbaNaString( idPracownika ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        unsigned int idPracownika, idHurtowni;
        QDate dataZlozenia;
        QString nrFaktury;

        enum PoleBazy {
            Id, IdHurtowni, DataZlozenia, DataRealizacji, Status, NrFaktury, IdPracownika
        };
    };

    struct Sprzedaz : public Transakcja, Rekord {
        Sprzedaz( unsigned int idPracownika, unsigned int idKlienta, unsigned int idFaktury,
                  const QString &nrParagonu, Potwierdzenie potwierdzenie,
                  const QDate dataRealizacji = QDate(), float upust = 0.0,
                  StatusZamowienia status = Oczekujace, unsigned int id = 0 )
            : Transakcja( dataRealizacji, upust, status ),
              Rekord( "Sprzedaz", id )
        {
            this->potwierdzenie = potwierdzenie;
            this->nrParagonu = nrParagonu;
            this->idFaktury = idFaktury;
            this->idKlienta = idKlienta;
            this->idPracownika = idPracownika;
        }

        Sprzedaz( const QSqlQuery &query )
            : Transakcja( 0 ),
              Rekord( "Sprzedaz", query.value( 0 ).toUInt() )
        {
            idKlienta = query.value( polaBazy.indexOf( "idKlienta" ) ).toUInt();
            idPracownika = query.value( polaBazy.indexOf( "idPracownika" ) ).toUInt();
            nrParagonu = query.value( polaBazy.indexOf( "nrParagonu" ) ).toString();
            idFaktury = query.value( polaBazy.indexOf( "idFaktury" ) ).toUInt();
            dataRealizacji = query.value( polaBazy.indexOf( "dataRealizacji" ) ).toDate();
            upust = query.value( polaBazy.indexOf( "upust" ) ).toFloat();
            status = stringNaStatus( query.value( polaBazy.indexOf( "status" ) ).toString() );
            potwierdzenie = stringNaPotwierdzenie( query.value( polaBazy.indexOf( "potwierdzenie" ) ).toString() );
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6, %7" )
                    .arg( nawiasy( dataNaString( dataRealizacji ) ) )
                    .arg( nawiasy( statusNaString( status ) ) )
                    .arg( nawiasy( potwierdzenieNaString( potwierdzenie ) ) )
                    .arg( nawiasy( nrParagonu ) )
                    .arg( liczbaNaString( idFaktury ) )
                    .arg( liczbaNaString( idKlienta ) )
                    .arg( liczbaNaString( idPracownika ) );
        }
        static QString tabela;
        static QStringList polaBazy;
        Potwierdzenie potwierdzenie;
        QString nrParagonu;
        unsigned int idFaktury, idKlienta, idPracownika;

        enum PoleBazy {
            Id, DataRealizacji, Status, PotwierdzeniePole, NrParagonu, IdFaktury, IdKlienta, IdPracownika
        };
    };

    struct Faktura : public Rekord {
        Faktura( const QString &nr, unsigned int id = 0 )
            : Rekord( "Faktura", id )
        {
            this->nr = nr;
        }

        Faktura( const QSqlQuery &query )
            : Rekord( "Faktura", query.value( 0 ).toUInt() )
        {
            nr = query.value( polaBazy.indexOf( "nr" ) ).toString();
        }

        QString wartosci() const {
            return nawiasy( nr );
        }

        static QString tabela;
        static QStringList polaBazy;
        QString nr;

        enum PoleBazy {
            Id, NrFaktury
        };
    };

    struct Kategoria : public Rekord {
        Kategoria( const QString &nazwa, unsigned int id = 0 )
            : Rekord( "Kategoria", id )
        {
            this->nazwa = nazwa;
        }

        Kategoria( const QSqlQuery &query )
            : Rekord( "Kategoria", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
        }

        QString wartosci() const {
            return nawiasy( nazwa );
        }

        static QString tabela;
        static QStringList polaBazy;
        QString nazwa;

        enum PoleBazy {
            Id, Nazwa
        };
    };

    struct Czlowiek {
    protected:
        Czlowiek( const QString &nazwa, const QString &ulica, const QString &miejscowosc,
                  const QString &kodPocztowy, const QString &telefon, const QString &email )
        {
            this->nazwa = nazwa;
            this->ulica = ulica;
            this->miejscowosc = miejscowosc;
            this->kodPocztowy = kodPocztowy;
            this->telefon = telefon;
            this->email = email;
        }

        Czlowiek() {}

    public:
        QString nazwa, ulica, miejscowosc, kodPocztowy, telefon, email;
    };

    struct Klient : public Czlowiek, Rekord {
        Klient( const QString &regon, const QString &nazwa, const QString &ulica, const QString &miejscowosc,
                const QString &kodPocztowy, const QString &telefon, const QString &email,
                unsigned int id = 0 )
                    : Czlowiek( nazwa, ulica, miejscowosc, kodPocztowy, telefon, email ),
                      Rekord( "Klient", id )
        {
            this->regon = regon;
        }

        Klient( const QSqlQuery &query )
            : Rekord( "Klient", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
            regon = query.value( polaBazy.indexOf( "regon" ) ).toString();
            ulica = query.value( polaBazy.indexOf( "ulica" ) ).toString();
            miejscowosc = query.value( polaBazy.indexOf( "miejscowosc" ) ).toString();
            kodPocztowy = query.value( polaBazy.indexOf( "kodPocztowy" ) ).toString();
            telefon = query.value( polaBazy.indexOf( "telefon" ) ).toString();
            email = query.value( polaBazy.indexOf( "email" ) ).toString();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6" )
                    .arg( nawiasy( regon ) )
                    .arg( nawiasy( ulica ) )
                    .arg( nawiasy( miejscowosc ) )
                    .arg( nawiasy( kodPocztowy ) )
                    .arg( nawiasy( telefon ) )
                    .arg( nawiasy( nazwa ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        QString regon;

        enum PoleBazy {
            Id, Regon, Ulica, Miejscowosc, KodPocztowy, Telefon, Nazwa
        };
    };

    struct Pracownik : public Czlowiek, Rekord {
        Pracownik( const QString &pesel, const QString &nip, const QString &nazwa,
                   Posada posada, const QDate dataZatrudnienia, float stawka,
                   const QString &ulica, const QString &miejscowosc,
                   const QString &kodPocztowy, const QString &telefon, const QString &email,
                   const QString &haslo, unsigned int id = 0 )
                    : Czlowiek( nazwa, ulica, miejscowosc, kodPocztowy, telefon, email ),
                      Rekord( "Pracownik", id )
        {
            this->pesel = pesel,
            this->nip = nip;
            this->nazwa = nazwa;
            this->posada = posada;
            this->dataZatrudnienia = dataZatrudnienia;
            this->stawka = stawka;
            this->haslo = haslo;
        }

        Pracownik( const QSqlQuery &query )
            : Rekord( "Pracownik", query.value( 0 ).toUInt() )
        {
            nazwa = query.value( polaBazy.indexOf( "nazwa" ) ).toString();
            pesel = query.value( polaBazy.indexOf( "pesel" ) ).toString();
            dataZatrudnienia = query.value( polaBazy.indexOf( "dataZatrudnienia" ) ).toDate();
            nip = query.value( polaBazy.indexOf( "nip" ) ).toString();
            posada = stringNaPosade( query.value( polaBazy.indexOf( "posada" ) ).toString() );
            stawka = query.value( polaBazy.indexOf( "stawka" ) ).toFloat();
            ulica = query.value( polaBazy.indexOf( "ulica" ) ).toString();
            miejscowosc = query.value( polaBazy.indexOf( "miejscowosc" ) ).toString();
            kodPocztowy = query.value( polaBazy.indexOf( "kodPocztowy" ) ).toString();
            telefon = query.value( polaBazy.indexOf( "telefon" ) ).toString();
            email = query.value( polaBazy.indexOf( "email" ) ).toString();
            haslo = query.value( polaBazy.indexOf( "haslo" ) ).toString();
        }

        QString wartosci() const {
            return QString( "%1, %2, %3, %4, %5, %6, %7, %8, %9, %10, %11, %12" )
                        .arg( nawiasy( nazwa ) )
                        .arg( nawiasy( pesel ) )
                        .arg( nawiasy( nip ) )
                        .arg( nawiasy( posadaNaString( posada ) ) )
                        .arg( nawiasy( dataNaString( dataZatrudnienia ) ) )
                        .arg( liczbaNaString( stawka ) )
                        .arg( nawiasy( ulica ) )
                        .arg( nawiasy( miejscowosc ) )
                        .arg( nawiasy( kodPocztowy ) )
                        .arg( nawiasy( telefon ) )
                        .arg( nawiasy( email ) )
                        .arg( nawiasy( haslo ) );
        }

        static QString tabela;
        static QStringList polaBazy;
        QString pesel, nip, haslo;
        Posada posada;
        QDate dataZatrudnienia;
        float stawka;

        enum PoleBazy {
            Id, Nazwisko, Pesel, Nip, PosadaPole, DataZatrudnienia, Stawka, Ulica, Miejscowosc, KodPocztowy, Telefon, Email, Haslo
        };
    };

    // deklaracja metod
    explicit DBProxy( QObject *parent, const QString &host, const QString &dbName,
                      const QString &login, const QString &pass);

    bool polacz();
    void rozlacz();
    void rozpocznijDodawanie();
    void zakonczDodawanie();

    QString getLogin();

    template< typename T > bool uaktualnij( const T& rekord ) {
            QStringList wartosci = rekord.wartosci().split( ", " );
            for( int i = 0; i < wartosci.size(); ++i ) {
                wartosci[ i ].prepend( T::polaBazy.at( i + 1 ) + "=" );
            }

            QString queryString = QString( "UPDATE " + T::tabela + " SET " + wartosci.join( ", " )
                                           + " WHERE id=" + QString::number( rekord.id ) );
            return execQuery( queryString, true ).toBool();
    }

    template< typename T > unsigned int dodaj( T& rekord ) {
        QString queryString = QString( "INSERT INTO " + T::tabela + " (" + T::polaBazy.join( ", " ) + ") "
                                       "VALUES (NULL, " + rekord.wartosci() + ");" );
        unsigned int id = execQuery( queryString ).toUInt();
        rekord.id = id;
        return id;
    }

    template< typename T > QList< T > pobierz( const QMultiMap< typename T::PoleBazy, Filtr > &filtr = QMultiMap< typename T::PoleBazy, Filtr >(),
                                               Dzialanie dzialanie = AND )
    {
        QString queryString = QString( "SELECT " + T::polaBazy.join( ", " ) + " FROM %1" )
                              .arg( T::tabela );

        if( !filtr.empty() ) {
            queryString += " WHERE ";

            QString dzialanieString = " OR ";
            if( dzialanie == AND )
                dzialanieString = " AND ";

            typename QMultiMap< typename T::PoleBazy, Filtr >::const_iterator it = filtr.begin();
            for( it = filtr.begin(); it != filtr.end(); ++it ) {
                QString poleStr = T::polaBazy[ it.key() ];
                Filtr poleFiltru = it.value();
                QVariant wartosc = it.value().wartosc;

                queryString += poleStr;
                queryString += relacjaNaString( poleFiltru.relacja );

                if( Rekord::polaUInt.contains( poleStr ) )
                    queryString += liczbaNaString( wartosc.toUInt() );

                else if( Rekord::polaFloat.contains( poleStr ) )
                    queryString += liczbaNaString( wartosc.toFloat() );

                else if( Rekord::polaQDate.contains( poleStr ) )
                    queryString += nawiasy( dataNaString( wartosc.toDate() ) );

                else if( Rekord::polaEnum.contains( poleStr ) ) {
                    if( poleStr == "vat" )
                        queryString += nawiasy( vatNaString( (StawkaVAT)wartosc.toInt() ) );

                    if( poleStr == "status" )
                        queryString += nawiasy( statusNaString( (StatusZamowienia)wartosc.toInt() ) );

                    if( poleStr == "potwierdzenie" )
                        queryString += nawiasy( potwierdzenieNaString( (Potwierdzenie)wartosc.toInt() ) );

                    if( poleStr == "posada" )
                        queryString += nawiasy( posadaNaString( (Posada)wartosc.toInt() ) );
                }

                else {
                    if( poleFiltru.relacja == Zawiera ) {
                        wartosc = "%" + wartosc.toString() + "%";
                    }
                    queryString += nawiasy( wartosc.toString() );
                }

                queryString += dzialanieString;
            }
            queryString.chop( 4 );
        }
        queryString += ";";

        QSqlQuery query( db );

        QList< T > lista;
        if( execQuery( queryString, true, &query ).toBool() ) {
            while( query.next() ) {
                lista.append( T( query ) );
            }
        }

        return lista;
    }

    static Posada stringNaPosade( const QString &string );
    static Potwierdzenie stringNaPotwierdzenie( const QString &string );
    static StatusZamowienia stringNaStatus( const QString &string );
    static StawkaVAT stringNaVat( const QString &string );
    static QString dataNaString( const QDate &data );
    static QString liczbaNaString( double liczba );
    static QString nawiasy( const QString &string );
    static QString posadaNaString( Posada posada );
    static QString potwierdzenieNaString( Potwierdzenie potwierdzenie );
    static QString relacjaNaString( Relacja relacja );
    static QString statusNaString( StatusZamowienia status );
    static QString vatNaString( StawkaVAT vat );

signals:
    void bladDodawaniaRekordu();
    void log( QString str );

public slots:
public:
    void usunRekord( const Rekord *rekord );
private:
    QVariant execQuery( const QString &queryString, bool zwracajBool = false, QSqlQuery *query = 0 );

    QSqlDatabase db;

    // zarz?dzie maszyn? stanu zwi?zan? z kontrol? b??d?w przy dodawaniu
    // rekord?w do bazy danych
    bool dodawanie;
    bool mBladDodawaniaRekordu;
    QList< Rekord* > aktualnieDodawaneRekordy;

private slots:
    void debug( QString str );
};

namespace DBProxyNS {
    typedef QMultiMap< DBProxy::Sklep::PoleBazy, DBProxy::Filtr > FiltrSklep;
    typedef QMultiMap< DBProxy::Hurtownia::PoleBazy, DBProxy::Filtr > FiltrHurtownia;
    typedef QMultiMap< DBProxy::TowarHurtownia::PoleBazy, DBProxy::Filtr > FiltrTowarHurtownia;
    typedef QMultiMap< DBProxy::TowarSklep::PoleBazy, DBProxy::Filtr > FiltrTowarSklep;
    typedef QMultiMap< DBProxy::PozycjaZamowienia::PoleBazy, DBProxy::Filtr > FiltrPozycjaZamowienia;
    typedef QMultiMap< DBProxy::PozycjaSprzedazy::PoleBazy, DBProxy::Filtr > FiltrPozycjaSprzedazy;
    typedef QMultiMap< DBProxy::ZamowienieHurtownia::PoleBazy, DBProxy::Filtr > FiltrZamowienieHurtownia;
    typedef QMultiMap< DBProxy::ZamowienieSklep::PoleBazy, DBProxy::Filtr > FiltrZamowienieSklep;
    typedef QMultiMap< DBProxy::Sprzedaz::PoleBazy, DBProxy::Filtr > FiltrSprzedaz;
    typedef QMultiMap< DBProxy::Faktura::PoleBazy, DBProxy::Filtr > FiltrFaktura;
    typedef QMultiMap< DBProxy::Kategoria::PoleBazy, DBProxy::Filtr > FiltrKategoria;
    typedef QMultiMap< DBProxy::Klient::PoleBazy, DBProxy::Filtr > FiltrKlient;
    typedef QMultiMap< DBProxy::Pracownik::PoleBazy, DBProxy::Filtr > FiltrPracownik;

    typedef DBProxy::Sklep Sklep;
    typedef DBProxy::Hurtownia Hurtownia;
    typedef DBProxy::TowarHurtownia TowarHurtownia;
    typedef DBProxy::TowarSklep TowarSklep;
    typedef DBProxy::PozycjaZamowienia PozycjaZamowienia;
    typedef DBProxy::PozycjaSprzedazy PozycjaSprzedazy;
    typedef DBProxy::ZamowienieHurtownia ZamowienieHurtownia;
    typedef DBProxy::ZamowienieSklep ZamowienieSklep;
    typedef DBProxy::Sprzedaz Sprzedaz;
    typedef DBProxy::Faktura Faktura;
    typedef DBProxy::Kategoria Kategoria;
    typedef DBProxy::Klient Klient;
    typedef DBProxy::Pracownik Pracownik;

    typedef DBProxy::Filtr Filtr;
}

Q_DECLARE_METATYPE( DBProxy::Posada );
Q_DECLARE_METATYPE( DBProxy::Potwierdzenie );
Q_DECLARE_METATYPE( DBProxy::StatusZamowienia );
Q_DECLARE_METATYPE( DBProxy::StawkaVAT );

#endif // DBPROXY_H
