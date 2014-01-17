#ifndef CONFIGURATIONFILE_H
#define CONFIGURATIONFILE_H

#include <QSettings>
#include <QStringList>
#include <typeinfo>

class ConfigurationFile{
  public:
    ConfigurationFile(const QString& filePath,QString& groupsToRead);
    QMap<QString,QString> getReadedConfiguration();
  private:
    void readFile();
    //I Use QMAP because is faster than QHash for short lists of elements
    QMap<QString,QString> readedConfiguration;
    QString configurationFilePath;
    QString group;

};

#endif // CONFIGURATIONFILE_H
