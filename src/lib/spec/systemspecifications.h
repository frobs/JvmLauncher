#ifndef SYSTEMSPECIFICATIONS_H
#define SYSTEMSPECIFICATIONS_H

#include <QMessageBox>
#include <QString>
#include <QVariantHash>
#include <QVariant>
#include "src/lib/utils/qvariantlistutils.h"

class SystemSpecifications{
  public:
   SystemSpecifications();
    SystemSpecifications(QVariantHash &minimunSystemRequeriments);
    bool isValid();

  protected:
    QVariantHash m_minimunSystemRequeriments;
    QVariantHash runtimeSystemSpecifications;
    void validate();

  private:
    QString errorMessage;
    QMessageBox msgBox;
    bool validated;
    QString m_key;
    void evaluateIntValues(QString& fieldName, int minimunValidValue,int currentValue);
    void evaluateQVariantListValues(QString& fieldName, QVariant minimunValidValue,QVariant currentValue);
};

#endif // SYSTEMSPECIFICATIONS_H
