#ifndef WINDOWS_H
#define WINDOWS_H

#include <QVariant>
#include <Windows.h>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <comutil.h>
#include "../os/multios.h"

typedef BOOL (WINAPI *IW64PFP)(HANDLE, BOOL *);

class Windows: public MultiOs{
  public:
    Windows();
    QVariant getFreeRam();
    QVariant getTotalRam();
    QVariant getOsVersionNumber();
    QVariant getOsArchitecture();

  private:
    MEMORYSTATUSEX statex;
};

#endif // WINDOWS_H
