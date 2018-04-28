#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T12:31:12
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Oscilloscope
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adc.cpp

HEADERS  += mainwindow.h \
    adc.h

FORMS    += mainwindow.ui
