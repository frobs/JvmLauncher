#include "tst_splashscreen.h"

SplashScreenTest::SplashScreenTest(){}

void SplashScreenTest::initTestCase(){
  splash = SplashScreen::getInstance();
  splash2 = SplashScreen::getInstance();
}

void SplashScreenTest::TwoObjectsReferencesToTheSameInstance(){
  QVERIFY2(splash==splash2, "Should be true");
}

void SplashScreenTest::cleanupTestCase(){}
