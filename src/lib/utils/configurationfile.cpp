#include "configurationfile.h"

ConfigurationFile::ConfigurationFile(const QString& filePath){
  settings = new QSettings(filePath,QSettings::IniFormat);
}

ConfigurationFile::~ConfigurationFile(){
  delete(settings);
}

QVariantHash ConfigurationFile::loadGroupKeyValue(QString& group){
  settings->beginGroup(group);
  foreach (QString key, settings->childKeys()) {
    readedConfiguration[key] = settings->value(key);
  }
  settings->endGroup();
  return readedConfiguration;
}

QVariantList ConfigurationFile::getValues(QString& group){
  QVariantHash keysAndValues;
  keysAndValues = loadGroupKeyValue(group);
  return keysAndValues.values();
}


QVariantList ConfigurationFile::getChildKeys(QString& group){
  settings->beginGroup("fridge/linux");
  QStringList childKeys = settings->childKeys();
  qCopy(childKeys.begin(), childKeys.end(), m_keys.begin()); // works because QVariant has
  settings->endGroup();
  return m_keys;
}

QVariantList ConfigurationFile::getSubGroups(QString& group){
  settings->beginGroup(group);
  QStringList childKeys = settings->childKeys();
  qCopy(childKeys.begin(), childKeys.end(), m_subGroups.begin()); // works because QVariant has
  settings->endGroup();
  return m_subGroups;
}
