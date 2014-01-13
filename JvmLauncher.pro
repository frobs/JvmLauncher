
QT += widgets core

TEMPLATE = app

DEPENDPATH += . src src/graphics
INCLUDEPATH += . src/graphics

HEADERS += src/graphics/splashscreen.h \
    src/lib/operativesystem/linux.h \
    src/lib/operativesystem/multios.h \
    src/lib/operativesystem/unix.h


SOURCES += src/main.cpp \
           src/graphics/splashscreen.cpp \
    src/lib/operativesystem/linux.cpp \
    src/lib/operativesystem/multios.cpp \
    src/lib/operativesystem/unix.cpp


RESOURCES += QtResourcesFile.qrc
