#-------------------------------------------------
#
# Project created by QtCreator 2013-12-09T19:04:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SegmentacionIntegrales
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
        segmentationint.cpp \
    integralproy.cpp

HEADERS  += segmentationint.h \
    integralproy.h

FORMS    += segmentationint.ui
