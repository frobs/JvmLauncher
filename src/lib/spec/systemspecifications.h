#ifndef SYSTEMSPECIFICATIONS_H
#define SYSTEMSPECIFICATIONS_H

#include <QMessageBox>
#include <QString>
#include <QMap>

class SystemSpecifications{
  public:
   SystemSpecifications();
    SystemSpecifications(QMap<QString,QString> &minimunSystemRequeriments);
    bool isValid();

  protected:
    QMap<QString,QString> m_minimunSystemRequeriments;
    void validate(QMap<QString,QString>& runtimeSystemSpecifications);

  private:
    QString errorMessage;
    QMessageBox msgBox;
    bool validated;
};

#endif // SYSTEMSPECIFICATIONS_H
