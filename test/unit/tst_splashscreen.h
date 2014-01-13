#ifndef TST_SPLASHSCREEN_H
#define TST_SPLASHSCREEN_H

#include <QtTest>
#include "src/graphics/splashscreen.h"

class SplashScreenTest : public QObject{
  Q_OBJECT

  public:
    SplashScreenTest();

  private:
    QSplashScreen* splash;
    QSplashScreen* splash2;
  private Q_SLOTS:
    void initTestCase();
    void TwoObjectsReferencesToTheSameInstance();
};

#endif // TST_SPLASHSCREEN_H
