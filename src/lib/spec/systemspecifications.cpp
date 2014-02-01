#include "systemspecifications.h"


SystemSpecifications::SystemSpecifications(){
 validated = false;
}

SystemSpecifications::SystemSpecifications(QVariantHash& minimunSystemRequeriments){
  validated = false;
  m_minimunSystemRequeriments=minimunSystemRequeriments;
  //We format strings to QVariantList for not depend of processor and her conversion to doubles and floats
  QVariantListUtils::formatQStringsWithDecimalsToIntegers(m_minimunSystemRequeriments);
}

bool SystemSpecifications::isValid(){
  return validated;
}

void SystemSpecifications::validate(){
  foreach(QString key, runtimeSystemSpecifications.keys()){
    //We separate simple integers and QVariantLists from QHash
    if(runtimeSystemSpecifications[key].canConvert(QMetaType::Int)){
      evaluateIntValues(key,m_minimunSystemRequeriments[key].toInt(),runtimeSystemSpecifications[key].toInt());
    }else{
      evaluateQVariantListValues(key,m_minimunSystemRequeriments[key],runtimeSystemSpecifications[key]);
    }
  }
  if(!errorMessage.isEmpty()){
    msgBox.setText(errorMessage);
    int ret = msgBox.exec();
    if(ret==QMessageBox::Ok){
      exit(EXIT_FAILURE);
    }
  }
  validated=true;
}

void SystemSpecifications::evaluateIntValues(QString& fieldName, int minimunValidValue,int currentValue){
  if(currentValue < minimunValidValue){
    errorMessage.append("The expected value of "+fieldName.replace("_"," ")+" is lower than "+QString::number(minimunValidValue)+" this must be higher\n");
  }
}

void SystemSpecifications::evaluateQVariantListValues(QString& fieldName, QVariant minimunValidValue, QVariant currentValue){
  for(int i = 0;i < minimunValidValue.toList().size();i++){
    if(minimunValidValue.toList().at(i).toInt() > currentValue.toList().at(i).toInt()){
      errorMessage.append("The expected value of "+fieldName.replace("_"," ")+" is lower than "+minimunValidValue.toStringList().join(".")+" this must be higher\n");
      break;
    }
  }
}

