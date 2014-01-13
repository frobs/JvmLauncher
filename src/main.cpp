#include <QApplication>
#include <QSplashScreen>
#include <QString>
#include "src/graphics/splashscreen.h"

int main (int argc, char* argv[]){
  QApplication app(argc,argv);
  QSplashScreen* splash = SplashScreen::getInstance();
  SplashScreen::setSplashMessage(QString(QLatin1String("Launching Launcher")));
  splash->show();

  app.exec();
  return EXIT_SUCCESS;
}
