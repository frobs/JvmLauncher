#include "tst_multios.h"

MultiOsTest::MultiOsTest(){}

void MultiOsTest::initTestCase(){
  operativeSystem = new MultiOs();
}

void MultiOsTest::getProcessorCoresNumberReturnAValidValue(){
  QVERIFY2(operativeSystem->getCoresNum().toInt() > 0, "should be true");
}

void MultiOsTest::getProcessorSseVersionReturnAValidValue(){
  QVERIFY2(operativeSystem->getSseVersion().toInt()>0, "should be true");
}

void MultiOsTest::getScreenHeightReturnAValidValue(){
  QVERIFY2(operativeSystem->getScreenHeight().toInt()>0, "should be true");
}

void MultiOsTest::getScreenWidthReturnAValidValue(){
  QVERIFY2(operativeSystem->getScreenWidth().toInt()>0, "should be true");
}

