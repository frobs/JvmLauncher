#include "specificationsfactory.h"

SpecificationsFactory::SpecificationsFactory(){
}


SystemSpecifications* SpecificationsFactory::factory(QString type, QMap<QString,QString> minimunSystemSpecifications) {
  if(type == "linux") return new LinuxSpecifications(minimunSystemSpecifications);

}
