#include "linux.h"

Linux::Linux(){}
Linux::~Linux(){}

unsigned long Linux::getTotalRam(){
  sysinfo(&memoryInformation);
  long totalRam= memoryInformation.totalram;
  totalRam *= memoryInformation.mem_unit;
  return totalRam/1000000;
}

unsigned long Linux::getFreeRam(){
  sysinfo(&memoryInformation);
  unsigned long freeRam= memoryInformation.freeram;
  freeRam *= memoryInformation.mem_unit;
  return freeRam/1000000;
}
