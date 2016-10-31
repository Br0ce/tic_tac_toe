# ttt_frontend.pro

QT += core gui
QT += network
QT += widgets

TEMPLATE = app
TARGET = ttt_frontend

CONFIG += c++11
#CONFIG += release
CONFIG += debug

INCLUDEPATH += ../hdr/
INCLUDEPATH += ../../hdr/

DESTDIR=bin #Target file directory
OBJECTS_DIR=gen_bin #Intermediate object files directory
MOC_DIR=gen_bin #Intermediate moc files directory

# Input
HEADERS += hdr/front_win.h \
           hdr/field.h \
           hdr/socket.h \
           hdr/session_handler.h

SOURCES += src/main.cpp \
           src/front_win.cpp \
           src/field.cpp \
           src/socket.cpp \
           src/session_handler.cpp
