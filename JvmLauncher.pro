
QT += gui core

TEMPLATE = app

DEPENDPATH += . src src/graphics
INCLUDEPATH += . src/graphics

HEADERS += src/graphics/splashscreen.h

SOURCES += src/main.cpp \
           src/graphics/splashscreen.cpp

RESOURCES += QtResourcesFile.qrc
