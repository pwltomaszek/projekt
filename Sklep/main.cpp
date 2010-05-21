#include <QApplication>
#include "sklep.h"
#include <QtPlugin>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->addLibraryPath( "C:/Qt/2009.05/qt/plugins/sqldrivers" );
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1250"));
    OknoSklep w;
    w.show();
    return a.exec();
}
