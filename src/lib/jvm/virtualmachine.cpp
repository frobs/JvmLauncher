#include "virtualmachine.h"

VirtualMachine::VirtualMachine(){}

void VirtualMachine::create_jvm(QStringList &jvmArgs){
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
    invoke_class();
  }
}

void VirtualMachine::invoke_class() {
  jclass cls;
  jmethodID javaMethod;
  jobjectArray applicationArgs;
  applicationArgs = env->NewObjectArray(0, env->FindClass("java/lang/String"), NULL);
  //class and main method
  cls = env->FindClass("MainWindow");
  if (cls == 0) qDebug()<<"Sorry, I can't find the class"; //In case that class not exist
  //call to main method
  javaMethod = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
  env->CallStaticVoidMethod(cls, javaMethod, applicationArgs); //Call to the method
}

//By default the jvm is autodestroyed by default when the
//java application is exitted, but it can be needed in the future
void VirtualMachine::destroy_jvm(){
  jvm->DestroyJavaVM();
}
