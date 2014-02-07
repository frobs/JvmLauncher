JvmLauncher
===========

A c++/qt multiplatform launcher for jvm applications

##Requisites:
> ###Linux:

> > Compile:

> > > Qt 4.8 or 5.2.

> > > Gcc 4.x(tested with 4.7 and 4.8) standard used c++ 99

> > > OpenJdk/Oracle Jdk 1.7

> > Execute:

> > > JRE 1.x

> ###MacOs:

> > Compile:

> > > Qt 5.2

> > > CLANG(Version installed with Qt)

> > Execute:

> > > JRE 1.x

##Configuration:
> ###Linux:
> > Compile:

> > > Debian/Ubuntu and Qt-5.2:

> > > > `apt-get install libgl-dev`

> > > JAVA_HOME environment variable with the path to JDK

> > Execute:

> > > JRE_HOME environment variable with the path to JRE

> > > Shared libraries of JRE accesible to the system, i.e. using LD_LIBRARY__PATH
 
> ###MacOs:

> > Compile:

> > > JAVA_HOME environment variable with the path to JDK

> > > Shared libraries of JRE accesible to the system, i.e. using LD_LIBRARY__PATH

> > > If you see this error when import project:

> > >Project ERROR: Xcode not set up properly. You may need to confirm the license agreement by running /usr/bin/xcodebuild.

> > > > Execute `/usr/bin/xcodebuild` and agree the license

> > > > Execute on the project directory: `qmake -spec macx-xcode JvmLauncher.pro`

## Compile the project:
> ###Linux:
> > `qmake JvmLauncher.pro`

> >` make`

> > Remember copy your application to the launcher directory with the same path that you have specified on your jvm-parameters.ini/classpath

## Executing the compiled executable:

> ###Linux:

> > `./JvmLauncher`

##Compiling and executing the tests:
> ###Linux:
> > `qmake testUnit.pro`

> >` make`

> > `./testUnitJvmLauncher`

