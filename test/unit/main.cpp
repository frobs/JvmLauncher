#include <QtTest/QTest>
#include <QApplication>
#include "tst_splashscreen.h"
#include "tst_multios.h"
#include "tst_unix.h"
#include "tst_linux.h"

int main(int argc, char* argv[]){
  QApplication app(argc,argv);

  SplashScreenTest splashScreenTest;
  QTest::qExec(&splashScreenTest);

  MultiOsTest multiOsTest;
  QTest::qExec(&multiOsTest);

  UnixTest unixTest;
  QTest::qExec(&unixTest);

  LinuxTest linuxTest;
  QTest::qExec(&linuxTest);
}
