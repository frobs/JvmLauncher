#ifndef UNIX_H
#define UNIX_H

#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include "src/lib/operativesystem/multios.h"

class Unix : public MultiOs{
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
