#include "windowsspecifications.h"

WindowsSpecifications::WindowsSpecifications(QVariantHash &minimunSystemRequeriments):SystemSpecifications(minimunSystemRequeriments){
  //How this class is the result of a factory we doesn't need call to linux factory, operative system is already discriminated
  systemSpecificationsChecker = new Windows;
  getRuntimeSystemSpecifications();
}

void WindowsSpecifications::getRuntimeSystemSpecifications(){
  runtimeSystemSpecifications["free_ram"] = systemSpecificationsChecker->getFreeRam();
  runtimeSystemSpecifications["total_ram"] = systemSpecificationsChecker->getTotalRam();
  runtimeSystemSpecifications["screen_width"] = systemSpecificationsChecker->getScreenWidth();
  runtimeSystemSpecifications["screen_height"] = systemSpecificationsChecker->getScreenHeight();
  runtimeSystemSpecifications["windows_version"] = systemSpecificationsChecker->getOsVersionNumber();
  validate();
}
