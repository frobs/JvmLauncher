#ifndef SPECIFICATIONSFACTORY_H
#define SPECIFICATIONSFACTORY_H

#include <QString>
#include <QHash>

//LinuxSpecifications class include linux class that includes some headers linux dependent
//If we include this class on windows for example it give us a error
#ifdef Q_OS_LINUX
  #include "src/lib/spec/linuxspecifications.h"
#endif

class SpecificationsFactory{
  public:
    SpecificationsFactory();
    static SystemSpecifications* specFactory(QString type,QHash<QString,QString> minimunSystemSpecifications);
};

#endif // SPECIFICATIONSFACTORY_H
