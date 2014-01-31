QT += widgets core gui
TEMPLATE = app
DEPENDPATH += . src src/graphics
CONFIG += app

linux{
  INCLUDEPATH += $$(JDK_HOME)/include
  INCLUDEPATH += $$(JDK_HOME)/include/linux
  LIBS += -L$$(JAVA_HOME)/lib/amd64/server -ljvm
  LIBS += -L$$(JAVA_HOME)/lib/i386/client -ljvm
}



#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.
HEADERS += \
  src/graphics/splashscreen.h \
  src/lib/utils/qtresourcesfileconstants.h \
  src/lib/os/osruntime.h \
  src/lib/utils/configurationfile.h \
  src/lib/spec/specificationsfactory.h \
  src/lib/spec/systemspecifications.h \
    src/lib/utils/runtimeconstants.h \
    src/lib/os/multios.h \
    src/lib/utils/qvariantlistformatter.h
  win32{

  }else{
    HEADERS += \
      src/lib/os/unix.h
    mac{

    }else{
      HEADERS += \
        src/lib/spec/linuxspecifications.h \
        src/lib/os/linux.h
    }
  }
SOURCES += \
  src/main.cpp \
  src/graphics/splashscreen.cpp \
  src/lib/os/osruntime.cpp \
  src/lib/utils/configurationfile.cpp \
  src/lib/spec/specificationsfactory.cpp \
  src/lib/spec/systemspecifications.cpp \
    src/lib/os/multios.cpp \
    src/lib/utils/qvariantlistformatter.cpp
  win32{

  }else{
    SOURCES += \
      src/lib/os/unix.cpp
    mac{

    }else{
      SOURCES += \
        src/lib/spec/linuxspecifications.cpp \
        src/lib/os/linux.cpp
    }
  }

RESOURCES += QtResourcesFile.qrc
