#-------------------------------------------------
#
# Project created by QtCreator 2013-08-01T08:53:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Histograma
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
        siriosource.cpp \
    Imagen/imagenQt.cpp \
    Imagen/imagenCv.cpp \
    Imagen/handler.cpp \
    Imagen/smatch.cpp \
    Imagen/svideo.cpp \
    Imagen/sbss.cpp

HEADERS  += siriosource.h \
    Imagen/imagenQt.h \
    Imagen/imagenCv.h \
    Imagen/handler.h \
    Imagen/smatch.h \
    Imagen/svideo.h \
    Imagen/sbss.h

FORMS    += siriosource.ui
