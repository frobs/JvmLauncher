#include "multios.h"

MultiOs::MultiOs(){}

MultiOs::~MultiOs(){}

QVariant MultiOs::getScreenWidth(){
  return qApp->desktop()->width();
}

QVariant MultiOs::getScreenHeight(){
  return qApp->desktop()->height();
}

QVariant MultiOs::getCoresNum(){
  cpuID(1, regs);
  return (regs[1] >> 16) & 0xff; // EBX[23:16]
  }

QVariant MultiOs::getSseVersion(){
  QVariant sseVersion;
    //detect sse-sse3
    cpuID(0x00000001,regs);

    if((regs[3]>>25)  & 0x1){//sse
      sseVersion=1;
      }
    if((regs[3]>>26) & 0x1){//sse2
      sseVersion=2;
      }
    if((regs[2]>>0) & 0x1){//sse3
      sseVersion=3;
      }
    if((regs[2]>>19) & 0x1){//sse4
      sseVersion=4;
      }
  return sseVersion;
}

void MultiOs::cpuID(unsigned i, unsigned regs[4]) {
#ifdef _WIN32
    __cpuid((int *)regs, (int)i);
#else
  asm volatile
    ("cpuid" : "=a" (regs[0]), "=b" (regs[1]), "=c" (regs[2]), "=d" (regs[3])
     : "a" (i), "c" (0));
  // ECX is set to zero for CPUID function 4
#endif
}
