#ifndef TST_LINUX_H
#define TST_LINUX_H

#include <QtTest>
#include <QString>
#include "src/lib/os/linux.h"

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
    void MultiOsInherittedCorrectly();
    void UnixInherittedCorrectly();
};

#endif // TST_LINUX_H
