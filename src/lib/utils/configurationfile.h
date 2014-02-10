#ifndef CONFIGURATIONFILE_H
#define CONFIGURATIONFILE_H

#include <QSettings>
#include <QString>
#include <QVariantList>
#include <QStringList>
#include <QVariantHash>
#include <typeinfo>

class ConfigurationFile{
  public:
    ConfigurationFile(const QString& filePath);
    ~ConfigurationFile();
    QVariantHash loadGroupKeyValue(QString& group);
    QVariantList getChildKeys(QString& group);
    QVariantList getSubGroups(QString& group);
    QVariantList getValues(QString& group);
  private:
    //I Use QHash because is faster than QHash for short lists of elements
    QVariantHash readedConfiguration;
    QSettings *settings;
    QVariantList m_subGroups;
    QVariantList m_keys;

};

#endif // CONFIGURATIONFILE_H
