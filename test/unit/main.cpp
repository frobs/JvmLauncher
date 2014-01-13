#include <QtTest/QTest>
#include <QApplication>
#include "tst_splashscreen.h"
#include "tst_multios.h"

int main(int argc, char* argv[]){
  QApplication app(argc,argv);

  SplashScreenTest splashScreenTest;
  QTest::qExec(&splashScreenTest);

  MultiOsTest multiOsTest;
  QTest::qExec(&multiOsTest);

}
