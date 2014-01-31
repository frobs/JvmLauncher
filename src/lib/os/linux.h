#ifndef LINUX_H
#define LINUX_H

#include "src/lib/os/unix.h"
#include "src/lib/os/multios.h"

class Linux: public Unix,public MultiOs{
  public:
    Linux();
    ~Linux();
    QVariant getTotalRam();
    QVariant getFreeRam();
  private:
    struct sysinfo memoryInformation;
};

#endif // LINUX_H
