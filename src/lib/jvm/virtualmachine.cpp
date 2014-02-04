#include "virtualmachine.h"

VirtualMachine::VirtualMachine(QString& currentOs,QVariant& minimunJavaVersion){
  jvmParameters = new JvmParameters(currentOs);
  jvmArgs = jvmParameters->get();
  m_minimunJREVersion = minimunJavaVersion;
  splash = SplashScreen::getInstance();
}

void VirtualMachine::start(){
  create_jvm();
  evaluateJavaVersion();
  invoke("MainWindow","main");
}

void VirtualMachine::create_jvm(){
  static JavaVMOption *options=NULL;
  int noOfOptions = 0;
  noOfOptions=jvmArgs.size();
  options = (JavaVMOption *)malloc(noOfOptions * sizeof(JavaVMOption));
  JNI_GetDefaultJavaVMInitArgs(&vm_args);

  //jvm options
  for (int i=0;i<jvmArgs.size();i++){
      options[i].optionString = strdup((char *)jvmArgs.at(i).toStdString().c_str());
  }
  //jvm args
  vm_args.version = JNI_VERSION_1_6;
  vm_args.nOptions = noOfOptions;
  vm_args.options = options;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  jint res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
  if (res < 0) {//jvm don't created
      qDebug()<<"Can't create Java VM\n";
      exit(1);
  }else{
    free(options);
  }
}

void VirtualMachine::invoke(const char* javaClass,const char* method) {
  jclass cls;
  jmethodID javaMethod;
  jobjectArray applicationArgs;
  applicationArgs = env->NewObjectArray(0, env->FindClass("java/lang/String"), NULL);
  //class and main method
  cls = env->FindClass(javaClass);
  if (cls == 0) qDebug()<<"Sorry, I can't find the class"; //In case that class not exist
  //call to main method
  javaMethod = env->GetStaticMethodID(cls, method, "([Ljava/lang/String;)V");
  SplashScreen::setSplashMessage(QString("Launching java application"));
  env->CallStaticVoidMethod(cls, javaMethod, applicationArgs); //Call to the method
  splash->close();
}

QString VirtualMachine::getJvmVersion(){
  QString javaVersion;
  jclass systemClass = env->FindClass("java/lang/System");
  jmethodID getPropertyMethod = env->GetStaticMethodID(systemClass, "getProperty",
                                                      "(Ljava/lang/String;)Ljava/lang/String;");
  jstring propertyName = env->NewStringUTF("java.version");
  jstring value = (jstring) env->CallStaticObjectMethod(systemClass,
                                                        getPropertyMethod,
                                                        propertyName);
  //parsing the version
  javaVersion = QString(env->GetStringUTFChars(value, NULL));
  //textArray.at[0]=version of java
  //textArray.at[1]=version of java update
  return javaVersion.split("_").at(0);
}

//By default the jvm is destroyed when the
//java application is exitted, but it can be needed in the future
void VirtualMachine::destroy_jvm(){
  jvm->DestroyJavaVM();
}

void VirtualMachine::evaluateJavaVersion(){
  QStringList minimunJREVersion = m_minimunJREVersion.toString().split(".");
  QString currentJREVersion = getJvmVersion();
  QStringList currentJREVersionList = currentJREVersion.split(".");
  for (int i = 0; i < minimunJREVersion.size();i++){
    if(minimunJREVersion.at(i).toInt() > currentJREVersionList.at(i).toInt()){
      QMessageBox errorDialog;
      errorDialog.setText("Error, java version running "+currentJREVersion+
                        ", minimun java version required "+m_minimunJREVersion.toString());
      errorDialog.setMinimumWidth(400);
      errorDialog.setMinimumHeight(300);
      errorDialog.setWindowTitle("Launcher");
      qDebug()<<"Java version not supported";
      errorDialog.exec();
      exit(1);
    }
  }
}
