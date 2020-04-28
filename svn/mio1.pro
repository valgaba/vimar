#-------------------------------------------------
#
# Project created by QtCreator 2020-04-27T08:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mio1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gui/player.cpp

HEADERS  += mainwindow.h \
    gui/player.h

FORMS    += mainwindow.ui










# -------------------------------------------------
# mis lib
# -------------------------------------------------


win32 {

LIBS += ..\lib\bass\bass.lib \
        ..\lib\vumeter\libqvumeterplug.a


INCLUDEPATH = ..\lib\bass \
              ..\lib\vumeter \
              ..\lib\otras



#OBJECTS_DIR =../out
#MOC_DIR = ../out
#UI_DIR = ../out  # este no
#DESTDIR = ../IRadit-1.0-win32


}
#-----------------------------------------------------------

unix {

LIBS += /usr/lib/libbass.so \
       /usr/lib/libqvumeterplug.so \
      /usr/lib/libtag.so.1



INCLUDEPATH = ../lib/bass \
              ../lib/taglib/include/taglib \
              ../lib/vumeter



OBJECTS_DIR =../out
MOC_DIR = ../out
UI_DIR = ../out
DESTDIR = ../LinuxDesktop



}



#-------------------------------------------------------------
RESOURCES += \
    radit.qrc


RC_FILE = radit.rc
