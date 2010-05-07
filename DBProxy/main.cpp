#include <QApplication>

#include "dbproxy.h"

int main( int argc, char *argv[] ) {
    QApplication app( argc, argv );

    DBProxy db( NULL, "localhost", "Sklep", "root", "inutero" );
    db.polacz();

    QMultiMap< DBProxy::TowarSklep::PoleBazy, DBProxy::Filtr > filtr, filtr2;
    filtr.insert( DBProxy::TowarSklep::Id, DBProxy::Filtr( 4, DBProxy::Wieksze ) );
    filtr.insert( DBProxy::TowarSklep::Id, DBProxy::Filtr( 2, DBProxy::Mniejsze ) );
    QList< DBProxy::TowarSklep > towary = db.pobierz< DBProxy::TowarSklep >( filtr, DBProxy::OR );

    foreach( DBProxy::TowarSklep towar, towary ) {
        qDebug() << towar.id;
    }

    filtr2.insert( DBProxy::TowarSklep::Opis, DBProxy::Filtr( "Ceska", DBProxy::Zawiera ) );
    QList< DBProxy::TowarSklep > towary2 = db.pobierz< DBProxy::TowarSklep >( filtr2 );
    foreach( DBProxy::TowarSklep towar, towary2 ) {
        qDebug() << towar.nazwa;
    }

    DBProxy::Hurtownia h( "nazwa", "regon", "ul", "m", "k0", "te", "f", "em", 3.4 );
    db.dodajHurtownie( h );

    return app.exec();
}
