#include "qvariantlistutils.h"

QVariantListUtils::QVariantListUtils(){
}

//This method convert QString to ints and real QStrings to int QVariantLists
void QVariantListUtils::formatQStringsWithDecimalsToIntegers(QVariantHash& hashToBeFormatted){
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

QStringList QVariantListUtils::toQStringList(QVariantList variantList){
  QStringList result;
  QListIterator<QVariant> i(variantList);
  while (i.hasNext()) {
    result << i.next().toString();
  }
  return result;
}

QVariantList QVariantListUtils::toQVariantList(QStringList stringList){
  QVariantList result;
  qCopy(stringList.begin(), stringList.end(), result.begin());
  return result;
}
