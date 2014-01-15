#include "tst_linux.h"

LinuxTest::LinuxTest(){}

void LinuxTest::initTestCase(){
  LinuxOperativeSystem = new Linux();
}

void LinuxTest::getLinuxTotalRamReturnAValidValue(){
  QVERIFY2(LinuxOperativeSystem->getTotalRam() > 0, "Should be true");
}

void LinuxTest::getLinuxFreeRamReturnAValidValue(){
  QVERIFY2(LinuxOperativeSystem->getFreeRam()>0, "Should be true");
}

void LinuxTest::TotalRamMustBeHigherThanFreeRam(){
  QVERIFY2(LinuxOperativeSystem->getFreeRam() < LinuxOperativeSystem->getTotalRam(), "Should be true");
}

void LinuxTest::MultiOsInherittedCorrectly(){
  QVERIFY2(LinuxOperativeSystem->getCoresNum() > 0, "should be true");
}

void LinuxTest::UnixInherittedCorrectly(){
  QVERIFY2(!LinuxOperativeSystem->getOsArchitecture().isEmpty(), "should be true");
}
