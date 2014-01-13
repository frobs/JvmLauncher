#include "splashscreen.h"

SplashScreen* SplashScreen::MySplash = NULL;

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
