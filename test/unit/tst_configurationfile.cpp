#include "tst_configurationfile.h"


ConfigurationFileTest::ConfigurationFileTest(){}

void ConfigurationFileTest::initTestCase(){
  const QString configurationFilePath = ":/test/config/minimun-system-requeriments.ini";
  QString group = "test";
  configuration = new ConfigurationFile(configurationFilePath,group);
  result = configuration->getReadedConfiguration();
}

void ConfigurationFileTest::QMapOfReadedFileHaveAllElements(){
  QVERIFY2(result.size() == 2,"should be true");
}

void ConfigurationFileTest::QMapOfReadedFileReturnTheCorrectValue(){
  QVERIFY2(result.value("total_ram")=="3000","should be true");
}
