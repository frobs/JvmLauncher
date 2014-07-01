JvmLauncher
===========

The idea behind this project is write a multiplatform application in C++/QT that launch a Java application (works for console and swing).
Works in GNU/Linux, Windows and MACX.

See all the information about configuration etc. on the [Wiki](https://github.com/frobs/JvmLauncher/wiki)

Closed issues:
* We can show a splash screen while the java libraries and application is been launched and is automatically closed.
* Check the system and validate the minimun requeriments needed by our java app, and show a alert pop up if this isn't complete.
* We can define static parameters and get low level machine information to parametrize the jvm where out java app will be launched.

Future issues:
* Big refactor and clean of code
* Add the feature of check and download the java app updates when the launcher is executed, update libraries versions, the app.jar...
* Add the option of launch a app without GUI, it is, without SplashScreen or popup alert. For console Java applications that will run in environment without x.
