#include "tst_unix.h"

UnixTest::UnixTest(){}

void UnixTest::initTestCase(){
  UnixOperativeSystem = new Unix();
}

void UnixTest::ShouldReturnOsArchitectureQStringWithLenghtHigherThanZero(){
  QVERIFY2(!UnixOperativeSystem->getOsArchitecture().isEmpty(), "The OS architecture received is empty");
}

void UnixTest::ShouldReturnOsVersionNumberQStringWithLenghtHigherThanZero(){
  QVERIFY2(!UnixOperativeSystem->getOsVersionNumber().isEmpty(), "The OS version number received is empty");
}

void UnixTest::ShouldReturnOsFullVersionQStringWithLenghtHigherThanZero(){
  QVERIFY2(!UnixOperativeSystem->getFullOsVersion().isEmpty(), "The OS full version received is empty");
}


void UnixTest::ShouldReturnOsArchitectureQStringInitialized(){
  QVERIFY2(!UnixOperativeSystem->getOsArchitecture().isNull(), "The OS architecture received is null");
}

void UnixTest::ShouldReturnOsVersionNumberQStringInitilized(){
  QVERIFY2(!UnixOperativeSystem->getOsVersionNumber().isNull(), "The OS version number received is null");
}

void UnixTest::ShouldReturnOsFullVersionQStringInitiliazed(){
  QVERIFY2(!UnixOperativeSystem->getFullOsVersion().isNull(), "The OS full version received is null");
}


void UnixTest::cleanupTestCase(){}
