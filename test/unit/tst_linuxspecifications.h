#ifndef TST_LINUXSPECIFICATIONSTEST_H
#define TST_LINUXSPECIFICATIONSTEST_H

#include <QtTest>
#include <QString>
#include "src/lib/spec/linuxspecifications.h"

class LinuxSpecificationsTest: public QObject{
  Q_OBJECT

  public:
    LinuxSpecificationsTest();
  private:
    LinuxSpecifications *spec;

  private Q_SLOTS:
    void initTestCase();
    void validateSystemRequeriments();
  };

#endif // TST_LINUXSPECIFICATIONSTEST_H
