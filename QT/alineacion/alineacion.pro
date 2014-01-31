#-------------------------------------------------
#
# Project created by QtCreator 2014-01-23T18:21:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alineacion
TEMPLATE = app


INCLUDEPATH += /usr/local/include/opencv

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree


SOURCES += main.cpp\
        alineacion.cpp \
    fourier.cpp \
    simage.cpp \
    linearregretion.cpp

HEADERS  += alineacion.h \
    fourier.h \
    simage.h \
    linearregretion.h

FORMS    += alineacion.ui
