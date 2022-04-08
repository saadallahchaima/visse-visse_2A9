QT       += core gui charts
QT += sql
QT += printsupport
QT += gui
QT += core gui network

QT += core gui charts
QT += core

QT       += core gui charts sql  multimedia multimediawidgets printsupport charts serialport

QT += core gui printsupport

QT += sql

QT += multimedia
Qt += charts

SUBDIRS += \
    widget \
    quickitem \
    lib
CONFIG+=qaxcontainer
QT += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    excelexporthelper.cpp \
    facture.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    paiement.cpp

HEADERS += \
    connexion.h \
    excelexporthelper.h \
    facture.h \
    fournisseur.h \
    mainwindow.h \
    paiement.h

FORMS += \
    mainwindow.ui
include({PAHT_TO_LIB}../defaults.pri)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Excel/Facture.xlsx \
    Pictures/Addition.png \
    Pictures/Aqua.qss \
    Pictures/Clear.png \
    Pictures/Error.jpg \
    Pictures/Filmovio.qss \
    Pictures/Fr.png \
    Pictures/MacOS.qss \
    Pictures/PDF.jpg \
    Pictures/Payments.png \
    Pictures/Remove.png \
    Pictures/Russe.png \
    Pictures/Search.png \
    Pictures/Stat.png \
    Pictures/Tri.png \
    Pictures/Update.jpg \
    Pictures/english.png \
    Pictures/logo.jpg \
    Pictures/not.png

RESOURCES += \
    Resources.qrc
