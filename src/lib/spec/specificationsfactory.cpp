#include "specificationsfactory.h"

SpecificationsFactory::SpecificationsFactory(){
}

SystemSpecifications* SpecificationsFactory::specFactory(QString type, QVariantHash minimunSystemSpecifications) {
  if(type == "linux") return new LinuxSpecifications(minimunSystemSpecifications);
}
