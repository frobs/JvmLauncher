#ifndef JVMPARAMETERS_H
#define JVMPARAMETERS_H

#include <QVariantHash>
#include "../utils/configurationfile.h"
#include "../utils/qtresourcesfileconstants.h"
#include "../utils/runtimeconstants.h"
#include "../utils/qvariantlistutils.h"

#ifdef Q_OS_LINUX
  #include "src/lib/os/linux.h"
#endif

#ifdef Q_OS_MACX
  #include "src/lib/os/mac.h"
#endif
#ifdef Q_OS_WIN
  #include "../os/windows.h"
#endif

using namespace std;
class JvmParameters{
  public:
    JvmParameters(QString& platform);
    ~JvmParameters();
    QStringList get();

  private:
    QString m_platform;
    QString absoluteGroupPath;
    QStringList m_formattedParameters;
    QVariantHash m_parameterHash;
    ConfigurationFile* configFileReader;
    void copyStaticSettings(QString& groupAbsolutePath);
    void copyStaticSettingsOSArchitectureDependent();
    void generateJvmParameters();
    void generateDynamicParameters();
    void initilizeOperativeSystemObject();
    QString formatClassPath(QString classpathFileConfigurationValue);
    QString formatSse(QString parameterToRefactor);
    QString formatParallelThreads(QString parameterToRefactor);
    QString formatXss(QString parameterToRefactor);
    #ifdef Q_OS_LINUX
      Linux* operativeSystem;
    #endif
    #ifdef Q_OS_MACX
      Mac* operativeSystem;
    #endif
    #ifdef Q_OS_WIN
      Windows* operativeSystem;
    #endif
};

#endif // JVMPARAMETERS_H
