#ifndef TST_CONFIGURATIONFILE_H
#define TST_CONFIGURATIONFILE_H

#include <QTest>
#include <QMap>
#include <QString>
#include "src/lib/utils/configurationfile.h"

class ConfigurationFileTest : public QObject{
  Q_OBJECT

  public:
    ConfigurationFileTest();
  private:
    QMap<QString,QString> result;
    ConfigurationFile *configuration;
  private Q_SLOTS:
    void initTestCase();
    void QMapOfReadedFileHaveAllElements();
    void QMapOfReadedFileReturnTheCorrectValue();
};

#endif // TST_CONFIGURATIONFILE_H
