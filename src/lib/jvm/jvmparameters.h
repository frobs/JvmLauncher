#ifndef JVMPARAMETERS_H
#define JVMPARAMETERS_H

#include <QHash>
#include "src/lib/utils/configurationfile.h"
#include "src/lib/utils/qtresourcesfileconstants.h"
#include "src/lib/utils/runtimeconstants.h"
#include <iostream>

#ifdef Q_OS_LINUX
  #include "src/lib/os/linux.h"
#endif

using namespace std;
class JvmParameters{
  public:
    JvmParameters(QString& platform);
    ~JvmParameters();
    QStringList getJvmParameters();

  private:
    QString m_platform;
    QString absoluteGroupPath;
    QStringList m_formattedParameters;
    QHash<QString,QString> m_parameterHash;
    ConfigurationFile* configFileReader;
    void copyStaticSettings(QString& groupAbsolutePath);
    void copyStaticSettingsOSArchitectureDependent();
    void generateJvmParameters();
    void generateDynamicParameters();
    QString formatClassPath(QString& classpathFileConfigurationValue);
    QString formatSse(QString& parameterToRefactor);
    QString formatParallelThreads(QString& parameterToRefactor);
    QString formatXss(QString& parameterToRefactor);
    #ifdef Q_OS_LINUX
      Linux* operativeSystem = new Linux();
    #endif
};

#endif // JVMPARAMETERS_H
