#ifndef MULTIOS_H
#define MULTIOS_H

#include <QApplication>
#include <QDesktopWidget>
#include <stdint.h>
#ifdef _WIN32
  #include <limits.h>
  #include <intrin.h>
  typedef unsigned __int32  uint32_t;

#else
  #include <stdint.h>
#endif

class MultiOs{
  public:
    MultiOs();
    ~MultiOs();
    QVariant getScreenWidth();
    QVariant getScreenHeight();
    QVariant getSseVersion();
    QVariant getCoresNum();
  private:
    unsigned regs[4];
    void cpuID(unsigned,unsigned []);
};

#endif // MULTIOS_H
