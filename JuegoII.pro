#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T20:20:59
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia
QT       += core gui serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JuegoII
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    menu1.cpp \
    funciones.cpp \
    menu2.cpp \
    personaje.cpp \
    proyectil.cpp \
    villano.cpp \
    trampa.cpp \
    aliens.cpp \
    proyectilejecutivo.cpp \
    proyectilalien.cpp \
    gameo.cpp \
    ramsey.cpp \
    ataquer1.cpp \
    vidas.cpp \
    comic.cpp

HEADERS += \
        mainwindow.h \
    menu1.h \
    funciones.h \
    menu2.h \
    personaje.h \
    proyectil.h \
    villano.h \
    trampa.h \
    aliens.h \
    proyectilejecutivo.h \
    proyectilalien.h \
    gameo.h \
    ramsey.h \
    ataquer1.h \
    vidas.h \
    comic.h

FORMS += \
        mainwindow.ui \
    menu1.ui \
    menu2.ui \
    gameo.ui \
    comic.ui

RESOURCES += \
    gif.qrc \
    fondo.qrc \
    comic.qrc

DISTFILES +=
