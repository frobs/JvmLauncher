#ifndef UNIX_H
#define UNIX_H

#include <QString>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

class Unix{
public:
  Unix();
  ~Unix();
  QString getOsArchitecture();
  QString getOsVersionNumber();
  QString getFullOsVersion();
private:
  struct utsname unameData;
};

#endif // UNIX_H
