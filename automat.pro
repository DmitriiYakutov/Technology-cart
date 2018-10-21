QT += core
QT -= gui

TARGET = automat
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    output.cpp \
    action.cpp \
    automat.cpp \
    enumstate.cpp \
    enumcondition.cpp \
    output_automat.cpp

HEADERS += \
    output.h \
    action.h \
    automat.h \
    enumstate.h \
    enumcondition.h \
    output_automat.h

