#include "tst_linux.h"

LinuxTest::LinuxTest(){}

void LinuxTest::initTestCase(){
  LinuxOperativeSystem = new Linux();
}

void LinuxTest::getLinuxTotalRam(){
  QVERIFY2(LinuxOperativeSystem->getTotalRam() > 0, "Should be true");
}

void LinuxTest::getLinuxFreeRam(){
  QVERIFY2(LinuxOperativeSystem->getFreeRam()>0, "Should be true");
}

void LinuxTest::TotalRamMustBeHigherThanFreeRam(){
  QVERIFY2(LinuxOperativeSystem->getFreeRam() < LinuxOperativeSystem->getTotalRam(), "Should be true");
}

