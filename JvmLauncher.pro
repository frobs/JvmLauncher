QT += core gui widgets
TEMPLATE = app
DEPENDPATH += . src src/graphics
CONFIG += app

#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.

#--------------LINUX--------------
unix:!macx{
  release { DESTDIR = linuxRelease }
  dynamicLibs.path += $$DESTDIR/libs
  dynamicLibs.files += \
    $$(QT_LIBRARY_PATH)/*Core.so \
    $$(QT_LIBRARY_PATH)/*Gui.so

  compress.path += '.'
  compress.extra += 'tar czfv linuxRelease.tar.gz linuxRelease/'

  INCLUDEPATH += $$(JAVA_HOME)/include
  INCLUDEPATH += $$(JAVA_HOME)/include/linux
  LIBS += -L$$(JRE_HOME)/lib/amd64/server -ljvm
  LIBS += -L$$(JRE_HOME)/lib/i386/client -ljvm

  HEADERS += \
    src/lib/spec/linuxspecifications.h \
    src/lib/os/linux.h
  SOURCES += \
    src/lib/spec/linuxspecifications.cpp \
    src/lib/os/linux.cpp

}

#--------------MAC--------------
macx{
  INCLUDEPATH += $$(JAVA_HOME)/include
  INCLUDEPATH += $$(JAVA_HOME)/include/darwin
  LIBS += -L"/Library/Internet Plug-Ins/JavaAppletPlugin.plugin/Contents/Home/lib/server" -ljvm
  LIBS += -L"/Library/Internet Plug-Ins/JavaAppletPlugin.plugin/Contents/Home/lib/client" -ljvm
  SOURCES+= \
    src/lib/os/mac.cpp \
    src/lib/spec/macspecifications.cpp
  HEADERS += \
    src/lib/os/mac.h \
    src/lib/spec/macspecifications.h
}

#--------------UNIX--------------
unix{
  HEADERS += \
    src/lib/os/unix.h
  SOURCES += \
    src/lib/os/unix.cpp
}

#--------------ALL OPERATIVE SYSTEM--------------
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
