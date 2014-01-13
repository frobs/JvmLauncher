#include "multios.h"

MultiOs::MultiOs(){}

MultiOs::~MultiOs(){
  delete(regs);
}

unsigned int MultiOs::getScreenWidth(){
  return qApp->desktop()->width();
}

unsigned int MultiOs::getScreenHeight(){
  return qApp->desktop()->height();
}

unsigned int MultiOs::getCoresNum(){
  cpuID(1, regs);
 return (regs[1] >> 16) & 0xff; // EBX[23:16];
}

unsigned int MultiOs::getSseVersion(){
  cpuID(0x00000001,regs);
  unsigned int sseVersion = 0;
  if((regs[3]>>25)  & 0x1){
    sseVersion=1;
    }
  else if((regs[3]>>26) & 0x1){
    sseVersion=2;
    }
  else if((regs[2]>>0) & 0x1){
    sseVersion=3;
    }
  else if((regs[2]>>19) & 0x1){
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
