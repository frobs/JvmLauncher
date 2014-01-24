#include "linuxspecifications.h"

LinuxSpecifications::LinuxSpecifications(QHash<QString,QString> &minimunSystemRequeriments):SystemSpecifications(minimunSystemRequeriments){
  //How this class is the result of a factory we not need call to linux factory, operative system is already discriminated
  systemSpecificationsChecker = new Linux();
  getRuntimeSystemSpecifications();
}

void LinuxSpecifications::getRuntimeSystemSpecifications(){
  m_runtimeSystemSpecifications["free_ram"] = systemSpecificationsChecker->getFreeRam();
  m_runtimeSystemSpecifications["total_ram"] = systemSpecificationsChecker->getTotalRam();
  m_runtimeSystemSpecifications["screen_width"] = systemSpecificationsChecker->getScreenWidth();
  m_runtimeSystemSpecifications["screen_height"] = systemSpecificationsChecker->getScreenHeight();
  m_runtimeSystemSpecifications[getRuntimeDistribution()] = systemSpecificationsChecker->getOsVersionNumber();
  validate(m_runtimeSystemSpecifications);
}

QString LinuxSpecifications::getRuntimeDistribution(){
  if (systemSpecificationsChecker->getFullOsVersion().contains("Ubuntu")) return QString("ubuntu_version");
  return QString("linux_version");
}
