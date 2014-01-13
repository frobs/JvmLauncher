#include "unix.h"

Unix::Unix(){}
Unix::~Unix(){}

QString Unix::getOsArchitecture(){
  uname(&unameData);
  return unameData.machine;
}

QString Unix::getOsVersionNumber(){
  uname(&unameData);
  return unameData.release;
}

QString Unix::getFullOsVersion(){
  uname(&unameData);
  return unameData.version;
}
