#ifndef QVARIANTLISTFORMATTER_H
#define QVARIANTLISTFORMATTER_H

#include <QVariantHash>

class QVariantListFormatter{
public:
  QVariantListFormatter();
  void formatQStringsWithDecimalsToIntegers(QVariantHash& hashToBeFormatted);
};

#endif // QVARIANTLISTFORMATTER_H
