#ifndef VirtualMachine_H
#define VirtualMachine_H

#include "jni.h"
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

class VirtualMachine{
  public:
    VirtualMachine();
    void create_jvm(QStringList &jvmArgs);
    void destroy_jvm();
  private:
    void invoke_class();
    QString getJvmVersion();
    JavaVM *jvm;
    JNIEnv *env;
    JavaVMInitArgs vm_args;
  };

#endif // VirtualMachine_H
