#include <QtTest/QTest>
#include <QApplication>
#include <QString>
#include "tst_splashscreen.h"
#include "tst_multios.h"
#include "tst_unix.h"
#include "tst_linux.h"
#include "tst_configurationfile.h"
#include "tst_linuxspecifications.h"

int main(int argc, char* argv[]){
  QApplication app(argc,argv);

  //This main method is our test runner
  //we add here all test classes that we want run
  //remember that you need separate test operative system
  //depending, we can use  Qt Macros

//-------------ALL PLATFORMS TESTS-------------
  SplashScreenTest splashScreenTest;
  QTest::qExec(&splashScreenTest);

  MultiOsTest multiOsTest;
  QTest::qExec(&multiOsTest);

  ConfigurationFileTest configurationFileTest;
  QTest::qExec(&configurationFileTest);

//-------------WINDOWS TESTS-------------
  #ifdef Q_OS_WIN32
  #endif

//-------------UNIX TESTS(MACOSX and GNU/LINUX)-------------
  #ifdef Q_OS_UNIX
    UnixTest unixTest;
    QTest::qExec(&unixTest);
  #endif

//-------------MACOSX TESTS-------------
  #ifdef  Q_OS_MACX
  #endif

//-------------GNU/LINUX-------------
  #ifdef  Q_OS_LINUX
      LinuxTest linuxTest;
      QTest::qExec(&linuxTest);

      LinuxSpecificationsTest linuxSpecificationsTest;
      QTest::qExec(&linuxSpecificationsTest);
  #endif
}
