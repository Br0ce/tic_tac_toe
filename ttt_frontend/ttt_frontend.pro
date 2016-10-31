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

DESTDIR=bin #Target file directory
OBJECTS_DIR=gen_bin #Intermediate object files directory
MOC_DIR=gen_bin #Intermediate moc files directory

# Input
HEADERS += 
SOURCES += src/main.cpp
