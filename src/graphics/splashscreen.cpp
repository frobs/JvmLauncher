#include "splashscreen.h"

SplashScreen* SplashScreen::MySplash = NULL;

SplashScreen* SplashScreen::getInstance(){
  if(MySplash == NULL){
    QPixmap image(PATH_TO_SPLASHSCREEN_IMAGE);
    MySplash = new SplashScreen();
    MySplash->setPixmap(image);
  }
  return MySplash;
}

//We need call QWidget constructor If we want use  QWidget methods from outside of this class
SplashScreen::SplashScreen(QWidget *parent) :
  QSplashScreen(parent){
}

SplashScreen::~SplashScreen(){
  delete(SplashScreen::MySplash);
}

void SplashScreen::setSplashMessage(QString message){
  SplashScreen::MySplash->showMessage(message,
                      Qt::AlignLeft | Qt::AlignBottom, Qt::black);
}
