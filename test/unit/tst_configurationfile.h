#ifndef TST_CONFIGURATIONFILE_H
#define TST_CONFIGURATIONFILE_H

#include <QTest>
#include <QHash>
#include <QString>
#include "src/lib/utils/configurationfile.h"

class ConfigurationFileTest : public QObject{
  Q_OBJECT

  public:
    ConfigurationFileTest();
  private:
    QHash<QString,QString> result;
    ConfigurationFile *configuration;
  private Q_SLOTS:
    void initTestCase();
    void QHashOfReadedFileHaveAllElements();
    void QHashOfReadedFileReturnTheCorrectValue();
};

#endif // TST_CONFIGURATIONFILE_H
