import java.awt.*;

public class Singleton implements Displayer {
   private static Singleton instance;
   private int data;  // état du singleton

   private Singleton() { } // constructeur privé

   public static Singleton getInstance() {
	  if (instance == null) instance = new Singleton();  // instanciation retardée
	  return instance;
   }

   public int getData() {
	  return data;
   }

   public void setData(int data) {
	  this.data = data;
   }

   @Override
   public int getWidth() {
	  return 0;
   }

   @Override
   public int getHeight() {
	  return 0;
   }

   @Override
   public Graphics2D getGraphics() {
	  return null;
   }

   @Override
   public void repaint() {

   }

   @Override
   public void setTitle(String s) {

   }
}
