
QT       += widgets testlib core

TARGET = tst_splashscreen
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH+= ../../
DEPENDPATH+= ../../

SOURCES += test/unit/main.cpp \
    test/unit/tst_splashscreen.cpp \
    src/graphics/splashscreen.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test/unit/tst_splashscreen.h \
    src/graphics/splashscreen.h
