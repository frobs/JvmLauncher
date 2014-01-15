#ifndef TST_LINUXSPECIFICATIONS_H
#define TST_LINUXSPECIFICATIONS_H

#include <QtTest>

class LinuxSpecificationsTest : public QObject{
  Q_OBJECT

  public:
    LinuxSpecificationsTest();
  private:
    LinuxSpecifications *LinuxOperativeSystem;
  private Q_SLOTS:
    void initTestCase();
};

#endif // TST_LINUXSPECIFICATIONS_H
