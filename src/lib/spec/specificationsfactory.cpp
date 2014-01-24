#include "specificationsfactory.h"

SpecificationsFactory::SpecificationsFactory(){
}

SystemSpecifications* SpecificationsFactory::specFactory(QString type, QHash<QString,QString> minimunSystemSpecifications) {
  if(type == "linux") return new LinuxSpecifications(minimunSystemSpecifications);

}
