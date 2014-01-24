#include "tst_configurationfile.h"


ConfigurationFileTest::ConfigurationFileTest(){}

void ConfigurationFileTest::initTestCase(){
  const QString configurationFilePath = ":/test/config/minimun-system-requeriments.ini";
  QString group = "test";
  configuration = new ConfigurationFile(configurationFilePath);
  result = configuration->loadGroupKeyValue(group);
}

void ConfigurationFileTest::QHashOfReadedFileHaveAllElements(){
  QVERIFY2(result.size() == 2,"should be true");
}

void ConfigurationFileTest::QHashOfReadedFileReturnTheCorrectValue(){
  QVERIFY2(result.value("total_ram")=="3000","should be true");
}
