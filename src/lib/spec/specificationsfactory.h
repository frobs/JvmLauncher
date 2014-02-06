#ifndef SPECIFICATIONSFACTORY_H
#define SPECIFICATIONSFACTORY_H

#include <QString>
#include <QHash>

//LinuxSpecifications class include linux class that includes some headers linux dependent
//If we include this class on windows for example it give us a error
#ifdef Q_OS_LINUX
  #include "src/lib/spec/linuxspecifications.h"
#endif

#ifdef Q_OS_MACX
  #include "src/lib/spec/macspecifications.h"
#endif

class SpecificationsFactory{
  public:
    SpecificationsFactory();
    static SystemSpecifications* specFactory(QVariantHash minimunSystemSpecifications);
};

#endif // SPECIFICATIONSFACTORY_H
