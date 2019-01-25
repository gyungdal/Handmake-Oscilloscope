#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T12:31:12
#
#-------------------------------------------------


INCLUDEPATH += /usr/local/qwt-6.1.4/include \
    /usr/local/qwt-6.1.4

LIBS += -L/usr/local/qwt-6.1.4/lib -lqwt \
    /usr/local/qwt-6.1.4/lib/libqwt.so.6.1.4 -lqwt

DEPENDPATH += /usr/local/qwt-6.1.4/include
CONFIG += qwt

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Oscilloscope
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    adc.cpp \
    knob.cpp \
    chart.cpp

HEADERS  += mainwindow.h \
    adc.h \
    type.h \
    config.h \
    knob.h \
    chart.h
