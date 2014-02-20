QT += core gui widgets
TEMPLATE = app
DEPENDPATH += . src src/graphics
CONFIG += app

#We need specify what classes will be available for each
#operative system if we include a header of Linux and we
#are compiling in Windows, the universe explodes.

#--------------WINDOWS--------------
#On windows we use msvc because mingw not link correctly to jvm.lib and produce a:
#undefined reference to `_imp__ JNI_GetDefaultJavaVMInitArgs@4'
#error: undefined reference to `_imp__JNI_CreateJavaVM@12'
#How we use msvc all includes of headers on application need be refactor to be relatives
#to the current file.
#msvc compiler don't understand: DEPENDPATH qt macro
win32{
    release { DESTDIR = dist-windows_x86 }
    INCLUDEPATH += $$(JAVA_HOME)/include
    INCLUDEPATH += $$(JAVA_HOME)/include/win32
    LIBS += -L"$$(JAVA_HOME)\lib" -ljvm
}

#--------------LINUX--------------
unix:!macx{
  release { DESTDIR = dist-linux_x64 }
  dynamicLibs.path += $$DESTDIR/libs
  dynamicLibs.files += \
    $$(QT_LIBRARY_PATH)/*Core.so \
    $$(QT_LIBRARY_PATH)/*Gui.so
  compress.path += '.'
    compress.extra += 'tar czfv dist-linux_x64.tar.gz dist-linux_x64/'

  INCLUDEPATH += $$(JAVA_HOME)/include
  INCLUDEPATH += $$(JAVA_HOME)/include/linux
  LIBS += -L$$(JRE_HOME)/lib/amd64/server -ljvm

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
  src/lib/jvm/virtualmachine.h \
    src/lib/os/windows.h \
    src/lib/spec/windowsspecifications.h

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
  src/lib/jvm/virtualmachine.cpp \
    src/lib/os/windows.cpp \
    src/lib/spec/windowsspecifications.cpp

RESOURCES += QtResourcesFile.qrc
INSTALLS += dynamicLibs compress
