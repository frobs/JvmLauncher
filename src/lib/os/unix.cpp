#include "unix.h"


Unix::Unix(){}
Unix::~Unix(){}

QVariant Unix::getOsArchitecture(){
  struct utsname unameData;
  uname(&unameData);
  return unameData.machine;
}

QVariant Unix::getOsVersionNumber(){
  struct utsname unameData;
  uname(&unameData);
  return unameData.release;
}

QVariant Unix::getFullOsVersion(){
  struct utsname unameData;
  uname(&unameData);
  return unameData.version;
}
