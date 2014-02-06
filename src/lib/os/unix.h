#ifndef UNIX_H
#define UNIX_H

#include <QVariant>
#include <QVariantList>
#include <sys/utsname.h>
#include <sys/types.h>

class Unix{
public:
  Unix();
  ~Unix();
  QVariant getOsArchitecture();
  QVariant getOsVersionNumber();
  QVariant getFullOsVersion();
private:
  struct utsname unameData;
};

#endif // UNIX_H
