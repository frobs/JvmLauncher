#ifndef SYSTEMSPECIFICATIONS_H
#define SYSTEMSPECIFICATIONS_H

#include <QMessageBox>
#include <QString>
#include <QHash>

class SystemSpecifications{
  public:
   SystemSpecifications();
    SystemSpecifications(QHash<QString,QString> &minimunSystemRequeriments);
    bool isValid();

  protected:
    QHash<QString,QString> m_minimunSystemRequeriments;
    void validate(QHash<QString,QString>& runtimeSystemSpecifications);

  private:
    QString errorMessage;
    QMessageBox msgBox;
    bool validated;
};

#endif // SYSTEMSPECIFICATIONS_H
