# -------------------------------------------------
# Project created by QtCreator 2010-04-20T15:27:45
# -------------------------------------------------
QT += sql
QT += network \
    sql
TARGET = Sklep
TEMPLATE = app
SOURCES += main.cpp \
    sklep.cpp \
    sprzedawca.cpp \
    kierownik.cpp \
    ../DBProxy/dbproxy.cpp \
    finalizacja.cpp \
    logowanieh.cpp \
    magazynier.cpp
HEADERS += sklep.h \
    sprzedawca.h \
    kierownik.h \
    ../DBProxy/dbproxy.h \
    finalizacja.h \
    logowanieh.h \
    magazynier.h
FORMS += sklep.ui \
    sprzedawca.ui \
    kierownik.ui \
    finalizacja.ui \
    logowanieh.ui \
    magazynier.ui
