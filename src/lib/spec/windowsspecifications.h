#ifndef WINDOWSSPECIFICATIONS_H
#define WINDOWSSPECIFICATIONS_H

#include "systemspecifications.h"
#include "../os/windows.h"
#include <QVariantList>

class WindowsSpecifications : public SystemSpecifications{
  public:
    WindowsSpecifications(QVariantHash& minimunSystemRequeriments);

  private:
    void getRuntimeSystemSpecifications();
    Windows* systemSpecificationsChecker;
};

#endif // WINDOWSSPECIFICATIONS_H
