#ifndef LINUX_H
#define LINUX_H

#include "src/lib/os/multios.h"
#include "src/lib/os/unix.h"

class Linux: public Unix, public MultiOs{
  public:
    Linux();
    ~Linux();
    QString getTotalRam();
    QString getFreeRam();
  private:
    struct sysinfo memoryInformation;
};

#endif // LINUX_H
