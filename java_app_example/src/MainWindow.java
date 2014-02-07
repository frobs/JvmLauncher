public class MainWindow {
    public static void main(String[] args) {
        //We need initialize swing gui of this way for 
        //can call it from jni.
        //if you use the default code of netbeans or eclipse with new Runnable
        //Your application could't be launched on macOs on other platforms work.
        CreateAndShowGUI t1=new CreateAndShowGUI();
        t1.start();
        try {
            t1.join();//is more important synchronize the main thread with the gui thread 
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
