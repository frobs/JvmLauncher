#include <QApplication>
#include <QSplashScreen>
#include <QString>
#include "src/graphics/splashscreen.h"
#include "src/lib/os/osruntime.h"
#include "src/lib/utils/configurationfile.h"

int main (int argc, char* argv[]){
  //TO-DO Create a QCoreApplication instead of QApplication if SplashScreen is disabled
  QApplication app(argc,argv);
  QSplashScreen* splash;
  OSRuntime* operativeSystem;
  ConfigurationFile* minimunOSRequerimentsConfiguration;
  QString currentOs;
  //I use QMap because this is faster than QHash for small lists.
  QMap<QString,QString> minimunOSRequeriments;


  operativeSystem = new OSRuntime();
  currentOs = operativeSystem->getOSRuntime();
  minimunOSRequerimentsConfiguration = new ConfigurationFile(QString(PATH_TO_MINIMUN_SYSTEM_REQUERIMENTS_FILE),currentOs);
  splash = SplashScreen::getInstance();


  minimunOSRequeriments = minimunOSRequerimentsConfiguration->getReadedConfiguration();


  SplashScreen::setSplashMessage(QString("Launching Launcher"));
  splash->show();

  app.exec();
  return EXIT_SUCCESS;
}
