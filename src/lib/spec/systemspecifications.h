#ifndef SYSTEMSPECIFICATIONS_H
#define SYSTEMSPECIFICATIONS_H

#include <QString>

class SystemSpecifications{
  public:
    explicit SystemSpecifications(QString ConfigurationFilePath);
     ~SystemSpecifications();
    static SystemSpecifications* Create(QString type);
    bool isValid();
    QString configurationFile;

  private:
    void loadConfiguration();
    void getRuntimeSpecifications();
    void formatRuntimeSpecifications();
    void validate();
};

#endif // SYSTEMSPECIFICATIONS_H
