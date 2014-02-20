#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPixmap>
#include "../lib/utils/qtresourcesfileconstants.h"

class SplashScreen : public QSplashScreen{
  Q_OBJECT
  public:
    static SplashScreen* getInstance();
    static void setSplashMessage(QString message);
    ~SplashScreen();
  private:
    explicit SplashScreen(QWidget *parent = 0);
    static SplashScreen* MySplash;
  signals:

  public slots:

};

#endif // SPLASHSCREEN_H
