#ifndef TST_UNIX_H
#define TST_UNIX_H

#include <QtTest>
#include "src/lib/operativesystem/unix.h"

class UnixTest : public QObject{
  Q_OBJECT

  public:
    UnixTest();
  private:
    Unix *UnixOperativeSystem;
  private Q_SLOTS:
    void initTestCase();
    void OsArchitectureIsNotEmpty();
    void OsVersionNumberIsNotEmpty();
    void OsFullVersionIsNotEmpty();
    void OsArchitectureIsNotNull();
    void OsVersionNumberIsNotNull();
    void OsFullVersionIsNotNull();
};

#endif // TST_UNIX_H
