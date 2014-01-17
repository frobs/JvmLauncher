#include "configurationfile.h"

ConfigurationFile::ConfigurationFile(const QString& filePath,QString& groupToRead){
  configurationFilePath=filePath;
  group = groupToRead;
  readFile();

}

void ConfigurationFile::readFile(){
  QSettings settings(configurationFilePath,
                     QSettings::IniFormat);
  settings.beginGroup(group);
  foreach (QString key, settings.childKeys()) {
     readedConfiguration[key]=settings.value(key).toString();
    }
  settings.endGroup();
}

QMap<QString,QString> ConfigurationFile::getReadedConfiguration(){
  return readedConfiguration;
}
