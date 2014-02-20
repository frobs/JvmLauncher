#ifndef WINDOWSSPECIFICATIONS_H
#define WINDOWSSPECIFICATIONS_H

#include "src/lib/spec/systemspecifications.h"
#include "src/lib/os/windows.h"
#include <QVariantList>

class WindowsSpecifications : public SystemSpecifications{
  public:
    WindowsSpecifications(QVariantHash& minimunSystemRequeriments);

  private:
    void getRuntimeSystemSpecifications();
    Windows* systemSpecificationsChecker;
};

#endif // WINDOWSSPECIFICATIONS_H
