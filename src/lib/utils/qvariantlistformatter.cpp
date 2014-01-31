#include "qvariantlistformatter.h"
#include <QUrl>

QVariantListFormatter::QVariantListFormatter(){
}

//This method convert QString to ints and real QStrings to int QVariantLists
void QVariantListFormatter::formatQStringsWithDecimalsToIntegers(QVariantHash& hashToBeFormatted){
  QVariantList temporalVariantList;
  QStringList temporalStringList;
  foreach(QString key,hashToBeFormatted.keys()){
    if(hashToBeFormatted[key].toString().contains(".")){
      temporalVariantList.clear();
      temporalStringList = hashToBeFormatted[key].toString().split(".") ;
      for(int i = 0;i<temporalStringList.size();i++){
        temporalVariantList.append(temporalStringList.at(i).toInt());
      }
      hashToBeFormatted[key] = temporalVariantList;
    }else{
        hashToBeFormatted[key] = hashToBeFormatted[key].toInt();
      }
  }
}
