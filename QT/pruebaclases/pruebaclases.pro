#-------------------------------------------------
#
# Project created by QtCreator 2013-09-06T19:07:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pruebaclases
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
        mainwindow.cpp \
         simage.cpp \
    Smatch/frameprocessor.cpp \
    ../Libs/SvideoProcessor/featuretracker.cpp \
    videoprocessor.cpp \
    surfd.cpp \
    Smatch/hog.cpp \
    ../Libs/SvideoProcessor/integralproy.cpp \
    Scountour/scontour.cpp

HEADERS  += mainwindow.h \
    simage.h \
    Smatch/Smatch_global.h \
    Smatch/frameprocessor.h \
    ../Libs/SvideoProcessor/featuretracker.h \
    videoprocessor.h \
    surfd.h \
    Smatch/hog.h \
    ../Libs/SvideoProcessor/integralproy.h \
    Scountour/scontour.h

FORMS    += mainwindow.ui
