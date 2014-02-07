import java.awt.Dimension;
import java.lang.reflect.InvocationTargetException;
 
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;
 
 
public class CreateAndShowGUI extends Thread{
	Runnable HelloWorldFrame = new Runnable() {
        public void run() {
        	//Make sure we have nice window decorations.
            JFrame.setDefaultLookAndFeelDecorated(true);
 
            //Create and set up the window.
            JFrame frame = new JFrame("HelloWorldSwing");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            Dimension dimensions = new Dimension(800, 600);
            frame.setPreferredSize(dimensions);
            //Add the ubiquitous "Hello World" label.
            JLabel label = new JLabel("Hello World");
            frame.getContentPane().add(label);
 
            //Display the window.
            frame.pack();
            
            frame.setVisible(true);	
        }
    };
    
	public void run(){
    	
        try {
                        // Being Swing good citizens
			SwingUtilities.invokeAndWait(HelloWorldFrame);
		} catch (InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
 
}
