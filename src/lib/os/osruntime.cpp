#include "osruntime.h"

OSRuntime::OSRuntime(){}
QString OSRuntime::getOSRuntime(){
    #ifdef Q_OS_LINUX
        return QString("linux");
    #endif
    #ifdef Q_OS_MACX
        return QString("macos");
    #endif
    #ifdef Q_OS_WIN32
        return QString("windows");
    #endif
    return QString("unrecognized");
}

