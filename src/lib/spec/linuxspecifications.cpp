#include "linuxspecifications.h"
#include "QDebug"

LinuxSpecifications::LinuxSpecifications(QVariantHash &minimunSystemRequeriments):SystemSpecifications(minimunSystemRequeriments){
  //How this class is the result of a factory we not need call to linux factory, operative system is already discriminated
  systemSpecificationsChecker = new Linux();
  getRuntimeSystemSpecifications();
}

void LinuxSpecifications::getRuntimeSystemSpecifications(){
  runtimeSystemSpecifications["free_ram"] = systemSpecificationsChecker->getFreeRam();
  runtimeSystemSpecifications["total_ram"] = systemSpecificationsChecker->getTotalRam();
  runtimeSystemSpecifications["screen_width"] = systemSpecificationsChecker->getScreenWidth();
  runtimeSystemSpecifications["screen_height"] = systemSpecificationsChecker->getScreenHeight();
  runtimeSystemSpecifications[getRuntimeDistribution()] = formatOsVersionNumber(systemSpecificationsChecker->getOsVersionNumber().toString);
  validate();
}

QString LinuxSpecifications::getRuntimeDistribution(){
  if (systemSpecificationsChecker->getFullOsVersion().toString().contains("Ubuntu")) return QString("ubuntu_version");
  return QString("kernel_version");
}

QVariantList LinuxSpecifications::formatOsVersionNumber(QString version){
  QVariantList formattedMajorAndMinor;
  QStringList majorAndMinor;
  majorAndMinor = version.split("-").at(0).split(".");
  foreach (QString value, majorAndMinor) {
      formattedMajorAndMinor.append(value.toInt());
  }
  return formattedMajorAndMinor;

}