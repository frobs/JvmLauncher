#ifndef LINUXSPECIFICATIONS_H
#define LINUXSPECIFICATIONS_H

#include "src/lib/spec/systemspecifications.h"
#include "src/lib/os/linux.h"
#include <QVariantList>

class LinuxSpecifications : public SystemSpecifications{
  public:
    LinuxSpecifications(QVariantHash& minimunSystemRequeriments);

  private:
    void getRuntimeSystemSpecifications();
    Linux* systemSpecificationsChecker;
    QString getRuntimeDistribution(); 
    QVariantList formatOsVersionNumber(QString version);
  };

#endif // LINUXSPECIFICATIONS_H
