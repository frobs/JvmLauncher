#include <QApplication>
#include <QSplashScreen>
#include <QString>
#include "src/graphics/splashscreen.h"
#include "src/lib/os/osruntime.h"
#include "src/lib/utils/configurationfile.h"
#include "src/lib/spec/specificationsfactory.h"
#include "src/lib/jvm/virtualmachine.h"


int main (int argc, char* argv[]){
  //TO-DO Create a QCoreApplication instead of QApplication if SplashScreen is disabled
  QApplication app(argc,argv);
  //We show the splash at the beginning of time
  QSplashScreen* splash;
  splash = SplashScreen::getInstance();
  SplashScreen::setSplashMessage(QString("Launching Launcher"));
  splash->show();

  OSRuntime* operativeSystemRuntimeChecker;
  ConfigurationFile* mininimunOSRequerimentsReader;
  SystemSpecifications* specifications;
  VirtualMachine* jvmLauncher;
  QString currentOs;
  QHash<QString,QVariant> minimunOSRequerimentsHash;
  bool systemSpecificationsAreValidated;

  operativeSystemRuntimeChecker = new OSRuntime();
  currentOs = operativeSystemRuntimeChecker->getOSRuntime();
  mininimunOSRequerimentsReader = new ConfigurationFile(QString(PATH_TO_MINIMUN_SYSTEM_REQUERIMENTS_FILE));
  minimunOSRequerimentsHash = mininimunOSRequerimentsReader->loadGroupKeyValue(currentOs);
  specifications = SpecificationsFactory::specFactory(currentOs,minimunOSRequerimentsHash);
  systemSpecificationsAreValidated = specifications->isValid();

  //If the launcher came here all system specifications have been validated
  if (systemSpecificationsAreValidated){
    delete(operativeSystemRuntimeChecker);
    delete(mininimunOSRequerimentsReader);
    delete(specifications);

    jvmLauncher = new VirtualMachine(currentOs,minimunOSRequerimentsHash["jre_version"]);
    jvmLauncher->start();

  }
  app.exec();
  return EXIT_SUCCESS;
}
