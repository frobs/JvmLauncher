#ifndef MACSPECIFICATIONS_H
#define MACSPECIFICATIONS_H

#include <QVariantHash>
#include "src/lib/spec/systemspecifications.h"
#include "src/lib/os/mac.h"

class MacSpecifications : public SystemSpecifications{
  public:
    MacSpecifications(QVariantHash& minimunSystemRequeriments);
  private:
    QVariantList formatOsVersionNumber(QString version);
    void getRuntimeSystemSpecifications();
    Mac* systemSpecificationsChecker;
};

#endif // MACSPECIFICATIONS_H
