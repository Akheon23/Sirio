#-------------------------------------------------
#
# Project created by QtCreator 2012-12-18T14:16:43
#
#-------------------------------------------------

# Programa para limpiar señales de voz

QT       += core gui

TARGET = interfaz1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    option.cpp \
    plotwidget.cpp \
    qcustomplot.cpp \
    procesamiento.cpp

HEADERS  += mainwindow.h \
    option.h \
    plotwidget.h \
    qcustomplot.h \
    procesamiento.h

FORMS    += mainwindow.ui \
    plotwidget.ui \
    option.ui


#INCLUDEPATH += /usr/include/octave-3.2.4/
#LIBS += -L"/usr/lib/octave-3.2.4/" -loctinterp -loctave


INCLUDEPATH += /usr/include/octave-3.6.2/
LIBS += -L"/usr/lib/x86_64-linux-gnu/" -loctinterp -loctave

INCLUDEPATH += /usr/include/octave-3.6.1/
LIBS += -L"/usr/lib/i386-linux-gnu/" -loctinterp -loctave


OTHER_FILES += \
    ../Graficos/stop.png \
    ../Graficos/playsegment.png \
    ../Graficos/play.png
