#On windows we use msvc because mingw not link correctly to jvm.lib and produce a:
#undefined reference to `_imp__ JNI_GetDefaultJavaVMInitArgs@4'
#error: undefined reference to `_imp__JNI_CreateJavaVM@12'
#How we use msvc all includes of headers on application need be refactor to be relatives
#to the current file.
#msvc compiler don't understand: DEPENDPATH qt macro
#The QSplashScreen is created in one thread and close in another thread
#this produce a error of threads on debug mode, to fix it compile on relase mode

release { DESTDIR = dist-windows_x86 }
INCLUDEPATH += $$(JAVA_HOME)/include
INCLUDEPATH += $$(JAVA_HOME)/include/win32
LIBS += -L"$$(JAVA_HOME)\lib" -ljvm

HEADERS += \
  src/lib/os/windows.h \
  src/lib/spec/windowsspecifications.h
SOURCES += \
  src/lib/os/windows.cpp \
  src/lib/spec/windowsspecifications.cpp
