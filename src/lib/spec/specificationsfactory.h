#ifndef SPECIFICATIONSFACTORY_H
#define SPECIFICATIONSFACTORY_H

#include <QString>
#include <QMap>

//LinuxSpecifications class include linux class that includes some headers linux dependent
//If we include this class on windows for example it give us a error
#ifdef Q_OS_LINUX
  #include "src/lib/spec/linuxspecifications.h"
#endif

class SpecificationsFactory{
public:
  SpecificationsFactory();
  static SystemSpecifications* factory(QString type,QMap<QString,QString> minimunSystemSpecifications);
};

#endif // SPECIFICATIONSFACTORY_H
