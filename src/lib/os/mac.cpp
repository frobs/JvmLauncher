#include "mac.h"

Mac::Mac(){}


QVariant Mac::getFreeRam(){
  QVariant freeRam;
  vm_size_t page_size;
  mach_port_t mach_port;
  mach_msg_type_number_t count;
  vm_statistics_data_t vm_stats;
  mach_port = mach_host_self();
  count = sizeof(vm_stats) / sizeof(natural_t);
  if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
    KERN_SUCCESS == host_statistics(mach_port, HOST_VM_INFO,
                                    (host_info_t)&vm_stats, &count)){
    freeRam = (int64_t)vm_stats.free_count * (int64_t)page_size/1024000;
    }
  return freeRam;
}

//
QVariant Mac::getTotalRam(){
  int mib[2] = { CTL_HW, HW_MEMSIZE };
  int64_t physical_memory;
  size_t length;
  length=sizeof(int64_t);
  sysctl(mib,2,&physical_memory,&length,NULL,0);
  return QVariant(physical_memory/1024000);
}
