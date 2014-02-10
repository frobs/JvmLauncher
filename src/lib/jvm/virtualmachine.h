#ifndef VirtualMachine_H
#define VirtualMachine_H

#include "jni.h"
#include <QString>
#include <QStringList>
#include <QVariantList>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QThread>
#include "src/graphics/splashscreen.h"
#include "src/lib/utils/qvariantlistutils.h"
#include "src/lib/jvm/jvmparameters.h"

//We need that jni launcher run in a QThread separated from main
//thread, if we use the main thread for launch  the jvm,
//a error that doesn't show any trace occur and the java app
//can't be launched
class VirtualMachine: public QThread{
  public:
    VirtualMachine(QString& currentOs,QVariant& minimunJavaVersion);
  private:
    void run();
    void invoke(const char* javaClass,const char* javaMethod);
    void create_jvm();
    void evaluateJavaVersion();
    QString getJvmVersion();
    QSplashScreen* splash;
    QStringList jvmArgs;
    QVariant m_minimunJREVersion;
    JvmParameters* jvmParameters;
    JavaVM *jvm;
    JNIEnv *env;
    JavaVMInitArgs vm_args;
  };

#endif // VirtualMachine_H
