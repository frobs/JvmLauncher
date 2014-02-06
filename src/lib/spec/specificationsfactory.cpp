#include "specificationsfactory.h"

SpecificationsFactory::SpecificationsFactory(){
}

SystemSpecifications* SpecificationsFactory::specFactory(QVariantHash minimunSystemSpecifications) {
  //We can't use a type parameter, "if" conditional is evaluate when compile
    //how LinuxSpecifications class is not loaded this launch error
    //We need use Macros to determine operative system where we are compiling
  #ifdef Q_OS_LINUX
    return new LinuxSpecifications(minimunSystemSpecifications);
  #endif
  #ifdef Q_OS_MACX
    return new MacSpecifications(minimunSystemSpecifications);
  #endif
}
