#ifndef VirtualMachine_H
#define VirtualMachine_H

#include "jni.h"
#include <QString>
#include <QStringList>
#include <QVariantList>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "src/lib/utils/qvariantlistutils.h"
#include "src/lib/jvm/jvmparameters.h"

class VirtualMachine{
  public:
    VirtualMachine(QString& currentOs,QVariant& minimunJavaVersion);
    void start();
  private:
    void invoke(const char* javaClass,const char* javaMethod);
    void create_jvm();
    void evaluateJavaVersion();
    void destroy_jvm();
    QString getJvmVersion();
    QStringList jvmArgs;
    QVariant m_minimunJREVersion;
    JvmParameters* jvmParameters;
    JavaVM *jvm;
    JNIEnv *env;
    JavaVMInitArgs vm_args;
  };

#endif // VirtualMachine_H
