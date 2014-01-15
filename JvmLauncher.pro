QT += widgets core gui
TEMPLATE = app
DEPENDPATH += . src src/graphics

#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.
HEADERS += \
  src/graphics/splashscreen.h \
  src/lib/os/multios.h \
  src/lib/spec/systemspecifications.h
  win32{

  }else{
    HEADERS += \
      src/lib/os/unix.h
    mac{

    }else{
      HEADERS += \
        src/lib/os/linux.h
    }
  }
SOURCES += \
  src/main.cpp \
  src/graphics/splashscreen.cpp \
  src/lib/os/multios.cpp \
  src/lib/spec/systemspecifications.cpp
  win32{

  }else{
    SOURCES += \
      src/lib/os/unix.cpp
    mac{

    }else{
      SOURCES += \
        src/lib/os/linux.cpp
    }
  }

RESOURCES += QtResourcesFile.qrc
