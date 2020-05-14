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
    gui/player.cpp \
    gui/audioitem.cpp \
    gui/buttontool.cpp \
    gui/combotool.cpp \
    gui/scrollarea.cpp \
    simplewidget.cpp \
    gui/dialogcolor.cpp \
    engine/Fader.cpp \
    engine/StreamFile.cpp \
    engine/StreamMath.cpp \
    engine/StreamPlay.cpp \
    engine/StreamRender.cpp \
    render/Render.cpp \
    gui/framebase.cpp \
    gui/frameplayertool.cpp \
    gui/dialogplayertool.cpp \
    gui/frameplayernav.cpp \
    gui/slider.cpp \
    gui/frameplayerslider.cpp \
    gui/labelcount.cpp \
    gui/labelbase.cpp \
    gui/dialogbase.cpp \
    gui/dialogprogressbar.cpp

HEADERS  += mainwindow.h \
    gui/player.h \
    gui/audioitem.h \
    gui/buttontool.h \
    gui/combotool.h \
    gui/scrollarea.h \
    simplewidget.h \
    gui/dialogcolor.h \
    engine/Fader.h \
    engine/StreamFile.h \
    engine/StreamMath.h \
    engine/StreamPlay.h \
    engine/StreamRender.h \
    render/Render.h \
    gui/framebase.h \
    gui/frameplayertool.h \
    gui/dialogplayertool.h \
    gui/frameplayernav.h \
    gui/slider.h \
    gui/frameplayerslider.h \
    gui/labelcount.h \
    gui/labelbase.h \
    gui/dialogbase.h \
    gui/dialogprogressbar.h

FORMS    += mainwindow.ui \
    gui/AudioItem.ui \
    gui/DialogColor.ui










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
