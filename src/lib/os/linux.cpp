#include "linux.h"

Linux::Linux(){}
Linux::~Linux(){}

QVariant Linux::getTotalRam(){
  sysinfo(&memoryInformation);
  long long totalRam= memoryInformation.totalram;
  totalRam *= memoryInformation.mem_unit;
  return totalRam/1000000;
}

QVariant Linux::getFreeRam(){
  sysinfo(&memoryInformation);
  long long freeRam= memoryInformation.freeram;
  freeRam *= memoryInformation.mem_unit;
  return freeRam/1000000;
}
