include("config/compile/linux.ini")
release { DESTDIR = dist-linux_x64 }
dynamicLibs.path += $$DESTDIR/libs
dynamicLibs.files += \
  $${QT_LIBRARY_PATH}/*Core.so \
  $${QT_LIBRARY_PATH}/*Gui.so
compress.path += '.'
  compress.extra += 'tar czfv dist-linux_x64.tar.gz dist-linux_x64/'

INCLUDEPATH += $${JAVA_HOME_PATH}/include
INCLUDEPATH += $${JAVA_HOME_PATH}/include/linux
LIBS += -L$${JRE_HOME_PATH}/lib/amd64/server -ljvm

HEADERS += \
  src/lib/spec/linuxspecifications.h \
  src/lib/os/linux.h
SOURCES += \
  src/lib/spec/linuxspecifications.cpp \
  src/lib/os/linux.cpp
