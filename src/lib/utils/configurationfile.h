#ifndef CONFIGURATIONFILE_H
#define CONFIGURATIONFILE_H

#include <QSettings>
#include <QString>
#include <QStringList>
#include <typeinfo>

class ConfigurationFile{
  public:
    ConfigurationFile(const QString& filePath);
    ~ConfigurationFile();
    QHash<QString,QString> loadGroupKeyValue(QString& group);
    QStringList getChildKeys(QString& group);
    QStringList getSubGroups(QString& group);
    QStringList getValues(QString& group);
  private:
    //I Use QHash because is faster than QHash for short lists of elements
    QHash<QString,QString> readedConfiguration;
    QSettings *settings;
    QStringList m_subGroups;
    QStringList m_keys;
};

#endif // CONFIGURATIONFILE_H
