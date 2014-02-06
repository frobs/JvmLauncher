#include "macspecifications.h"
#include <QDebug>

MacSpecifications::MacSpecifications(QVariantHash& minimunSystemRequeriments){
  //How this class is the result of a factory we not need call to linux factory, operative system is already discriminated
  systemSpecificationsChecker = new Mac();
  getRuntimeSystemSpecifications();
}

void MacSpecifications::getRuntimeSystemSpecifications(){
  runtimeSystemSpecifications["free_ram"] = systemSpecificationsChecker->getFreeRam();
  runtimeSystemSpecifications["total_ram"] = systemSpecificationsChecker->getTotalRam();
  runtimeSystemSpecifications["screen_width"] = systemSpecificationsChecker->getScreenWidth();
  runtimeSystemSpecifications["screen_height"] = systemSpecificationsChecker->getScreenHeight();
  runtimeSystemSpecifications["macos_version"] = formatOsVersionNumber(systemSpecificationsChecker->getOsVersionNumber().toString());
  validate();

}

QVariantList MacSpecifications::formatOsVersionNumber(QString version){
  //uname.release on Mac return the version composed by three numbers but we only use 2 major and minor version
  QVariantList formattedMajorAndMinor;
  QStringList majorAndMinor;
  majorAndMinor = version.split(".");
  for(int i = 0; i < 2;i++){
      formattedMajorAndMinor.append(majorAndMinor.at(i).toInt());
  }
  return formattedMajorAndMinor;
}
