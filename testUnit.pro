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

#----------------ALL PLATFORMS----------------
HEADERS += \
    src/graphics/splashscreen.h \
    src/lib/os/multios.h \
    test/unit/tst_multios.h \
    test/unit/tst_splashscreen.h \
    src/lib/os/osruntime.h \
    test/unit/tst_configurationfile.h \
    src/lib/utils/configurationfile.h \
    src/lib/utils/qtresourcesfileconstants.h \
    src/lib/spec/systemspecifications.h \
    src/lib/spec/specificationsfactory.h \
    src/lib/utils/qvariantlistformatter.h


SOURCES += \
    src/graphics/splashscreen.cpp \
    src/lib/os/multios.cpp \
    test/unit/main.cpp \
    test/unit/tst_multios.cpp \
    test/unit/tst_splashscreen.cpp \
    src/lib/os/osruntime.cpp \
    test/unit/tst_configurationfile.cpp \
    src/lib/utils/configurationfile.cpp \
    src/lib/spec/systemspecifications.cpp \
    src/lib/spec/specificationsfactory.cpp \
    src/lib/utils/qvariantlistformatter.cpp


#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.
win32{
 #----------------WINDOWS----------------

}else{
  #----------------UNIX----------------
  HEADERS += \
    src/lib/os/unix.h \
    test/unit/tst_unix.h
  SOURCES += \
    src/lib/os/unix.cpp \
    test/unit/tst_unix.cpp
  mac{
  #----------------MAC----------------
  }else{
    #----------------LINUX----------------
    HEADERS += \
      src/lib/spec/linuxspecifications.h \
      src/lib/os/linux.h \
      test/unit/tst_linuxspecifications.h \
      test/unit/tst_linux.h

    SOURCES += \
    src/lib/spec/linuxspecifications.cpp \
    src/lib/os/linux.cpp \
    test/unit/tst_linuxspecifications.cpp \
    test/unit/tst_linux.cpp
  }
}

RESOURCES += \
    test/resources/TestResourcesFile.qrc

