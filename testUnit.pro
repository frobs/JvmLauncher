#This qtProject generate the executable that run all
#test of the application, with only a executable we
#run all test, one QtProject per test isn't pragmatic.
#Remember that you need add the class that you want test
#not only the test.


QT       += widgets testlib core

TARGET = testUnitJvmLauncher
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
DEFINES += SRCDIR=\\\"$$PWD/\\\"

#This give us access to all files of the project
DEPENDPATH+= ../../


#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.

#---------------CLASSES THAT WILL BE TESTED------------------------
HEADERS += \
  src/graphics/splashscreen.h \
  src/lib/os/multios.h
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
  src/graphics/splashscreen.cpp \
  src/lib/os/multios.cpp
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

#---------------TEST CLASSES------------------------------------
HEADERS += \
  test/unit/tst_splashscreen.h \
  test/unit/tst_multios.h
  win32{

  }else{
    HEADERS += \
      test/unit/tst_unix.h
    mac{

    }else{
      HEADERS += \
        test/unit/tst_linux.h
    }
  }
SOURCES += \
  test/unit/main.cpp \
  test/unit/tst_splashscreen.cpp \
  test/unit/tst_multios.cpp

  win32{

  }else{
    SOURCES += \
      test/unit/tst_unix.cpp
    mac{

    }else{
      SOURCES += \
        test/unit/tst_linux.cpp
    }
  }
