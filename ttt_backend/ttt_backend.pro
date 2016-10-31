# ttt_backend.pro

QT += core gui
QT += network
QT += widgets

TEMPLATE = app
TARGET = ttt_backend

CONFIG += c++11
#CONFIG += release
CONFIG += debug
CONFIG += console
CONFIG += app_bundle

INCLUDEPATH += ../hdr/

DESTDIR=bin #Target file directory
OBJECTS_DIR=gen_bin #Intermediate object files directory
MOC_DIR=gen_bin #Intermediate moc files directory

# Input
HEADERS += 

SOURCES += src/main.cpp \
