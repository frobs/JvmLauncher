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
  m_formattedParameters.append(formatClassPath(m_parameterHash["class_path"]));
  m_formattedParameters.append(formatSse(m_parameterHash["sse"]));
  m_formattedParameters.append(formatParallelThreads(m_parameterHash["parallel_gc_threads"]));
  m_formattedParameters.append(formatXss(m_parameterHash["xss"]));
}

QString JvmParameters::formatXss(QString& parameterToRefactor){
  return parameterToRefactor.replace("<value>",QString::number(operativeSystem->getCoresNum().toInt()*2046));
}

QString JvmParameters::formatParallelThreads(QString &parameterToRefactor){
  return parameterToRefactor.replace("<value>",operativeSystem->getCoresNum());
}

QString JvmParameters::formatSse(QString& parameterToRefactor){
  return parameterToRefactor.replace("<value>",operativeSystem->getSseVersion());
}

void JvmParameters::copyStaticSettingsOSArchitectureDependent(){
  absoluteGroupPath = m_platform+"/static_32";
  if(operativeSystem->getOsArchitecture()=="x86_64"){
    absoluteGroupPath = m_platform+"/static_64";
  }
  copyStaticSettings(absoluteGroupPath);
}

void JvmParameters::copyStaticSettings(QString& groupAbsolutePath){
  m_formattedParameters += configFileReader->getValues(groupAbsolutePath);
}

QString JvmParameters::formatClassPath(QString& classpathFileConfigurationValue){
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
  return classPathFormatted;
}

QStringList JvmParameters::getJvmParameters(){
  return m_formattedParameters;
}
