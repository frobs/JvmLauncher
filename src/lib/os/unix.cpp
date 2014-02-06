#include "unix.h"


Unix::Unix(){}
Unix::~Unix(){}

QVariant Unix::getOsArchitecture(){
  uname(&unameData);
  return unameData.machine;
}

QVariant Unix::getOsVersionNumber(){
  uname(&unameData);
  return unameData.release;
}

QVariant Unix::getFullOsVersion(){
  uname(&unameData);
  return unameData.version;
}
