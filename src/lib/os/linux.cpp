#include "linux.h"

Linux::Linux(){}
Linux::~Linux(){}

QString Linux::getTotalRam(){
  sysinfo(&memoryInformation);
  long totalRam= memoryInformation.totalram;
  totalRam *= memoryInformation.mem_unit;
  totalRam = totalRam/1000000;
  return QString::number(totalRam);
}

QString Linux::getFreeRam(){
  sysinfo(&memoryInformation);
  unsigned long freeRam= memoryInformation.freeram;
  freeRam *= memoryInformation.mem_unit;
  freeRam = freeRam/1000000;
  return QString::number(freeRam);
}
