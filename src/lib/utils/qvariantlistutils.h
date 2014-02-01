#ifndef QVARIANTLISTUTILS_H
#define QVARIANTLISTUTILS_H

#include <QVariantHash>
#include <QVariantList>
#include <QStringList>

class QVariantListUtils{
public:
  QVariantListUtils();
  static void formatQStringsWithDecimalsToIntegers(QVariantHash& hashToBeFormatted);
  static QStringList toQStringList(QVariantList variantList);
  static QVariantList toQVariantList(QStringList stringList);
};

#endif // QVARIANTLISTUTILS_H
