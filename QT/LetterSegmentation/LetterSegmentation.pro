#-------------------------------------------------
#
# Project created by QtCreator 2013-12-07T17:58:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LetterSegmentation
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
        lettersegmentation.cpp \
    Scountour/scontour.cpp \
    segmentation.cpp

HEADERS  += lettersegmentation.h \
    Scountour/scontour.h \
    segmentation.h

FORMS    += lettersegmentation.ui
