#-------------------------------------------------
#
# Project created by QtCreator 2013-12-07T19:14:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = extraccion_caracteristicas
TEMPLATE = app

unix{
    CONFIG += link_pkgconfig
    PKGCONFIG +=opencv
}
win32{
    INCLUDEPATH += C:\opencv246bin\install\include \
                   C:\opencv246bin\install\include\opencv \
                   C:\opencv246bin\install\include\opencv2

    LIBS += -LC:\\opencv246bin\\install\\lib \
            -lopencv_core246.dll \
            -lopencv_highgui246.dll \
            -lopencv_imgproc246.dll \
            -lopencv_features2d246.dll \
            -lopencv_calib3d246.dll \
            -lopencv_video246.dll \
            -lopencv_videostab246.dll

}

SOURCES += main.cpp\
        mainwindow.cpp \
    Ssobel.cpp \
    smatch.cpp \
    simage.cpp \
    scontour.cpp \
    integralproy.cpp \
    hog.cpp

HEADERS  += mainwindow.h \
    Ssobel.hpp \
    Smatch_global.h \
    smatch.h \
    simage.h \
    scontour.h \
    integralproy.h \
    hog.hpp

FORMS    += mainwindow.ui
