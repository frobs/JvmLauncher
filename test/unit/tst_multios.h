#ifndef TST_MULTIOS_H
#define TST_MULTIOS_H

#include <QString>
#include <QtTest>
#include "src/lib/operativesystem/multios.h"

class MultiOsTest : public QObject{
  Q_OBJECT

  public:
    MultiOsTest();
  private:
    MultiOs *operativeSystem;
  private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void ShouldReturnCoresNumberAndMustBeHigherThanZero();
    void ShouldReturnProcessorSseAndMustBeHigherThanZero();
    void ShouldReturnScreenWidthAndMustBeHigherThanZero();
    void ShouldReturnScreenHeightAndMustBeHigherThanZero();

};

#endif // TST_MULTIOS_H
