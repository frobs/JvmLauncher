#ifndef MAC_H
#define MAC_H

#include <QVariant>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include "src/lib/os/unix.h"
#include "src/lib/os/multios.h"

class Mac: public Unix,public MultiOs{
  public:
    Mac();
    QVariant getTotalRam();
    QVariant getFreeRam();
};

#endif // MAC_H
