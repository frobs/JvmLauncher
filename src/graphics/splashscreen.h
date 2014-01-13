#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPixmap>

class SplashScreen : public QSplashScreen{
  Q_OBJECT
public:
  static SplashScreen *getInstance(){
    if(MySplash == NULL){
      QPixmap image(":/resources/img/SplashImage.jpg");
      MySplash = new SplashScreen();
      MySplash->setPixmap(image);
    }
    return MySplash;
  }
  static void setSplashMessage(QString message);
  ~SplashScreen();
private:
  explicit SplashScreen(QWidget *parent = 0);
  static SplashScreen* MySplash;
signals:

public slots:

};

#endif // SPLASHSCREEN_H
