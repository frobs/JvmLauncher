#include "windows.h"

Windows::Windows(){

}

QVariant Windows::getFreeRam(){
  statex.dwLength=sizeof(statex);
  GlobalMemoryStatusEx(&statex);
  return statex.ullTotalPhys/1024000;
}

QVariant Windows::getTotalRam(){
  statex.dwLength=sizeof(statex);
  GlobalMemoryStatusEx(&statex);
  return statex.ullAvailPhys/1024000;
}

QVariant Windows::getOsVersionNumber(){
  return QSysInfo::WindowsVersion;
}

QVariant Windows::getOsArchitecture(){
    BOOL res = FALSE;
    // When this application is compiled as a 32-bit app,
    // and run on a native 64-bit system, Windows will run
    // this application under WOW64.  WOW64 is the Windows-
    // on-Windows subsystem that lets native 32-bit applications
    // run in 64-bit land.  This calls the kernel32.dll
    // API to see if this process is running under WOW64.
    // If it is running under WOW64, then that clearly means
    // this 32-bit application is running on a 64-bit OS,
    // and IsWow64Process will return true.
    IW64PFP IW64P = (IW64PFP)GetProcAddress(GetModuleHandle (L"kernel32"), "IsWow64Process");

    if(IW64P != NULL){
      IW64P(GetCurrentProcess(), &res);
    }
    if(res){
        return "x86_64";
    }
    return "i386";
}
