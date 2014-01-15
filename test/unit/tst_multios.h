#ifndef TST_MULTIOS_H
#define TST_MULTIOS_H

#include <QtTest>
#include "src/lib/os/multios.h"

class MultiOsTest : public QObject{
  Q_OBJECT

  public:
    MultiOsTest();
  private:
    MultiOs *operativeSystem;
  private Q_SLOTS:
    void initTestCase();
    void getProcessorCoresNumberReturnAValidValue();
    void getProcessorSseVersionReturnAValidValue();
    void getScreenWidthReturnAValidValue();
    void getScreenHeightReturnAValidValue();

};

#endif // TST_MULTIOS_H
