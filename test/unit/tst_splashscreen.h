#ifndef TST_SPLASHSCREEN_H
#define TST_SPLASHSCREEN_H

#include <QString>
#include <QtTest>
#include <QApplication>
#include <QPixmap>
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
    void cleanupTestCase();
    void ShouldReturnTrueIfTwoInstanceOfSplashScreenHaveTheSameReference();
};

#endif // TST_SPLASHSCREEN_H
