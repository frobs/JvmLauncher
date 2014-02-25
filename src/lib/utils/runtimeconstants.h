#ifndef RUNTIMECONSTANTS_H
#define RUNTIMECONSTANTS_H

#include <QDir>

#ifdef Q_OS_UNIX
  const QString CLASSPATH_SEPARATOR = ":";
#endif
#ifdef Q_OS_WIN32
  const QString CLASSPATH_SEPARATOR = ";";
#endif

const QString CURRENT_APPLICATION_PATH = QDir::currentPath();


#endif // RUNTIMECONSTANTS_H
