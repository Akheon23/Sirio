#-------------------------------------------------
#
# Project created by QtCreator 2013-12-09T10:26:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = houg
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
    integralproy.cpp \
    linearregretion.cpp \
    fourier.cpp \
    simage.cpp \
    hog.cpp

HEADERS  += mainwindow.h \
    integralproy.h \
    linearregretion.h \
    fourier.h \
    simage.h \
    hog.hpp

FORMS    += mainwindow.ui