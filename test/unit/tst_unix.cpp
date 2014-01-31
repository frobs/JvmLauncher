#include "tst_unix.h"

UnixTest::UnixTest(){}

void UnixTest::initTestCase(){
  UnixOperativeSystem = new Unix();
}

void UnixTest::OsArchitectureIsNotEmpty(){
  QVERIFY2(!UnixOperativeSystem->getOsArchitecture().toString().isEmpty(), "The OS architecture received is empty");
}

void UnixTest::OsVersionNumberIsNotEmpty(){
  QVERIFY2(!UnixOperativeSystem->getOsVersionNumber().toList().isEmpty(), "The OS version number received is empty");
}

void UnixTest::OsFullVersionIsNotEmpty(){
  QVERIFY2(!UnixOperativeSystem->getFullOsVersion().toString().isEmpty(), "The OS full version received is empty");
}


void UnixTest::OsArchitectureIsNotNull(){
  QVERIFY2(!UnixOperativeSystem->getOsArchitecture().toString().isNull(), "The OS architecture received is null");
}

void UnixTest::OsFullVersionIsNotNull(){
  QVERIFY2(!UnixOperativeSystem->getFullOsVersion().toString().isNull(), "The OS full version received is null");
}

