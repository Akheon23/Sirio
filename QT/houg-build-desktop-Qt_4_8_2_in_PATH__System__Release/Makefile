#############################################################################
# Makefile for building: houg
# Generated by qmake (2.01a) (Qt 4.8.2) on: Mon Jan 27 21:57:10 2014
# Project:  ../houg/houg.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile ../houg/houg.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I../houg -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/local/include/opencv -I/usr/local/include -I. -I. -I../houg -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_ts.so /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../houg/main.cpp \
		../houg/mainwindow.cpp \
		../houg/integralproy.cpp \
		../houg/linearregretion.cpp \
		../houg/fourier.cpp \
		../houg/simage.cpp \
		../houg/hog.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		integralproy.o \
		linearregretion.o \
		fourier.o \
		simage.o \
		hog.o \
		moc_mainwindow.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		../houg/houg.pro
QMAKE_TARGET  = houg
DESTDIR       = 
TARGET        = houg

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ../houg/houg.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile ../houg/houg.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/link_pkgconfig.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile ../houg/houg.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/houg1.0.0 || $(MKDIR) .tmp/houg1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/houg1.0.0/ && $(COPY_FILE) --parents ../houg/mainwindow.h ../houg/integralproy.h ../houg/linearregretion.h ../houg/fourier.h ../houg/simage.h ../houg/hog.hpp .tmp/houg1.0.0/ && $(COPY_FILE) --parents ../houg/main.cpp ../houg/mainwindow.cpp ../houg/integralproy.cpp ../houg/linearregretion.cpp ../houg/fourier.cpp ../houg/simage.cpp ../houg/hog.cpp .tmp/houg1.0.0/ && $(COPY_FILE) --parents ../houg/mainwindow.ui .tmp/houg1.0.0/ && (cd `dirname .tmp/houg1.0.0` && $(TAR) houg1.0.0.tar houg1.0.0 && $(COMPRESS) houg1.0.0.tar) && $(MOVE) `dirname .tmp/houg1.0.0`/houg1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/houg1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: ../houg/integralproy.h \
		../houg/fourier.h \
		../houg/simage.h \
		../houg/linearregretion.h \
		../houg/hog.hpp \
		/home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp \
		../houg/mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ../houg/mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: ../houg/mainwindow.ui
	/usr/bin/uic-qt4 ../houg/mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ../houg/main.cpp ../houg/mainwindow.h \
		../houg/integralproy.h \
		../houg/fourier.h \
		../houg/simage.h \
		../houg/linearregretion.h \
		../houg/hog.hpp \
		/home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../houg/main.cpp

mainwindow.o: ../houg/mainwindow.cpp ../houg/mainwindow.h \
		../houg/integralproy.h \
		../houg/fourier.h \
		../houg/simage.h \
		../houg/linearregretion.h \
		../houg/hog.hpp \
		/home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o ../houg/mainwindow.cpp

integralproy.o: ../houg/integralproy.cpp ../houg/integralproy.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o integralproy.o ../houg/integralproy.cpp

linearregretion.o: ../houg/linearregretion.cpp ../houg/linearregretion.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o linearregretion.o ../houg/linearregretion.cpp

fourier.o: ../houg/fourier.cpp ../houg/fourier.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fourier.o ../houg/fourier.cpp

simage.o: ../houg/simage.cpp ../houg/simage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o simage.o ../houg/simage.cpp

hog.o: ../houg/hog.cpp ../houg/hog.hpp \
		/home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hog.o ../houg/hog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

