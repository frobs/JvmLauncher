#ifndef JVMPARAMETERS_H
#define JVMPARAMETERS_H

#include <QVariantHash>
#include "src/lib/utils/configurationfile.h"
#include "src/lib/utils/qtresourcesfileconstants.h"
#include "src/lib/utils/runtimeconstants.h"
#include "src/lib/utils/qvariantlistutils.h"

#ifdef Q_OS_LINUX
  #include "src/lib/os/linux.h"
#endif

#ifdef Q_OS_MACX
  #include "src/lib/os/mac.h"
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
    QString formatClassPath(QString classpathFileConfigurationValue);
    QString formatSse(QString parameterToRefactor);
    QString formatParallelThreads(QString parameterToRefactor);
    QString formatXss(QString parameterToRefactor);
    #ifdef Q_OS_LINUX
      Linux* operativeSystem = new Linux();
    #endif
    #ifdef Q_OS_MACX
      Mac* operativeSystem = new Mac();
    #endif
};

#endif // JVMPARAMETERS_H
