
QT       += widgets testlib core

TARGET = tst_splashscreen
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH+= ../../
DEPENDPATH+= ../../

SOURCES += test/unit/main.cpp \
    test/unit/tst_splashscreen.cpp \
    test/unit/tst_multios.cpp \
    src/graphics/splashscreen.cpp \
    src/lib/operativesystem/linux.cpp \
    src/lib/operativesystem/multios.cpp \
    src/lib/operativesystem/unix.cpp \
    test/unit/tst_unix.cpp \
    test/unit/tst_linux.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test/unit/tst_splashscreen.h \
    test/unit/tst_multios.h \
    src/graphics/splashscreen.h \
    src/lib/operativesystem/linux.h \
    src/lib/operativesystem/multios.h \
    src/lib/operativesystem/unix.h \
    test/unit/tst_unix.h \
    test/unit/tst_linux.h
