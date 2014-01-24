#ifndef LINUXSPECIFICATIONS_H
#define LINUXSPECIFICATIONS_H

#include "src/lib/spec/systemspecifications.h"
#include "src/lib/os/linux.h"

class LinuxSpecifications : public SystemSpecifications{
  public:
    LinuxSpecifications(QHash<QString,QString> &minimunSystemRequeriments);

  private:
    void getRuntimeSystemSpecifications();
    Linux* systemSpecificationsChecker;
    QHash<QString,QString> m_runtimeSystemSpecifications;
    QString getRuntimeDistribution();
  };

#endif // LINUXSPECIFICATIONS_H
