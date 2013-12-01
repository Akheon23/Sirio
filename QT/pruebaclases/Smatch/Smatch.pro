#-------------------------------------------------
#
# Project created by QtCreator 2013-09-06T23:58:20
#
#-------------------------------------------------

QT       -= gui

TARGET = Smatch
TEMPLATE = lib

DEFINES += SMATCH_LIBRARY

SOURCES += smatch.cpp

HEADERS += smatch.h\
        Smatch_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE703AAB9
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Smatch.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
