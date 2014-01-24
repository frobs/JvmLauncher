#include "configurationfile.h"

ConfigurationFile::ConfigurationFile(const QString& filePath){
  settings = new QSettings(filePath,QSettings::IniFormat);
}

ConfigurationFile::~ConfigurationFile(){
  delete(settings);
}

QHash<QString,QString> ConfigurationFile::loadGroupKeyValue(QString& group){
  settings->beginGroup(group);
  foreach (QString key, settings->childKeys()) {
    readedConfiguration[key]=settings->value(key).toString();
  }
  settings->endGroup();
  return readedConfiguration;
}

QStringList ConfigurationFile::getValues(QString& group){
  QStringList values;
  QHash<QString,QString> keysAndValues;
  keysAndValues = loadGroupKeyValue(group);
  QHash<QString, QString>::iterator i;
  for (i = keysAndValues.begin(); i != keysAndValues.end(); ++i){
    values.append(i.value());
  }
  return values;
}


QStringList ConfigurationFile::getChildKeys(QString& group){
  settings->beginGroup("fridge/linux");
    m_keys = settings->childKeys();
  settings->endGroup();
  return m_keys;
}

QStringList ConfigurationFile::getSubGroups(QString& group){
  settings->beginGroup(group);
    m_subGroups = settings->childGroups();
  settings->endGroup();
  return m_subGroups;
}
