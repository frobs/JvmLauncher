#include "jvmparameters.h"

JvmParameters::JvmParameters(QString& platform){
  m_platform = platform;
  configFileReader = new ConfigurationFile(PATH_TO_JVM_PARAMETERS_FILE);
  generateJvmParameters();
}

JvmParameters::~JvmParameters(){
  delete(configFileReader);
}

void JvmParameters::generateJvmParameters(){
  absoluteGroupPath = m_platform+"/static";
  copyStaticSettings(absoluteGroupPath);
  copyStaticSettingsOSArchitectureDependent();
  generateDynamicParameters();
}

void JvmParameters::generateDynamicParameters(){
  absoluteGroupPath = m_platform+"/dynamic";
  m_parameterHash = configFileReader->loadGroupKeyValue(absoluteGroupPath);
  m_formattedParameters.append(formatClassPath(m_parameterHash["class_path"].toString()));
  m_formattedParameters.append(formatSse(m_parameterHash["sse"].toString()));
  m_formattedParameters.append(formatParallelThreads(m_parameterHash["parallel_gc_threads"].toString()));
  m_formattedParameters.append(formatXss(m_parameterHash["xss"].toString()));
}

QString JvmParameters::formatXss(QString parameterToRefactor){
  return parameterToRefactor.replace("<value>",QString::number(operativeSystem->getCoresNum().toInt()*2046));
}

QString JvmParameters::formatParallelThreads(QString parameterToRefactor){
  return parameterToRefactor.replace("<value>",operativeSystem->getCoresNum().toString());
}

QString JvmParameters::formatSse(QString parameterToRefactor){
  return parameterToRefactor.replace("<value>",operativeSystem->getSseVersion().toString());
}

void JvmParameters::copyStaticSettingsOSArchitectureDependent(){
  absoluteGroupPath = m_platform+"/static_32";
  if(operativeSystem->getOsArchitecture()=="x86_64"){
    absoluteGroupPath = m_platform+"/static_64";
  }
  copyStaticSettings(absoluteGroupPath);
}

void JvmParameters::copyStaticSettings(QString& groupAbsolutePath){
  m_formattedParameters += QVariantListUtils::toQStringList(configFileReader->getValues(groupAbsolutePath));
}

QString JvmParameters::formatClassPath(QString classpathFileConfigurationValue){
  QDir tempPath;
  QString classPathFormatted = "-Djava.class.path=";
  QStringList fileExtensionFilter("*.jar"); //We specify the type of files that we will get
  foreach(QString relativePath,classpathFileConfigurationValue.split(";")){
    //We change the pat to new path, this new path is composed by the current absolute
    //application path and relative paths loaded from configuration file
    tempPath.setPath(tempPath.toNativeSeparators(CURRENT_APPLICATION_PATH+"/"+relativePath));
    classPathFormatted.append(relativePath+
                              tempPath.entryList(fileExtensionFilter).join(CLASSPATH_SEPARATOR+relativePath)+
                              CLASSPATH_SEPARATOR);
  }
  //Remove the last separator character of chasspath
  classPathFormatted.chop(1);
  return classPathFormatted;
}

QStringList JvmParameters::get(){
  return m_formattedParameters;
}
