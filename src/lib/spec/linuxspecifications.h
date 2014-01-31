#ifndef LINUXSPECIFICATIONS_H
#define LINUXSPECIFICATIONS_H

#include "src/lib/spec/systemspecifications.h"
#include "src/lib/os/linux.h"

class LinuxSpecifications : public SystemSpecifications{
  public:
    LinuxSpecifications(QVariantHash& minimunSystemRequeriments);

  private:
    void getRuntimeSystemSpecifications();
    Linux* systemSpecificationsChecker;
    QString getRuntimeDistribution(); 
  };

#endif // LINUXSPECIFICATIONS_H
