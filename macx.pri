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
