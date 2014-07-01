#--------------COMMON TO ALL OPERATIVE SYSTEM--------------
QT += core gui widgets
TEMPLATE = app
DEPENDPATH += . src src/graphics
CONFIG += app

HEADERS += \
  src/graphics/splashscreen.h \
  src/lib/utils/qtresourcesfileconstants.h \
  src/lib/os/osruntime.h \
  src/lib/utils/configurationfile.h \
  src/lib/spec/specificationsfactory.h \
  src/lib/spec/systemspecifications.h \
  src/lib/utils/runtimeconstants.h \
  src/lib/os/multios.h \
  src/lib/jvm/jvmparameters.h \
  src/lib/utils/qvariantlistutils.h \
  src/lib/jvm/virtualmachine.h

SOURCES += \
  src/main.cpp \
  src/graphics/splashscreen.cpp \
  src/lib/os/osruntime.cpp \
  src/lib/utils/configurationfile.cpp \
  src/lib/spec/specificationsfactory.cpp \
  src/lib/spec/systemspecifications.cpp \
  src/lib/os/multios.cpp \
  src/lib/jvm/jvmparameters.cpp \
  src/lib/utils/qvariantlistutils.cpp \
  src/lib/jvm/virtualmachine.cpp

RESOURCES += QtResourcesFile.qrc
INSTALLS += dynamicLibs compress

OTHER_FILES += \
    linux.pri \
    windows.pri \
    macx.pri \
    unix.pri





#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.
#--------------WINDOWS--------------
win32{
  include(windows.pri)
}

#--------------LINUX--------------------
unix:!macx{
  include(linux.pri)
}

#--------------MAC----------------------
macx{
  include(macx.pri)
}

#--------------UNIX---------------------
unix{
  include(unix.pri)
}
