#include "tst_linuxspecifications.h"

LinuxSpecificationsTest::LinuxSpecificationsTest(){

}

void LinuxSpecificationsTest::initTestCase(){
  QVariantList kernel_version;
  kernel_version<<2<<5;
  QVariantList ubuntu_version;
  ubuntu_version<<10<<4;
  QVariantList jre_version;
  jre_version<<1<<7;
  QHash<QString,QVariant> minimunConfiguration;
  minimunConfiguration["total_ram"]=QVariant(1);
  minimunConfiguration["free_ram"]=QVariant(1);
  minimunConfiguration["ubuntu_version"]= ubuntu_version;
  minimunConfiguration["kernel_version"]= kernel_version;
  minimunConfiguration["screen_width"]=QVariant(1024);
  minimunConfiguration["screen_height"]=QVariant(768);
  minimunConfiguration["jre_version"]=jre_version;
  spec = new LinuxSpecifications(minimunConfiguration);
}

void LinuxSpecificationsTest::validateSystemRequeriments(){
  QVERIFY2(spec->isValid()==true,"should be true");
}
