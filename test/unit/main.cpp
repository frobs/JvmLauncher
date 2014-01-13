#include <QtTest/QTest>
#include "tst_splashscreen.h"
#include <QApplication>

int main(int argc, char* argv[]){
  QApplication app(argc,argv);

  SplashScreenTest splashScreenTest ;
  QTest::qExec(&splashScreenTest);

}
