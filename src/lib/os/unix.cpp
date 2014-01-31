#include "unix.h"

Unix::Unix(){}
Unix::~Unix(){}

QVariant Unix::getOsArchitecture(){
  uname(&unameData);
  return unameData.machine;
}

QVariant Unix::getOsVersionNumber(){
  //We return a QriantQVariantList that contains
  //the integers of version and subversion
  //why integers? integers is the more secure way of compare
  //value.
  uname(&unameData);
  QString fullOSVersion = unameData.release;
  QVariantList formattedMajorAndMinor;
  QStringList majorAndMinor;
  majorAndMinor = fullOSVersion.split("-").at(0).split(".");
  foreach (QString value, majorAndMinor) {
      formattedMajorAndMinor.append(value.toInt());
  }
  return formattedMajorAndMinor;
}

QVariant Unix::getFullOsVersion(){
  uname(&unameData);
  return unameData.version;
}
