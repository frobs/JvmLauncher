#ifndef UNIX_H
#define UNIX_H

#include <QVariant>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

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
