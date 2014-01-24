#include "tst_linuxspecifications.h"

LinuxSpecificationsTest::LinuxSpecificationsTest(){

}

void LinuxSpecificationsTest::initTestCase(){
  QHash<QString,QString> minimunConfiguration;
  minimunConfiguration["total_ram"]="1";
  minimunConfiguration["free_ram"]="1";
  minimunConfiguration["ubuntu_version"]="10.04";
  minimunConfiguration["kernel_version"]="2.6";
  minimunConfiguration["screen_width"]="1024";
  minimunConfiguration["screen_height"]="768";
  spec = new LinuxSpecifications(minimunConfiguration);
}

void LinuxSpecificationsTest::validateSystemRequeriments(){
  QVERIFY2(spec->isValid()==true,"should be true");
}
