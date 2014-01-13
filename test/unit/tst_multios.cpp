#include "tst_multios.h"

MultiOsTest::MultiOsTest(){}

void MultiOsTest::initTestCase(){
  operativeSystem = new MultiOs();
}

void MultiOsTest::ShouldReturnCoresNumberAndMustBeHigherThanZero(){

  QVERIFY2(operativeSystem->getCoresNum() > 0, "The number of cores obtained is 0, this is imposible!!");

}

void MultiOsTest::ShouldReturnProcessorSseAndMustBeHigherThanZero(){
  QVERIFY2(operativeSystem->getSseVersion()>0, "The processor sse obtained is 0");
}

void MultiOsTest::ShouldReturnScreenHeightAndMustBeHigherThanZero(){
  QVERIFY2(operativeSystem->getScreenHeight()>0, "The screen height obtained is 0, this is imposible!!");
}

void MultiOsTest::ShouldReturnScreenWidthAndMustBeHigherThanZero(){
  QVERIFY2(operativeSystem->getScreenWidth()>0, "The screen width obtained is 0, this is imposible!!");
}

void MultiOsTest::cleanupTestCase(){}
