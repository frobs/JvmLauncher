#ifndef LINUX_H
#define LINUX_H

#include "src/lib/operativesystem/unix.h"

class Linux: public Unix{
  public:
    Linux();
    ~Linux();
    unsigned long getTotalRam();
    unsigned long getFreeRam();
  private:
    struct sysinfo memoryInformation;
};

#endif // LINUX_H
