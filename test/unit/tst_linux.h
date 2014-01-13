#ifndef TST_LINUX_H
#define TST_LINUX_H

#include <QtTest>
#include "src/lib/operativesystem/linux.h"

class LinuxTest : public QObject{
  Q_OBJECT

  public:
    LinuxTest();
  private:
    Linux *LinuxOperativeSystem;
  private Q_SLOTS:
    void initTestCase();
    void getLinuxTotalRamReturnAValidValue();
    void getLinuxFreeRamReturnAValidValue();
    void TotalRamMustBeHigherThanFreeRam();
};

#endif // TST_LINUX_H
