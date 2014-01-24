#include "systemspecifications.h"


SystemSpecifications::SystemSpecifications(){
 validated = false;
}

SystemSpecifications::SystemSpecifications(QHash<QString,QString>& minimunSystemRequeriments){
  validated = false;
  m_minimunSystemRequeriments=minimunSystemRequeriments;
}

bool SystemSpecifications::isValid(){
  return validated;
}

void SystemSpecifications::validate(QHash<QString,QString>& runtimeSystemSpecifications){
  foreach(QString key,runtimeSystemSpecifications.keys()){
    if(runtimeSystemSpecifications[key] < m_minimunSystemRequeriments[key]){
      errorMessage.append("The expected value of "+key+" is lower than "+m_minimunSystemRequeriments[key]+" this must be higher\n");
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
