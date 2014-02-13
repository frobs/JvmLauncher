JvmLauncher
===========

A c++/qt multiplatform launcher for jvm applications

#Linux:
> ##Compilation:

> > ###Requisites:

> > > Qt 4.8 or 5.2.

> > > Gcc 4.x(tested with 4.7 and 4.8) standard used c++ 99

> > > OpenJdk/Oracle Jdk 1.7

> > ###Configuration:

> > > Debian/Ubuntu and Qt-5.2:

> > > `apt-get install libgl-dev`

> > > `JAVA_HOME` environment variable with the path to JDK

> > > `QT_LIBRARY_PATH` environment variable with the path to qt dynamic libraries that must be copy with launcher, libQtCore.os and libQtGui.os

> > ###Commands:

> > > Tests:

> > > > `qmake testUnit.pro`

> > > > `make`

> > > Launcher:

> > > > `qmake JvmLauncher.pro`

> > > > `make` or `make install` (if you want a tar.gz with shared libraries inside)

> > > > Remember copy your application to the launcher directory with the same path that you have specified on your jvm-parameters.ini/classpath

> ##Execute:

> > ###Requisites:

> > > JRE 1.x

> > ###Configuration:

> > > `JRE_HOME` environment variable with the path to JRE

> > > Shared libraries of JRE accesible to the system, i.e. using `LD_LIBRARY_PATH`

> > ###Commands:

> > > Tests:

> > > > `./testUnitJvmLauncher`

> > > Launcher:

> > > > `./yourLauncherName`

#Mac:
> ##Compilation:

> > ###Requisites:

> > > Qt 4.8 or 5.2.

> > > CLANG(Version installed with Qt)

> > > Oracle Jdk 1.7

> > ###Configuration:
> > > `JAVA_HOME` environment variable with the path to JDK

> > > If you see this error when import project:

> > > Project ERROR: Xcode not set up properly. You may need to confirm the license agreement by running /usr/bin/xcodebuild.

> > > > Execute `/usr/bin/xcodebuild` and agree the license

> > > > Execute on the project directory: `qmake -spec macx-xcode JvmLauncher.pro`

> ##Execute:

> > ###Requisites:

> > > JRE 1.x

> > ###Configuration:

> > > Shared libraries of JRE accesible to the system, i.e. using `DYLD_LIBRARY_PATH` 
