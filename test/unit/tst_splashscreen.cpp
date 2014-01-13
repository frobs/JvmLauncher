#include "tst_splashscreen.h"

SplashScreenTest::SplashScreenTest(){}

void SplashScreenTest::initTestCase(){
  splash = SplashScreen::getInstance();
  splash2 = SplashScreen::getInstance();
}

void SplashScreenTest::ShouldReturnTrueIfTwoInstanceOfSplashScreenHaveTheSameReference(){
  QVERIFY2(splash==splash2, "The instance returned from two splashScreen objects aren't the same");
}

void SplashScreenTest::cleanupTestCase(){}
